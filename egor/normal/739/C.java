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
        long[] left;
        long[] right;
        int[] mountain;
        int[] leftMountain;
        int[] rightMountain;
        int[] leftDown;
        int[] rightUp;
        int[] length;
        long[] delta;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] a = IOUtils.readIntArray(in, n);
            left = new long[4 * n];
            right = new long[4 * n];
            delta = new long[4 * n];
            mountain = new int[4 * n];
            leftMountain = new int[4 * n];
            rightMountain = new int[4 * n];
            leftDown = new int[4 * n];
            rightUp = new int[4 * n];
            length = new int[4 * n];
            init(0, 0, n - 1, a);
            int m = in.readInt();
            for (int i = 0; i < m; i++) {
                int f = in.readInt() - 1;
                int t = in.readInt() - 1;
                int d = in.readInt();
                update(0, 0, n - 1, f, t, d);
                out.printLine(mountain[0]);
            }
        }

        private void update(int root, int l, int r, int f, int t, int d) {
            if (l >= f && r <= t) {
                delta[root] += d;
                left[root] += d;
                right[root] += d;
                return;
            }
            if (l > t || r < f) {
                return;
            }
            pushDown(root);
            int middle = (l + r) >> 1;
            update(2 * root + 1, l, middle, f, t, d);
            update(2 * root + 2, middle + 1, r, f, t, d);
            join(root);
        }

        private void pushDown(int root) {
            left[2 * root + 1] += delta[root];
            right[2 * root + 1] += delta[root];
            delta[2 * root + 1] += delta[root];
            left[2 * root + 2] += delta[root];
            right[2 * root + 2] += delta[root];
            delta[2 * root + 2] += delta[root];
            delta[root] = 0;
        }

        private void init(int root, int a, int b, int[] h) {
            if (a == b) {
                left[root] = right[root] = h[a];
                leftMountain[root] = rightMountain[root] = leftDown[root] = rightUp[root] = 1;
                mountain[root] = 1;
                length[root] = 1;
                return;
            }
            int middle = (a + b) >> 1;
            init(2 * root + 1, a, middle, h);
            init(2 * root + 2, middle + 1, b, h);
            join(root);
        }

        private void join(int root) {
            left[root] = left[2 * root + 1];
            right[root] = right[2 * root + 2];
            leftMountain[root] = leftMountain[2 * root + 1];
            rightMountain[root] = rightMountain[2 * root + 2];
            leftDown[root] = leftDown[2 * root + 1];
            rightUp[root] = rightUp[2 * root + 2];
            mountain[root] = Math.max(mountain[2 * root + 1], mountain[2 * root + 2]);
            length[root] = length[2 * root + 1] + length[2 * root + 2];
            if (right[2 * root + 1] < left[2 * root + 2]) {
                mountain[root] = Math.max(mountain[root], rightUp[2 * root + 1] + leftMountain[2 * root + 2]);
                if (rightUp[2 * root + 1] == length[2 * root + 1]) {
                    leftMountain[root] = length[2 * root + 1] + leftMountain[2 * root + 2];
                }
                if (rightMountain[2 * root + 2] == length[2 * root + 2]) {
                    rightMountain[root] = rightUp[2 * root + 1] + length[2 * root + 2];
                }
                if (rightUp[2 * root + 2] == length[2 * root + 2]) {
                    rightUp[root] = length[2 * root + 2] + rightUp[2 * root + 1];
                }
            } else if (right[2 * root + 1] > left[2 * root + 2]) {
                mountain[root] = Math.max(mountain[root], rightMountain[2 * root + 1] + leftDown[2 * root + 2]);
                if (leftMountain[2 * root + 1] == length[2 * root + 1]) {
                    leftMountain[root] = length[2 * root + 1] + leftDown[2 * root + 2];
                }
                if (leftDown[2 * root + 2] == length[2 * root + 2]) {
                    rightMountain[root] = rightMountain[2 * root + 1] + length[2 * root + 2];
                }
                if (leftDown[2 * root + 1] == length[2 * root + 1]) {
                    leftDown[root] = length[2 * root + 1] + leftDown[2 * root + 2];
                }
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

    static class IOUtils {
        public static int[] readIntArray(InputReader in, int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readInt();
            }
            return array;
        }

    }
}