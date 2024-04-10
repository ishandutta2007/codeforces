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
        DBST solver = new DBST();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBST {
        boolean[][] ok;
        int[][] right;
        int[][] left;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] a = in.readIntArray(n);
            ok = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ok[i][j] = IntegerUtils.gcd(a[i], a[j]) != 1;
                }
            }
            left = new int[n][n];
            ArrayUtils.fill(left, -1);
            right = new int[n][n];
            ArrayUtils.fill(right, -1);
            for (int i = 0; i < n; i++) {
                if (goLeft(0, i - 1) && goRight(i + 1, n - 1)) {
                    out.printLine("Yes");
                    return;
                }
            }
            out.printLine("No");
        }

        private boolean goLeft(int from, int to) {
            if (to < from) {
                return true;
            }
            if (left[from][to] != -1) {
                return left[from][to] == 1;
            }
            for (int i = from; i <= to; i++) {
                if (ok[i][to + 1] && goLeft(from, i - 1) && goRight(i + 1, to)) {
                    left[from][to] = 1;
                    return true;
                }
            }
            left[from][to] = 0;
            return false;
        }

        private boolean goRight(int from, int to) {
            if (to < from) {
                return true;
            }
            if (right[from][to] != -1) {
                return right[from][to] == 1;
            }
            for (int i = from; i <= to; i++) {
                if (ok[i][from - 1] && goLeft(from, i - 1) && goRight(i + 1, to)) {
                    right[from][to] = 1;
                    return true;
                }
            }
            right[from][to] = 0;
            return false;
        }

    }

    static class IntegerUtils {
        public static int gcd(int a, int b) {
            a = Math.abs(a);
            b = Math.abs(b);
            while (b != 0) {
                int temp = a % b;
                a = b;
                b = temp;
            }
            return a;
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

    static class ArrayUtils {
        public static void fill(int[][] array, int value) {
            for (int[] row : array) {
                Arrays.fill(row, value);
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
}