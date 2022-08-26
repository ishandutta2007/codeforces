import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Objects;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            String s = in.readString();
            LongInteger n = new LongInteger(s);
            if (s.equals("1")) {
                out.printLine(1);
                return;
            }
            double log3 = (Math.log10(s.charAt(0) - '0') + (s.length() - 1)) / Math.log10(3);
            int exponent = (int) Math.round(Math.floor(log3) - 2);
            exponent = Math.max(exponent, 0);
            LongInteger power = new LongInteger("3").power(exponent);
            while (power.multiply(9).compareTo(n) <= 0) {
                power.multiplyBy(3);
                exponent++;
            }
            if (power.multiply(2).compareTo(n) >= 0) {
                out.printLine(3 * exponent + 2);
                return;
            }
            if (power.multiply(3).compareTo(n) >= 0) {
                out.printLine(3 * exponent + 3);
                return;
            }
            if (power.multiply(4).compareTo(n) >= 0) {
                out.printLine(3 * exponent + 4);
                return;
            }
            if (power.multiply(6).compareTo(n) >= 0) {
                out.printLine(3 * exponent + 5);
                return;
            }
            out.printLine(3 * exponent + 6);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class LongInteger implements Cloneable, Comparable<LongInteger> {
        private static final int MOD = 1000;
        private static final int MULTIPLY_THRESHOLD = 50;
        public static final LongInteger ZERO = new LongInteger("0");
        public static final LongInteger ONE = new LongInteger("1");
        private int length;
        private int[] digits;
        private int sign;

        private LongInteger(int length, int[] digits, int sign) {
            this.length = length;
            this.digits = digits;
            this.sign = sign;
        }

        public LongInteger(String s) {
            if (s.isEmpty()) {
                throw new NumberFormatException();
            }
            int from = 0;
            int to = s.length();
            if (s.charAt(0) == '-') {
                sign = -1;
                from = 1;
            } else {
                sign = 1;
                if (s.charAt(0) == '+') {
                    from = 1;
                }
            }
            if (from == to) {
                throw new NumberFormatException();
            }
            length = (to - from + 2) / 3;
            digits = new int[length];
            for (int i = 0; i < length; i++) {
                int start = Math.max(to - 3, from);
                for (int j = start; j < to; j++) {
                    digits[i] *= 10;
                    char c = s.charAt(j);
                    if (!Character.isDigit(c)) {
                        throw new NumberFormatException();
                    }
                    digits[i] += c - '0';
                }
                to = start;
            }
            if (length == 1 && digits[0] == 0) {
                sign = 0;
            }
        }

        public LongInteger multiply(long number) {
            LongInteger result = clone();
            result.multiplyBy(number);
            return result;
        }

        public void multiplyBy(long number) {
            long add = 0;
            for (int i = 0; i < length; i++) {
                add += number * digits[i];
                digits[i] = (int) (add % MOD);
                add /= MOD;
            }
            while (add != 0) {
                ensureLength(length + 1);
                digits[length++] = (int) (add % MOD);
                add /= MOD;
            }
        }

        public LongInteger multiply(LongInteger number) {
            if (Math.min(length, number.length) <= MULTIPLY_THRESHOLD) {
                return straightforwardMultiply(this, number);
            } else {
                return fftMultiply(this, number);
            }
        }

        private static LongInteger fftMultiply(LongInteger a, LongInteger b) {
            long[] result = FastFourierTransform.multiply(a.digits, b.digits, a.length, b.length);
            long add = 0;
            LongInteger product = new LongInteger(0, new int[result.length], a.sign * b.sign);
            for (int i = 0; i < result.length; i++) {
                add += result[i];
                if (add != 0) {
                    product.length = i + 1;
                }
                product.digits[i] = (int) (add % MOD);
                add /= MOD;
            }
            while (add > 0) {
                product.ensureLength(product.length + 1);
                product.digits[product.length++] = (int) (add % MOD);
                add /= MOD;
            }
            return product;
        }

        private static LongInteger straightforwardMultiply(LongInteger a, LongInteger b) {
            if (a.sign == 0 || b.sign == 0) {
                return ZERO;
            }
            LongInteger product =
                    new LongInteger(a.length + b.length - 1, new int[a.length + b.length], a.sign * b.sign);
            long add = 0;
            for (int i = 0; i < a.length + b.length - 1; i++) {
                for (int j = Math.max(0, i - b.length + 1); j < a.length && j <= i; j++) {
                    add += a.digits[j] * b.digits[i - j];
                }
                product.digits[i] = (int) (add % MOD);
                add /= MOD;
            }
            while (add > 0) {
                product.ensureLength(product.length + 1);
                product.digits[product.length++] = (int) (add % MOD);
                add /= MOD;
            }
            return product;
        }

        private void ensureLength(int length) {
            if (digits.length < length) {
                digits = Arrays.copyOf(digits, Math.max(2 * digits.length, length));
            }
        }

        public static int absCompare(LongInteger a, LongInteger b) {
            if (a.length != b.length) {
                return Integer.compare(a.length, b.length);
            }
            for (int i = a.length - 1; i >= 0; i--) {
                if (a.digits[i] != b.digits[i]) {
                    return Integer.compare(a.digits[i], b.digits[i]);
                }
            }
            return 0;
        }

        public static int compare(LongInteger a, LongInteger b) {
            if (a.sign != b.sign) {
                return Integer.compare(a.sign, b.sign);
            }
            return absCompare(a, b);
        }

        @SuppressWarnings("MethodDoesntCallSuperMethod")

        public LongInteger clone() {
            return new LongInteger(length, digits.clone(), sign);
        }


        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            LongInteger that = (LongInteger) o;
            return length == that.length &&
                    sign == that.sign &&
                    equals(digits, that.digits, length);
        }

        private static boolean equals(int[] a, int[] b, int length) {
            for (int i = 0; i < length; i++) {
                if (a[i] != b[i]) {
                    return false;
                }
            }
            return true;
        }


        public int hashCode() {
            int result = Objects.hash(length, sign);
            result = 31 * result + hashCode(digits, length);
            return result;
        }

        private static int hashCode(int[] digits, int length) {
            int result = 1;
            for (int i = 0; i < length; i++) {
                result = 31 * result + digits[i];
            }
            return result;
        }


        public String toString() {
            StringBuilder result = new StringBuilder();
            if (sign < 0) {
                result.append('-');
            }
            result.append(digits[length - 1]);
            for (int i = length - 2; i >= 0; i--) {
                int current = digits[i];
//            if (current < 1000) {
//                result.append('0');
                if (current < 100) {
                    result.append('0');
                    if (current < 10) {
                        result.append('0');
                    }
//                }
                }
                result.append(current);
            }
            return result.toString();
        }

        public LongInteger power(int exponent) {
            if (exponent == 0) {
                return ONE;
            }
            if ((exponent & 1) == 0) {
                return power(exponent >> 1).square();
            }
            return power(exponent - 1).multiply(this);
        }

        public LongInteger square() {
            return multiply(this);
        }


        public int compareTo(LongInteger o) {
            return compare(this, o);
        }

    }

    static class FastFourierTransform {
        public static void fft(double[] a, double[] b, boolean invert) {
            int count = a.length;
            for (int i = 1, j = 0; i < count; i++) {
                int bit = count >> 1;
                for (; j >= bit; bit >>= 1) {
                    j -= bit;
                }
                j += bit;
                if (i < j) {
                    double temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
            }
            for (int len = 2; len <= count; len <<= 1) {
                int halfLen = len >> 1;
                double angle = 2 * Math.PI / len;
                if (invert) {
                    angle = -angle;
                }
                double wLenA = Math.cos(angle);
                double wLenB = Math.sin(angle);
                for (int i = 0; i < count; i += len) {
                    double wA = 1;
                    double wB = 0;
                    for (int j = 0; j < halfLen; j++) {
                        double uA = a[i + j];
                        double uB = b[i + j];
                        double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
                        double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
                        a[i + j] = uA + vA;
                        b[i + j] = uB + vB;
                        a[i + j + halfLen] = uA - vA;
                        b[i + j + halfLen] = uB - vB;
                        double nextWA = wA * wLenA - wB * wLenB;
                        wB = wA * wLenB + wB * wLenA;
                        wA = nextWA;
                    }
                }
            }
            if (invert) {
                for (int i = 0; i < count; i++) {
                    a[i] /= count;
                    b[i] /= count;
                }
            }
        }

        public static long[] multiply(int[] a, int[] b, int aLength, int bLength) {
            int resultSize = Integer.highestOneBit(Math.max(aLength, bLength) - 1) << 2;
            resultSize = Math.max(resultSize, 1);
            double[] aReal = new double[resultSize];
            double[] aImaginary = new double[resultSize];
            double[] bReal = new double[resultSize];
            double[] bImaginary = new double[resultSize];
            for (int i = 0; i < aLength; i++) {
                aReal[i] = a[i];
            }
            for (int i = 0; i < bLength; i++) {
                bReal[i] = b[i];
            }
            fft(aReal, aImaginary, false);
            if (a == b && aLength == bLength) {
                System.arraycopy(aReal, 0, bReal, 0, aReal.length);
                System.arraycopy(aImaginary, 0, bImaginary, 0, aImaginary.length);
            } else {
                fft(bReal, bImaginary, false);
            }
            for (int i = 0; i < resultSize; i++) {
                double real = aReal[i] * bReal[i] - aImaginary[i] * bImaginary[i];
                aImaginary[i] = aImaginary[i] * bReal[i] + bImaginary[i] * aReal[i];
                aReal[i] = real;
            }
            fft(aReal, aImaginary, true);
            long[] result = new long[resultSize];
            for (int i = 0; i < resultSize; i++) {
                result[i] = Math.round(aReal[i]);
            }
            return result;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }
}