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
            int q = in.readInt();
            int[] p = IOUtils.readIntArray(in, n);
            int[] l = new int[q];
            int[] d = new int[q];
            int[] r = new int[q];
            int[] u = new int[q];
            IOUtils.readIntArrays(in, l, d, r, u);
            MiscUtils.decreaseByOne(l, d);
            int[] firstL = ArrayUtils.createArray(n + 1, -1);
            int[] nextL = new int[q];
            int[] firstR = ArrayUtils.createArray(n + 1, -1);
            int[] nextR = new int[q];
            for (int i = 0; i < q; i++) {
                nextL[i] = firstL[l[i]];
                firstL[l[i]] = i;
                nextR[i] = firstR[r[i]];
                firstR[r[i]] = i;
            }
            FenwickTree tree = new FenwickTree(n + 1);
            long[][] values = new long[q][9];
            for (int i = 0; i <= n; i++) {
                for (int j = firstL[i]; j != -1; j = nextL[j]) {
                    values[j][0] = tree.get(1, d[j]);
                    values[j][3] = tree.get(d[j] + 1, u[j]);
                    values[j][6] = tree.get(u[j] + 1, n);
                }
                for (int j = firstR[i]; j != -1; j = nextR[j]) {
                    values[j][1] = tree.get(1, d[j]) - values[j][0];
                    values[j][4] = tree.get(d[j] + 1, u[j]) - values[j][3];
                    values[j][7] = tree.get(u[j] + 1, n) - values[j][6];
                }
                if (i < n) {
                    tree.add(p[i], 1);
                }
            }
            for (int i = 0; i < q; i++) {
                values[i][2] = tree.get(1, d[i]) - values[i][0] - values[i][1];
                values[i][5] = tree.get(d[i] + 1, u[i]) - values[i][3] - values[i][4];
                values[i][8] = tree.get(u[i] + 1, n) - values[i][6] - values[i][7];
                long aa = values[i][0];
                long bb = values[i][1];
                long cc = values[i][2];
                long dd = values[i][3];
                long ee = values[i][4];
                long ff = values[i][5];
                long gg = values[i][6];
                long hh = values[i][7];
                long ii = values[i][8];
                out.printLine(aa * (ee + ff + hh + ii) + bb * (dd + ee + ff + gg + hh + ii) + cc * (dd + ee + gg + hh) +
                        dd * (ee + ff + hh + ii) + ee * (ff + gg + hh + ii) + ff * (gg + hh) + ee * (ee - 1) / 2);
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

    static class FenwickTree {
        private final long[] value;

        public FenwickTree(int size) {
            value = new long[size];
        }

        public long get(int from, int to) {
            if (from > to) {
                return 0;
            }
            return get(to) - get(from - 1);
        }

        private long get(int to) {
            to = Math.min(to, value.length - 1);
            long result = 0;
            while (to >= 0) {
                result += value[to];
                to = (to & (to + 1)) - 1;
            }
            return result;
        }

        public void add(int at, long value) {
            while (at < this.value.length) {
                this.value[at] += value;
                at = at | (at + 1);
            }
        }

    }

    static class MiscUtils {
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
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

        public static void readIntArrays(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
                }
            }
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
        public static int[] createArray(int count, int value) {
            int[] array = new int[count];
            Arrays.fill(array, value);
            return array;
        }

    }
}