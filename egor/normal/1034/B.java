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
        BLittleCLoves3II solver = new BLittleCLoves3II();
        solver.solve(1, in, out);
        out.close();
    }

    static class BLittleCLoves3II {
        int[][][] answer;
        long n;
        long m;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.readInt();
            m = in.readInt();
            if (n > m) {
                long t = n;
                n = m;
                m = t;
            }
            if (n == 1) {
                long x = m % 6;
                if (x <= 3) {
                    out.printLine(m - x);
                    return;
                }
                if (x == 4) {
                    out.printLine(m - 2);
                    return;
                }
                out.printLine(m - 1);
                return;
            }
            if (n <= 5 && m <= 30) {
                answer = new int[(int) (m + 1)][(int) (n + 1)][1 << (3 * n)];
                ArrayUtils.fill(answer, -1);
                out.printLine(go(0, 0, 0));
                return;
            }
            out.printLine(n * m - n * m % 2);
        }

        private int go(int row, int col, int mask) {
            if (answer[row][col][mask] != -1) {
                return answer[row][col][mask];
            }
            if (row == m) {
                return answer[row][col][mask] = mask == 0 ? 0 : Integer.MIN_VALUE;
            }
            if (col == n) {
                return answer[row][col][mask] = go(row + 1, 0, mask);
            }
            if ((mask & 1) == 1) {
                return answer[row][col][mask] = go(row, col + 1, mask >> 1);
            }
            answer[row][col][mask] = go(row, col + 1, mask >> 1);
            answer[row][col][mask] =
                    Math.max(go(row, col + 1, (mask >> 1) + (1 << (3 * n - 1))) + 2, answer[row][col][mask]);
            if (col != 0 && (mask >> (2 * n - 1) & 1) == 0) {
                answer[row][col][mask] = Math.max(answer[row][col][mask], go(row, col + 1,
                        (mask >> 1) + (1 << (2 * n - 2))) + 2);
            }
            if (col != n - 1 && (mask >> (2 * n + 1) & 1) == 0) {
                answer[row][col][mask] = Math.max(answer[row][col][mask], go(row, col + 1,
                        (mask >> 1) + (1 << (2 * n))) + 2);
            }
            if (col >= 2 && (mask >> (n - 2) & 1) == 0) {
                answer[row][col][mask] = Math.max(answer[row][col][mask], go(row, col + 1,
                        (mask >> 1) + (1 << (n - 3))) + 2);
            }
            if (col < n - 1 && (mask >> (n + 2) & 1) == 0) {
                answer[row][col][mask] = Math.max(answer[row][col][mask], go(row, col + 1,
                        (mask >> 1) + (1 << (n + 1))) + 2);
            }
            return answer[row][col][mask];
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

    static class ArrayUtils {
        public static void fill(int[][] array, int value) {
            for (int[] row : array) {
                Arrays.fill(row, value);
            }
        }

        public static void fill(int[][][] array, int value) {
            for (int[][] subArray : array) {
                fill(subArray, value);
            }
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