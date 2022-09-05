import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            ArrayList<ArrayList<Integer>> data = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String s = in.nextString();
                data.add(new ArrayList<>());
                for (int j = 0; j < m; j++) {
                    if (s.charAt(j) == '1') {
                        data.get(i).add(j);
                    }
                }
            }

            int[][] minDp = new int[n][k + 1];
            for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) minDp[i][j] = 501;
            for (int i = 0; i < n; i++) {
                for (int j = data.get(i).size(); j <= k; j++) minDp[i][j] = 0;
                for (int j = 0; j < data.get(i).size(); j++) {
                    for (int x = j; x < data.get(i).size(); x++) {
                        int numSkip = j + data.get(i).size() - 1 - x;
                        if (numSkip <= k) {
                            minDp[i][numSkip] = Math.min(minDp[i][numSkip], data.get(i).get(x) - data.get(i).get(j) + 1);
                        }
                    }
                }
            }
            int[] dpTotals = Arrays.copyOf(minDp[0], k + 1);
            for (int i = 1; i < n; i++) {
                int[] dpOld = Arrays.copyOf(dpTotals, k + 1);
                for (int j = 0; j <= k; j++) dpTotals[j] = Integer.MAX_VALUE;
                for (int j = 0; j <= k; j++) {
                    for (int x = 0; j + x <= k; x++) {
                        dpTotals[j + x] = Math.min(dpTotals[j + x], dpOld[j] + minDp[i][x]);
                    }

                }
            }

            out.printLine(dpTotals[k]);
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

        public void printLine(int i) {
            writer.println(i);
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

        public String nextString() {
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
}