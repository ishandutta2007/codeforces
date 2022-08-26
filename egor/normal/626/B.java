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
        boolean[][][] processed;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            char[] cards = IOUtils.readCharArray(in, n);
            int[] qty = new int[3];
            for (char c : cards) {
                switch (c) {
                case 'R':
                    qty[0]++;
                    break;
                case 'G':
                    qty[1]++;
                    break;
                case 'B':
                    qty[2]++;
                    break;
                }
            }
            processed = new boolean[n + 1][n + 1][n + 1];
            go(qty[0], qty[1], qty[2]);
            if (processed[0][0][1]) {
                out.print('B');
            }
            if (processed[0][1][0]) {
                out.print('G');
            }
            if (processed[1][0][0]) {
                out.print('R');
            }
            out.printLine();
        }

        private void go(int r, int g, int b) {
            if (processed[r][g][b]) {
                return;
            }
            processed[r][g][b] = true;
            if (r >= 2) {
                go(r - 1, g, b);
            }
            if (g >= 2) {
                go(r, g - 1, b);
            }
            if (b >= 2) {
                go(r, g, b - 1);
            }
            if (r >= 1 && g >= 1) {
                go(r - 1, g - 1, b + 1);
            }
            if (r >= 1 && b >= 1) {
                go(r - 1, g + 1, b - 1);
            }
            if (b >= 1 && g >= 1) {
                go(r + 1, g - 1, b - 1);
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

        public void printLine() {
            writer.println();
        }

        public void print(char i) {
            writer.print(i);
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
        private SpaceCharFilter filter;

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

    }
}