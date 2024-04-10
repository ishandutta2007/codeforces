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
        CLift solver = new CLift();
        solver.solve(1, in, out);
        out.close();
    }

    static class CLift {
        int[] a;
        int[] b;
        int[][][][][][] result;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            a = new int[n];
            b = new int[n];
            in.readIntArrays(a, b);
            result = new int[9][n + 1][10][][][];
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j <= n; j++) {
                    for (int k = 0; k < 10; k++) {
                        result[i][j][k] = new int[k + 1][][];
                        for (int l = 0; l <= k; l++) {
                            result[i][j][k][l] = new int[l + 1][];
                            for (int m = 0; m <= l; m++) {
                                result[i][j][k][l][m] = ArrayUtils.createArray(m + 1, -1);
                            }
                        }
                    }
                }
            }
            out.printLine(go(0, 0, 0, 0, 0, 0) + 2 * n);
        }

        private int go(int floor, int id, int e1, int e2, int e3, int e4) {
            if (result[floor][id][e1][e2][e3][e4] != -1) {
                return result[floor][id][e1][e2][e3][e4];
            }
            if (id == a.length && e1 == 0) {
                return result[floor][id][e1][e2][e3][e4] = 0;
            }
            result[floor][id][e1][e2][e3][e4] = Integer.MAX_VALUE;
            if (e1 != 0) {
                result[floor][id][e1][e2][e3][e4] = Math.min(result[floor][id][e1][e2][e3][e4], go(e1 - 1, id, e2, e3,
                        e4, 0) + Math.abs(floor + 1 - e1));
                if (e2 != 0) {
                    result[floor][id][e1][e2][e3][e4] =
                            Math.min(result[floor][id][e1][e2][e3][e4], go(e2 - 1, id, e1, e3,
                                    e4, 0) + Math.abs(floor + 1 - e2));
                    if (e3 != 0) {
                        result[floor][id][e1][e2][e3][e4] = Math.min(result[floor][id][e1][e2][e3][e4], go(e3 - 1, id,
                                e1, e2, e4, 0) + Math.abs(floor + 1 - e3));
                        if (e4 != 0) {
                            result[floor][id][e1][e2][e3][e4] =
                                    Math.min(result[floor][id][e1][e2][e3][e4], go(e4 - 1, id,
                                            e1, e2, e3, 0) + Math.abs(floor + 1 - e4));
                        }
                    }
                }
            }
            if (id != a.length && e4 == 0) {
                if (b[id] >= e1) {
                    result[floor][id][e1][e2][e3][e4] =
                            Math.min(result[floor][id][e1][e2][e3][e4], go(a[id] - 1, id + 1,
                                    b[id], e1, e2, e3) + Math.abs(floor + 1 - a[id]));
                } else if (b[id] >= e2) {
                    result[floor][id][e1][e2][e3][e4] =
                            Math.min(result[floor][id][e1][e2][e3][e4], go(a[id] - 1, id + 1,
                                    e1, b[id], e2, e3) + Math.abs(floor + 1 - a[id]));
                } else if (b[id] >= e3) {
                    result[floor][id][e1][e2][e3][e4] =
                            Math.min(result[floor][id][e1][e2][e3][e4], go(a[id] - 1, id + 1,
                                    e1, e2, b[id], e3) + Math.abs(floor + 1 - a[id]));
                } else {
                    result[floor][id][e1][e2][e3][e4] =
                            Math.min(result[floor][id][e1][e2][e3][e4], go(a[id] - 1, id + 1,
                                    e1, e2, e3, b[id]) + Math.abs(floor + 1 - a[id]));
                }
            }
            return result[floor][id][e1][e2][e3][e4];
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
        public static int[] createArray(int count, int value) {
            int[] array = new int[count];
            Arrays.fill(array, value);
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

        public void readIntArrays(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
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