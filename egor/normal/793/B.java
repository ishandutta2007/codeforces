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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            char[][] map = IOUtils.readTable(in, n, m);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 'S' || map[i][j] == 'T') {
                        char x = map[i][j] == 'S' ? '$' : '#';
                        for (int k = 0; k < 4; k++) {
                            int ni = i + MiscUtils.DX4[k];
                            int nj = j + MiscUtils.DY4[k];
                            while (MiscUtils.isValidCell(ni, nj, n, m) && map[ni][nj] != '*') {
                                if (map[ni][nj] != '.') {
                                    out.printLine("YES");
                                    return;
                                }
                                map[ni][nj] = x;
                                ni += MiscUtils.DX4[k];
                                nj += MiscUtils.DY4[k];
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                boolean foundS = false;
                boolean foundT = false;
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == '*') {
                        foundS = false;
                        foundT = false;
                    } else if (map[i][j] == '#') {
                        if (foundT) {
                            out.printLine("YES");
                            return;
                        } else {
                            foundS = true;
                        }
                    } else if (map[i][j] == '$') {
                        if (foundS) {
                            out.printLine("YES");
                            return;
                        } else {
                            foundT = true;
                        }
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                boolean foundS = false;
                boolean foundT = false;
                for (int j = 0; j < n; j++) {
                    if (map[j][i] == '*') {
                        foundS = false;
                        foundT = false;
                    } else if (map[j][i] == '#') {
                        if (foundT) {
                            out.printLine("YES");
                            return;
                        } else {
                            foundS = true;
                        }
                    } else if (map[j][i] == '$') {
                        if (foundS) {
                            out.printLine("YES");
                            return;
                        } else {
                            foundT = true;
                        }
                    }
                }
            }
            out.printLine("NO");
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
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

    static class IOUtils {
        public static char[] readCharArray(InputReader in, int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readCharacter();
            }
            return array;
        }

        public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = readCharArray(in, columnCount);
            }
            return table;
        }

    }

    static class MiscUtils {
        public static final int[] DX4 = {1, 0, -1, 0};
        public static final int[] DY4 = {0, -1, 0, 1};

        public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
            return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
        }

    }
}