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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int k = in.readInt();
            int[] c = IOUtils.readIntArray(in, n);
            int[][] p = IOUtils.readIntTable(in, n, m);
//        decreaseByOne(c);
            long[][][] answer = new long[n + 1][m + 1][k + 1];
            ArrayUtils.fill(answer, Long.MAX_VALUE);
            answer[0][0][0] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= m; j++) {
                    for (int l = 0; l <= k; l++) {
                        if (answer[i][j][l] == Long.MAX_VALUE) {
                            continue;
                        }
                        for (int o = c[i] == 0 ? 1 : c[i]; o <= (c[i] == 0 ? m : c[i]); o++) {
                            if (j == o) {
                                answer[i + 1][j][l] = Math.min(answer[i + 1][j][l], answer[i][j][l] + (c[i] == 0 ?
                                        p[i][o - 1] : 0));
                            } else if (l < k) {
                                answer[i + 1][o][l + 1] = Math.min(answer[i + 1][o][l + 1], answer[i][j][l] + (c[i] == 0
                                        ? p[i][o - 1] : 0));
                            }
                        }
                    }
                }
            }
            long result = Long.MAX_VALUE;
            for (int i = 0; i <= m; i++) {
                result = Math.min(result, answer[n][i][k]);
            }
            out.printLine(result == Long.MAX_VALUE ? -1 : result);
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

    static class ArrayUtils {
        public static void fill(long[][] array, long value) {
            for (long[] row : array) {
                Arrays.fill(row, value);
            }
        }

        public static void fill(long[][][] array, long value) {
            for (long[][] row : array) {
                fill(row, value);
            }
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

        public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = readIntArray(in, columnCount);
            }
            return table;
        }

    }
}