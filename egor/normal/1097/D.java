import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
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
        DMakotoIDoska solver = new DMakotoIDoska();
        solver.solve(1, in, out);
        out.close();
    }

    static class DMakotoIDoska {
        Map<Integer, long[]> computed = new HashMap<>();
        long[] reverse = IntegerUtils.generateReverse(100, MiscUtils.MOD7);

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long n = in.readLong();
            int k = in.readInt();
            List<LongIntPair> factorization = IntegerUtils.factorize(n);
            long answer = 1;
            for (LongIntPair factor : factorization) {
                long[] p = getProbability(factor.second, k);
                long current = 1;
                long sum = 0;
                for (long aP : p) {
                    sum += current * aP % MiscUtils.MOD7;
                    current *= factor.first % MiscUtils.MOD7;
                    current %= MiscUtils.MOD7;
                }
                answer *= sum % MiscUtils.MOD7;
                answer %= MiscUtils.MOD7;
            }
            out.printLine(answer);
        }

        private long[] getProbability(int exponent, int k) {
            if (computed.containsKey(exponent)) {
                return computed.get(exponent);
            }
            long[] current = new long[exponent + 1];
            current[exponent] = 1;
            computed.put(exponent, current);
            for (int i = 0; i < k; i++) {
                long sum = 0;
                for (int j = exponent; j >= 0; j--) {
                    sum += current[j] * reverse[j + 1];
                    sum %= MiscUtils.MOD7;
                    current[j] = sum;
                }
            }
            return current;
        }

    }

    static class MiscUtils {
        public static final int MOD7 = (int) (1e9 + 7);

    }

    static class IntegerUtils {
        public static List<LongIntPair> factorize(long number) {
            List<LongIntPair> result = new ArrayList<>();
            for (long i = 2; i * i <= number; i++) {
                if (number % i == 0) {
                    int power = 0;
                    do {
                        power++;
                        number /= i;
                    } while (number % i == 0);
                    result.add(LongIntPair.makePair(i, power));
                }
            }
            if (number != 1) {
                result.add(LongIntPair.makePair(number, 1));
            }
            return result;
        }

        public static long[] generateReverse(int upTo, long module) {
            long[] result = new long[upTo];
            if (upTo > 1) {
                result[1] = 1;
            }
            for (int i = 2; i < upTo; i++) {
                result[i] = (module - module / i * result[((int) (module % i))] % module) % module;
            }
            return result;
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

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
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

    static class LongIntPair implements Comparable<LongIntPair> {
        public final long first;
        public final int second;

        public static LongIntPair makePair(long first, int second) {
            return new LongIntPair(first, second);
        }

        public LongIntPair(long first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            LongIntPair pair = (LongIntPair) o;

            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            int result = Long.hashCode(first);
            result = 31 * result + Integer.hashCode(second);
            return result;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(LongIntPair o) {
            int value = Long.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
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

        public void printLine(long i) {
            writer.println(i);
        }

    }
}