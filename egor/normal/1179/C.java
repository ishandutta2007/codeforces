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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int[] min = new int[4000000];
        int[] sum = new int[4000000];
        int[] start = new int[1000000];

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int[] a = in.readIntArray(n);
            int[] b = in.readIntArray(m);
            for (int i : a) {
                start[1000000 - i]--;
            }
            for (int i : b) {
                start[1000000 - i]++;
            }
            init(0, 0, 999999);
            int q = in.readInt();
            for (int i = 0; i < q; i++) {
                int type = in.readInt();
                int id = in.readInt() - 1;
                int nVal = in.readInt();
                if (type == 1) {
                    update(0, 0, 999999, 1000000 - a[id], 1);
                    update(0, 0, 999999, 1000000 - nVal, -1);
                    a[id] = nVal;
                } else {
                    update(0, 0, 999999, 1000000 - b[id], -1);
                    update(0, 0, 999999, 1000000 - nVal, 1);
                    b[id] = nVal;
                }
                if (min[0] >= 0) {
                    out.printLine(-1);
                } else {
                    out.printLine(1000000 - getPos(0, 0, 999999, 0));
                }
            }
        }

        private int getPos(int root, int left, int right, int lSum) {
            if (left == right) {
                return left;
            }
            int middle = (left + right) >> 1;
            if (lSum + min[2 * root + 1] < 0) {
                return getPos(2 * root + 1, left, middle, lSum);
            } else {
                return getPos(2 * root + 2, middle + 1, right, lSum + sum[2 * root + 1]);
            }
        }

        private void update(int root, int left, int right, int at, int delta) {
            if (left > at || right < at) {
                return;
            }
            if (left == right) {
                sum[root] += delta;
                min[root] += delta;
            } else {
                int middle = (left + right) >> 1;
                update(2 * root + 1, left, middle, at, delta);
                update(2 * root + 2, middle + 1, right, at, delta);
                join(root);
            }
        }

        private void init(int root, int left, int right) {
            if (left == right) {
                min[root] = sum[root] = start[left];
            } else {
                int middle = (left + right) >> 1;
                init(2 * root + 1, left, middle);
                init(2 * root + 2, middle + 1, right);
                join(root);
            }
        }

        private void join(int root) {
            sum[root] = sum[2 * root + 1] + sum[2 * root + 2];
            min[root] = Math.min(min[2 * root + 1], sum[2 * root + 1] + min[2 * root + 2]);
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

        public int[] readIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
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

        public void printLine(int i) {
            writer.println(i);
        }

    }
}