import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] p = IOUtils.readIntArray(in, n);
            int[] divisor = IntegerUtils.generateDivisorTable(n + 1);
            int[] simple = new int[n + 1];
            int[] tps = new int[n + 1];
            int[] pr = new int[n + 1];
            simple[1] = 1;
            pr[1] = 1;
            int[] qty = new int[n + 1];
            qty[1]++;
            for (int i = 2; i <= n; i++) {
                int prev = i / divisor[i];
                if (prev % divisor[i] == 0) {
                    simple[i] = simple[prev];
                } else {
                    simple[i] = simple[prev] * divisor[i];
                }
                qty[simple[i]]++;
            }
            int[] type = new int[n + 1];
            type[1] = 1;
            int[] rem = new int[n + 1];
            rem[1]++;
            for (int i = 2; i <= n; i++) {
                if (divisor[i] == i) {
                    type[i] = n / i;
                    rem[type[i]]++;
                }
            }
            tps[1] = 1;
            for (int i = 2; i <= n; i++) {
                if ((long) i * i <= n || divisor[i] != i) {
                    continue;
                }
                for (int j = i; j <= n; j += i) {
                    simple[j] /= i;
                    tps[j] = type[i];
                    pr[j] = i;
                }
            }
            int[] direct = new int[n + 1];
            int[] reverse = new int[n + 1];
            for (int i = 0; i < n; i++) {
                if (p[i] == 0) {
                    continue;
                }
                if (simple[i + 1] != simple[p[i]] || tps[i + 1] != tps[p[i]]) {
                    out.printLine(0);
                    return;
                }
                if (pr[i + 1] == 0) {
                    qty[simple[i + 1]]--;
                } else {
                    qty[simple[i + 1] * pr[i + 1]]--;
                }
                if (pr[i + 1] != 0) {
                    if (direct[pr[i + 1]] == 0) {
                        direct[pr[i + 1]] = pr[p[i]];
                        rem[tps[i + 1]]--;
                    } else if (direct[pr[i + 1]] != pr[p[i]]) {
                        out.printLine(0);
                        return;
                    }
                    if (reverse[pr[p[i]]] == 0) {
                        reverse[pr[p[i]]] = pr[i + 1];
                    } else if (reverse[pr[p[i]]] != pr[i + 1]) {
                        out.printLine(0);
                        return;
                    }
                }
            }
            long answer = 1;
            long[] fact = IntegerUtils.generateFactorial(n + 1, MiscUtils.MOD7);
            for (int i : qty) {
                answer *= fact[i];
                answer %= MiscUtils.MOD7;
            }
            for (int i : rem) {
                answer *= fact[i];
                answer %= MiscUtils.MOD7;
            }
            out.printLine(answer);
        }

    }

    static class MiscUtils {
        public static final int MOD7 = (int) (1e9 + 7);

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

        public void printLine(int i) {
            writer.println(i);
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