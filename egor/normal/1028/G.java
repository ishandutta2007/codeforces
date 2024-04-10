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
        G solver = new G();
        solver.solve(1, in, out);
        out.close();
    }

    static class G {
        long[] moves = {204761410474L};

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long left = 1;
            long right = 10004205361450474L;
            for (int i = 0; i < 5; i++) {
                long[] request;
                if (i == 0) {
                    request = new long[2];
                    request[0] = 1;
                    request[1] = moves[0];
                } else {
                    request = request(5 - i, left, right);
                }
                out.printLine(request);
                out.flush();
                int result = in.readInt();
                if (result == -1) {
                    return;
                }
                if (result == 0) {
                    right = request[1] - 1;
                } else if (result == request[0]) {
                    left = request[result] + 1;
                } else {
                    left = request[result] + 1;
                    right = request[result + 1] - 1;
                }
            }
        }

        long bigMove(int moves) {
            long result = 0;
            for (int i = 0; i < moves; i++) {
                result *= 10001;
                result += 10000;
            }
            return result;
        }

        long[] request(int moves, long left, long right) {
            long[] request = new long[(int) (1 + Math.min(left, 10000))];
            request[0] = request.length - 1;
            for (int i = 1; i < request.length; i++) {
                if (left > right) {
                    request[0] = i - 1;
                    request = Arrays.copyOf(request, i);
                    return request;
                }
                if (left >= 10000) {
                    long next = bigMove(moves - 1) + left;
                    request[i] = Math.min(next, right);
                    left = next + 1;
                } else {
                    long from = left;
                    long to = right;
                    while (from < to) {
                        long middle = (from + to + 1) >> 1;
                        if (fit(moves - 1, left, middle - 1)) {
                            from = middle;
                        } else {
                            to = middle - 1;
                        }
                    }
                    request[i] = from;
                    left = from + 1;
                }
            }
            if (!fit(moves - 1, left, right)) {
                return null;
            }
            return request;
        }

        private boolean fit(int moves, long left, long right) {
            if (left > right) {
                return true;
            }
            if (moves == 0) {
                return false;
            }
            long max = Math.min(left, 10000);
            for (int i = 1; i < moves; i++) {
                max *= 10001;
                max += 10000;
            }
            if (right - left >= max) {
                return false;
            }
            if (left >= 10000) {
                return true;
            }
            int length = (int) (1 + Math.min(left, 10000));
            for (int i = 1; i < length; i++) {
                if (left > right) {
                    return true;
                }
                if (left >= 10000) {
                    long next = bigMove(moves - 1) + left;
                    left = next + 1;
                } else {
                    long from = left;
                    long to = right;
                    while (from < to) {
                        long middle = (from + to + 1) >> 1;
                        if (fit(moves - 1, left, middle - 1)) {
                            from = middle;
                        } else {
                            to = middle - 1;
                        }
                    }
                    left = from + 1;
                }
            }
            if (!fit(moves - 1, left, right)) {
                return false;
            }
            return true;
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

        public void print(long[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(long[] array) {
            print(array);
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