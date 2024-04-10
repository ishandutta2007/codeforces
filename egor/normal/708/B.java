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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int a00 = in.readInt();
            int a01 = in.readInt();
            int a10 = in.readInt();
            int a11 = in.readInt();
            int q0 = 0;
            while (q0 * (q0 - 1) / 2 < a00) {
                q0++;
            }
            if (q0 * (q0 - 1) / 2 != a00) {
                out.printLine("Impossible");
                return;
            }
            int q1 = 0;
            while (q1 * (q1 - 1) / 2 < a11) {
                q1++;
            }
            if (q1 * (q1 - 1) / 2 != a11) {
                out.printLine("Impossible");
                return;
            }
            if (a00 == 0 && a01 + a10 > 0) {
                q0 = 1;
            }
            if (a11 == 0 && a01 + a10 > 0) {
                q1 = 1;
            }
            if (a00 + a01 + a10 + a11 == 0) {
                q0 = 1;
            }
            if ((long) q1 * q0 != a01 + a10) {
                out.printLine("Impossible");
                return;
            }
            StringBuilder answer = new StringBuilder();
            if (q0 == 0 || q1 == 0) {
                for (int i = 0; i < q0; i++) {
                    answer.append('0');
                }
                for (int i = 0; i < q1; i++) {
                    answer.append('1');
                }
            } else {
                int head1 = a10 / q0;
                for (int i = 0; i < head1; i++) {
                    answer.append('1');
                }
                int head0 = q0 - a10 % q0;
                for (int i = 0; i < head0; i++) {
                    answer.append('0');
                }
                if (a01 != 0) {
                    answer.append('1');
                }
                for (int i = 0; i < q0 - head0; i++) {
                    answer.append('0');
                }
                for (int i = 0; i < q1 - head1 - 1; i++) {
                    answer.append('1');
                }
            }
            out.printLine(answer);
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