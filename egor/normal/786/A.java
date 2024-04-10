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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int k1 = in.readInt();
            int[] s1 = IOUtils.readIntArray(in, k1);
            int k2 = in.readInt();
            int[] s2 = IOUtils.readIntArray(in, k2);
            int[] win = new int[2 * n];
            win[0] = -1;
            win[n] = -1;
            int[] remaining = new int[2 * n];
            Arrays.fill(remaining, 0, n, k1);
            Arrays.fill(remaining, n, 2 * n, k2);
            int[] queue = new int[2 * n];
            queue[0] = 0;
            queue[1] = n;
            int size = 2;
            for (int i = 0; i < size; i++) {
                int at = queue[i];
                if (win[at] == -1) {
                    if (at < n) {
                        for (int j : s2) {
                            int from = at - j;
                            if (from < 0) {
                                from += n;
                            }
                            from += n;
                            if (win[from] == 0) {
                                win[from] = 1;
                                queue[size++] = from;
                            }
                        }
                    } else {
                        for (int j : s1) {
                            int from = at - n - j;
                            if (from < 0) {
                                from += n;
                            }
                            if (win[from] == 0) {
                                win[from] = 1;
                                queue[size++] = from;
                            }
                        }
                    }
                } else {
                    if (at < n) {
                        for (int j : s2) {
                            int from = at - j;
                            if (from < 0) {
                                from += n;
                            }
                            from += n;
                            remaining[from]--;
                            if (remaining[from] == 0 && win[from] == 0) {
                                win[from] = -1;
                                queue[size++] = from;
                            }
                        }
                    } else {
                        for (int j : s1) {
                            int from = at - n - j;
                            if (from < 0) {
                                from += n;
                            }
                            remaining[from]--;
                            if (remaining[from] == 0 && win[from] == 0) {
                                win[from] = -1;
                                queue[size++] = from;
                            }
                        }
                    }
                }
            }
            String[] result = {"Lose", "Loop", "Win"};
            String[] first = new String[n - 1];
            for (int i = 1; i < n; i++) {
                first[i - 1] = result[win[i] + 1];
            }
            String[] second = new String[n - 1];
            for (int i = 1; i < n; i++) {
                second[i - 1] = result[win[i + n] + 1];
            }
            out.printLine(first);
            out.printLine(second);
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