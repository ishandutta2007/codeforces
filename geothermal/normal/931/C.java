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
 * @author Jay Leeds
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
            int n = in.nextInt();
            int min = 100001;
            int[] data = new int[n];
            for (int i = 0; i < n; i++) {
                data[i] = in.nextInt();
                min = Math.min(min, data[i]);
            }

            int[] count = new int[3];
            for (int i = 0; i < n; i++) count[data[i] - min]++;

            if (count[2] == 0) {
                out.printLine(n);
                for (int i = 0; i < n; i++) out.print((data[i]) + " ");
            } else if (Math.min(count[0], count[2]) > count[1] / 2) {
                int rem = Math.min(count[0], count[2]);
                out.printLine(n - 2 * rem);
                for (int i = 0; i < count[0] - rem; i++) {
                    out.print(min + " ");
                }
                for (int i = 0; i < count[1] + 2 * rem; i++) {
                    out.print((min + 1) + " ");
                }
                for (int i = 0; i < count[2] - rem; i++) {
                    out.print((min + 2) + " ");
                }
            } else {
                int rem = count[1] / 2;
                out.printLine(n - 2 * rem);
                for (int i = 0; i < count[0] + rem; i++) {
                    out.print(min + " ");
                }
                for (int i = 0; i < count[1] - 2 * rem; i++) {
                    out.print((min + 1) + " ");
                }
                for (int i = 0; i < count[2] + rem; i++) {
                    out.print((min + 2) + " ");
                }
            }
            out.printLine();
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream; //Fast IO by Egor Kulikov, modified by myself
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

        public int nextInt() {
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

        public void printLine() {
            writer.println();
        }

        public void printLine(int i) {
            writer.println(i);
        }

        public void close() {
            writer.close();
        }

    }
}