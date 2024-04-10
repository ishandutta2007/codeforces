import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        private static final long MOD = (long) (1e9 + 7);
        int[] divisor = IntegerUtils.generateDivisorTable(1000001);
        int[][] allDivisors = new int[divisor.length][];
        int[] ratio = new int[divisor.length];
        long[] fact = IntegerUtils.generateFactorial(200001, MOD);
        long[] revFact = IntegerUtils.generateReverseFactorials(200001, MOD);

        {
            allDivisors[1] = new int[]{1};
            ratio[1] = 1;
            for (int i = 2; i <= 1000000; i++) {
                int p = divisor[i];
                int c = i;
                int pow = 0;
                int mult = 1;
                do {
                    pow++;
                    c /= p;
                    mult *= p;
                } while (c % p == 0);
                mult /= p;
                mult *= p - 1;
                allDivisors[i] = Arrays.copyOf(allDivisors[c], allDivisors[c].length * (pow + 1));
                for (int j = allDivisors[c].length; j < allDivisors[i].length; j++) {
                    allDivisors[i][j] = allDivisors[i][j - allDivisors[c].length] * p;
                }
                ratio[i] = ratio[c] * mult;
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int k = in.readInt();
            int q = in.readInt();
            int[] a = IOUtils.readIntArray(in, n);
            int[] qty = new int[divisor.length];
            for (int i : a) {
                for (int j : allDivisors[i]) {
                    qty[j]++;
                }
            }
            long answer = 0;
            for (int i = 1; i < qty.length; i++) {
                if (qty[i] >= k) {
                    answer += c(qty[i], k) * ratio[i] % MOD;
                }
            }
            answer %= MOD;
            int[] c = IOUtils.readIntArray(in, q);
            for (int i : c) {
                for (int j : allDivisors[i]) {
                    if (qty[j] >= k - 1) {
                        answer += c(qty[j], k - 1) * ratio[j] % MOD;
                    }
                    qty[j]++;
                }
                answer %= MOD;
                out.printLine(answer);
            }
        }

        private long c(int n, int m) {
            return fact[n] * revFact[m] % MOD * revFact[n - m] % MOD;
        }

    }

    static class IOUtils {
        public static int[] readIntArray(InputReader in, int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readInt();
            }
            return array;
        }

    }

    static class IntegerUtils {
        public static int[] generateDivisorTable(int upTo) {
            int[] divisor = new int[upTo];
            for (int i = 1; i < upTo; i++) {
                divisor[i] = i;
            }
            for (int i = 2; i * i < upTo; i++) {
                if (divisor[i] == i) {
                    for (int j = i * i; j < upTo; j += i) {
                        divisor[j] = i;
                    }
                }
            }
            return divisor;
        }

        public static long[] generateFactorial(int count, long module) {
            long[] result = new long[count];
            if (module == -1) {
                if (count != 0) {
                    result[0] = 1;
                }
                for (int i = 1; i < count; i++) {
                    result[i] = result[i - 1] * i;
                }
            } else {
                if (count != 0) {
                    result[0] = 1 % module;
                }
                for (int i = 1; i < count; i++) {
                    result[i] = (result[i - 1] * i) % module;
                }
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

        public static long[] generateReverseFactorials(int upTo, long module) {
            long[] result = generateReverse(upTo, module);
            if (upTo > 0) {
                result[0] = 1;
            }
            for (int i = 1; i < upTo; i++) {
                result[i] = result[i] * result[i - 1] % module;
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

        public void printLine(long i) {
            writer.println(i);
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
}