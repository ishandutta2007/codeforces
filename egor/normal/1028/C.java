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
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] x1 = new int[n];
            int[] y1 = new int[n];
            int[] x2 = new int[n];
            int[] y2 = new int[n];
            in.readIntArrays(x1, y1, x2, y2);
            int[] mx1 = new int[n + 1];
            int[] my1 = new int[n + 1];
            int[] mx2 = new int[n + 1];
            int[] my2 = new int[n + 1];
            mx1[n] = my1[n] = Integer.MIN_VALUE;
            mx2[n] = my2[n] = Integer.MAX_VALUE;
            for (int i = n - 1; i >= 0; i--) {
                mx1[i] = Math.max(mx1[i + 1], x1[i]);
                my1[i] = Math.max(my1[i + 1], y1[i]);
                mx2[i] = Math.min(mx2[i + 1], x2[i]);
                my2[i] = Math.min(my2[i + 1], y2[i]);
            }
            int cx1 = Integer.MIN_VALUE;
            int cy1 = Integer.MIN_VALUE;
            int cx2 = Integer.MAX_VALUE;
            int cy2 = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if (Math.max(cx1, mx1[i + 1]) <= Math.min(cx2, mx2[i + 1]) &&
                        Math.max(cy1, my1[i + 1]) <= Math.min(cy2, my2[i + 1])) {
                    out.printLine(Math.max(cx1, mx1[i + 1]), Math.max(cy1, my1[i + 1]));
                    return;
                }
                cx1 = Math.max(cx1, x1[i]);
                cy1 = Math.max(cy1, y1[i]);
                cx2 = Math.min(cx2, x2[i]);
                cy2 = Math.min(cy2, y2[i]);
            }
            while (true) {
                ;
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