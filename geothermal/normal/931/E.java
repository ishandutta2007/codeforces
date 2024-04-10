import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            StringBuilder s = new StringBuilder(in.nextString());
            ArrayList<ArrayList<String>> data = new ArrayList<>();
            for (int i = 0; i < 26; i++) data.add(new ArrayList<>());

            for (int i = 0; i < s.length(); i++) {
                data.get(s.charAt(0) - 97).add(s.toString());
                char c = s.charAt(0);
                s = new StringBuilder(s.substring(1));
                s.append(c);
            }

            double count = 0;
            for (int i = 0; i < 26; i++) {
                int[][] used = new int[s.length()][26];
                for (String str : data.get(i)) {
                    for (int j = 0; j < s.length(); j++) {

                        used[j][str.charAt(j) - 97]++;
                    }
                }
                double best = 0;
                for (int j = 0; j < used.length; j++) {
                    int num = 0;
                    for (int k = 0; k < 26; k++) if (used[j][k] == 1) num++;
                    best = Math.max(best, (double) num / s.length());
                }
                count += best;
            }


            out.printLine(count);

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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void printLine(double i) {
            writer.println(i);
        }

        public void close() {
            writer.close();
        }

    }
}