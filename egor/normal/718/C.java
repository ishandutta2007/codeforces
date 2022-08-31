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
        long[][] mat;
        long[] temp = new long[4];
        long[] by = {1, 1, 1, 0};
        long[][] result;
        long[][] delta;
        long[] change = new long[4];

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int[] a = IOUtils.readIntArray(in, n);
            mat = new long[4 * n][4];
            result = new long[4 * n][4];
            delta = new long[4 * n][4];
            init(0, 0, n - 1, a);
            for (int i = 0; i < m; i++) {
                int tp = in.readInt();
                int l = in.readInt() - 1;
                int r = in.readInt() - 1;
                if (tp == 1) {
                    int x = in.readInt();
                    calculate(change, temp, x);
                    update(0, 0, n - 1, l, r);
                } else {
                    query(0, 0, n - 1, l, r);
                    out.printLine(result[0][1]);
                }
            }
        }

        private void query(int root, int from, int to, int l, int r) {
            if (l > to || from > r) {
                Arrays.fill(result[root], 0);
                return;
            }
            if (l <= from && to <= r) {
                copy(result[root], mat[root]);
                return;
            }
            pushDown(root);
            int middle = (from + to) >> 1;
            query(2 * root + 1, from, middle, l, r);
            query(2 * root + 2, middle + 1, to, l, r);
            sum(result[root], result[2 * root + 1], result[2 * root + 2]);
        }

        private void update(int root, int from, int to, int l, int r) {
            if (l > to || from > r) {
                return;
            }
            if (l <= from && to <= r) {
                multiply(temp, mat[root], change);
                copy(mat[root], temp);
                multiply(temp, delta[root], change);
                copy(delta[root], temp);
                return;
            }
            pushDown(root);
            int middle = (from + to) >> 1;
            update(2 * root + 1, from, middle, l, r);
            update(2 * root + 2, middle + 1, to, l, r);
            sum(mat[root], mat[2 * root + 1], mat[2 * root + 2]);
        }

        private void pushDown(int root) {
            push(root, 2 * root + 1);
            push(root, 2 * root + 2);
            makeOne(delta[root]);
        }

        private void push(int from, int to) {
            multiply(temp, mat[to], delta[from]);
            copy(mat[to], temp);
            multiply(temp, delta[to], delta[from]);
            copy(delta[to], temp);
        }

        private void copy(long[] a, long[] b) {
            System.arraycopy(b, 0, a, 0, 4);
        }

        private void init(int root, int left, int right, int[] a) {
            makeOne(delta[root]);
            if (left == right) {
                calculate(mat[root], temp, a[left]);
            } else {
                int middle = (left + right) >> 1;
                init(2 * root + 1, left, middle, a);
                init(2 * root + 2, middle + 1, right, a);
                sum(mat[root], mat[2 * root + 1], mat[2 * root + 2]);
            }
        }

        private void calculate(long[] result, long[] temp, long exponent) {
            if (exponent == 0) {
                makeOne(result);
                return;
            }
            if ((exponent & 1) == 1) {
                calculate(temp, result, exponent - 1);
                multiply(result, temp, by);
            } else {
                calculate(temp, result, exponent >> 1);
                multiply(result, temp, temp);
            }
        }

        private void makeOne(long[] result) {
            result[0] = result[3] = 1;
            result[1] = result[2] = 0;
        }

        private void multiply(long[] a, long[] b, long[] c) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    a[2 * i + j] = 0;
                    for (int k = 0; k < 2; k++) {
                        a[2 * i + j] += b[2 * i + k] * c[2 * k + j];
                    }
                    a[2 * i + j] %= MiscUtils.MOD7;
                }
            }
        }

        private void sum(long[] a, long[] b, long[] c) {
            for (int i = 0; i < 4; i++) {
                a[i] = b[i] + c[i];
                if (a[i] >= MiscUtils.MOD7) {
                    a[i] -= MiscUtils.MOD7;
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

    static class MiscUtils {
        public static final int MOD7 = (int) (1e9 + 7);

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