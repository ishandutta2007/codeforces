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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int[][] right;
        int[][] down;
        int[][][][] answer;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            char[][] map = in.readTable(n, n);
            right = new int[n][n];
            down = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = n - 1; j >= 0; j--) {
                    if (map[i][j] != '#') {
                        right[i][j] = 1;
                        if (j + 1 < n) {
                            right[i][j] += right[i][j + 1];
                        }
                    }
                    if (map[j][i] != '#') {
                        down[j][i] = 1;
                        if (j + 1 < n) {
                            down[j][i] += down[j + 1][i];
                        }
                    }
                }
            }
            answer = new int[n][n][n][n];
            ArrayUtils.fill(answer, -1);
            out.printLine(go(0, n - 1, 0, n - 1));
        }

        private int go(int sx, int fx, int sy, int fy) {
            if (sx > fx || sy > fy) {
                return 0;
            }
            if (answer[sx][fx][sy][fy] != -1) {
                return answer[sx][fx][sy][fy];
            }
            if (fx - sx >= fy - sy) {
                answer[sx][fx][sy][fy] = fx - sx + 1;
                for (int i = sx; i <= fx; i++) {
                    if (right[i][sy] >= fy - sy + 1) {
                        answer[sx][fx][sy][fy] = Math.min(answer[sx][fx][sy][fy], go(sx, i - 1, sy, fy) + go(i + 1, fx,
                                sy, fy));
                    }
                }
            } else {
                answer[sx][fx][sy][fy] = fy - sy + 1;
                for (int i = sy; i <= fy; i++) {
                    if (down[sx][i] >= fx - sx + 1) {
                        answer[sx][fx][sy][fy] = Math.min(answer[sx][fx][sy][fy], go(sx, fx, sy, i - 1) + go(sx, fx,
                                i + 1, fy));
                    }
                }
            }
            return answer[sx][fx][sy][fy];
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

        public char[] readCharArray(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readCharArray(columnCount);
            }
            return table;
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

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
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

        public static void fill(int[][][][] array, int value) {
            for (int[][][] subArray : array) {
                fill(subArray, value);
            }
        }

    }
}