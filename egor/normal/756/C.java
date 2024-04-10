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
        int[] max;
        int[] delta;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int m = in.readInt();
            int[] p = new int[m];
            int[] t = new int[m];
            int[] x = new int[m];
            for (int i = 0; i < m; i++) {
                p[i] = in.readInt() - 1;
                t[i] = in.readInt();
                if (t[i] == 1) {
                    x[i] = in.readInt();
                }
            }
            max = new int[4 * m];
            delta = new int[4 * m];
            int[] answer = new int[m];
            int[] number = new int[m];
            for (int i = 0; i < m; i++) {
                if (t[i] == 1) {
                    number[p[i]] = x[i];
                }
                update(0, 0, m - 1, 0, p[i], 2 * t[i] - 1);
                if (max[0] <= 0) {
                    answer[i] = -1;
                } else {
                    int pos = binarySearch(0, 0, m - 1);
                    answer[i] = number[pos];
                }
                out.printLine(answer[i]);
            }
        }

        private int binarySearch(int root, int left, int right) {
            if (left == right) {
                return left;
            }
            pushDown(root);
            int middle = (left + right) >> 1;
            if (max[2 * root + 2] > 0) {
                return binarySearch(2 * root + 2, middle + 1, right);
            }
            return binarySearch(2 * root + 1, left, middle);
        }

        private void update(int root, int left, int right, int from, int to, int by) {
            if (left > to || right < from) {
                return;
            }
            if (left >= from && right <= to) {
                updateBy(root, by);
                return;
            }
            pushDown(root);
            int middle = (left + right) >> 1;
            update(2 * root + 1, left, middle, from, to, by);
            update(2 * root + 2, middle + 1, right, from, to, by);
            max[root] = Math.max(max[2 * root + 1], max[2 * root + 2]);
        }

        private void pushDown(int root) {
            updateBy(2 * root + 1, delta[root]);
            updateBy(2 * root + 2, delta[root]);
            delta[root] = 0;
        }

        private void updateBy(int root, int by) {
            max[root] += by;
            delta[root] += by;
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