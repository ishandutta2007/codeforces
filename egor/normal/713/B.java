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
        int stage;
        int n;
        OutputWriter out;
        InputReader in;

        void query(int end) {
            switch (stage) {
            case 0:
                out.printLine('?', 1, 1, end, n);
                break;
            case 1:
                out.printLine('?', 1, 1, n, end);
                break;
            case 2:
                out.printLine('?', n + 1 - end, 1, n, n);
                break;
            case 3:
                out.printLine('?', 1, n + 1 - end, n, n);
                break;
            }
            out.flush();
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.out = out = new OutputWriter(System.out);
            this.in = in = new InputReader(System.in);
            n = in.readInt();
            int[] endx = new int[2];
            int[] endy = new int[2];
            int[] stx = new int[2];
            int[] sty = new int[2];
            find(endx);
            stage++;
            find(endy);
            stage++;
            find(stx);
            for (int i = 0; i < 2; i++) {
                stx[i] = n + 1 - stx[i];
            }
            stage++;
            find(sty);
            for (int i = 0; i < 2; i++) {
                sty[i] = n + 1 - sty[i];
            }
            for (int i = 0; i < 8; i++) {
                if (stx[i & 1] > endx[i >> 2 & 1] || sty[i >> 1 & 1] > endy[0]) {
                    continue;
                }
                if (stx[1 - (i & 1)] > endx[1 - (i >> 2 & 1)] || sty[1 - (i >> 1 & 1)] > endy[1]) {
                    continue;
                }
                out.printLine('?', stx[i & 1], sty[i >> 1 & 1], endx[i >> 2 & 1], endy[0]);
                out.flush();
                if (in.readInt() == 0) {
                    continue;
                }
                out.printLine('?', stx[1 - (i & 1)], sty[1 - (i >> 1 & 1)], endx[1 - (i >> 2 & 1)], endy[1]);
                out.flush();
                if (in.readInt() != 0) {
                    out.printLine("!", stx[i & 1], sty[i >> 1 & 1], endx[i >> 2 & 1], endy[0], stx[1 - (i & 1)],
                            sty[1 - (i >> 1 & 1)], endx[1 - (i >> 2 & 1)], endy[1]);
                    out.flush();
                    return;
                }
            }
        }

        private void find(int[] endx) {
            int left = 1;
            int right = n;
            while (left < right) {
                int middle = (left + right) >> 1;
                query(middle);
                if (in.readInt() == 2) {
                    right = middle;
                } else {
                    left = middle + 1;
                }
            }
            endx[0] = left;
            left = 0;
            right--;
            while (left < right) {
                int middle = (left + right + 1) >> 1;
                query(middle);
                if (in.readInt() == 0) {
                    left = middle;
                } else {
                    right = middle - 1;
                }
            }
            endx[1] = left + 1;
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

        public void flush() {
            writer.flush();
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