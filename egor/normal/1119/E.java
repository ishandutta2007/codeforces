import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.NavigableSet;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        EPavelITreugolniki solver = new EPavelITreugolniki();
        solver.solve(1, in, out);
        out.close();
    }

    static class EPavelITreugolniki {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] a = in.readIntArray(n);
            NavigableSet<Integer> odd = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 1) {
                    odd.add(i);
                }
            }
            long answer = 0;
            int at = 0;
            for (int i = n - 1; i >= at; i--) {
                if (a[i] == 1) {
                    odd.remove(i);
                }
                if (a[i] <= 1) {
                    continue;
                }
                while (a[i] >= 2 && !odd.isEmpty()) {
                    int other = odd.pollLast();
                    a[other]--;
                    a[i] -= 2;
                    answer++;
                }
                while (a[i] >= 2 && at < i) {
                    int current = Math.min(a[i] >> 1, a[at]);
                    a[i] -= 2 * current;
                    a[at] -= current;
                    answer += current;
                    if (a[at] > 0) {
                        break;
                    }
                    at++;
                }
                if (at == i) {
                    answer += a[i] / 3;
                    break;
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
}