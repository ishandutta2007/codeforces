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
        DForeigner solver = new DForeigner();
        solver.solve(1, in, out);
        out.close();
    }

    static class DForeigner {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int[][] shift = new int[11][11];
            for (int i = 0; i < 11; i++) {
                for (int j = 0; j < 11; j++) {
                    for (int k = i; k != j; k = (k + 1) % 11) {
                        shift[i][j] += k;
                    }
                    shift[i][j] %= 11;
                }
            }
            String s = in.readString();
            int[][] length = new int[2][11];
            int[][] next = new int[2][11];
            long answer = 0;
            for (int i = s.length() - 1; i >= 0; i--) {
                int digit = s.charAt(i) - '0';
                if (digit != 0) {
                    answer += length[1][digit] + 1;
                }
                for (int j = 0; j < 2; j++) {
                    for (int current = 0; current < 11; current++) {
                        if (digit >= current) {
                            next[j][current] = 0;
                            continue;
                        }
                        int first = j * 10;
                        int nFirst = (1 - j) * 10;
                        int nCurrent = (nFirst + shift[first][current] + digit) % 11;
                        next[j][current] = 1 + length[1 - j][nCurrent];
                    }
                }
                int[][] temp = length;
                length = next;
                next = temp;
            }
            out.printLine(answer);
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

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
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

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }
}