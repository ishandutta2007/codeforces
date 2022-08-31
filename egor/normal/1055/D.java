import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        DRefaktoring solver = new DRefaktoring();
        solver.solve(1, in, out);
        out.close();
    }

    static class DRefaktoring {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            String[] w = in.readStringArray(n);
            String[] w1 = in.readStringArray(n);
            boolean[] change = new boolean[n];
            int[] start = new int[n];
            int[] end = new int[n];
            String from = null;
            String to = null;
            for (int i = 0; i < n; i++) {
                if (!w[i].equals(w1[i])) {
                    change[i] = true;
                    start[i] = -1;
                    for (int j = 0; j < w[i].length(); j++) {
                        char c = w[i].charAt(j);
                        char c1 = w1[i].charAt(j);
                        if (c != c1) {
                            if (start[i] == -1) {
                                start[i] = j;
                            }
                            end[i] = j + 1;
                        }
                    }
                    if (from == null) {
                        from = w[i].substring(start[i], end[i]);
                        to = w1[i].substring(start[i], end[i]);
                    } else {
                        if (!from.equals(w[i].substring(start[i], end[i])) || !to.equals(w1[i].substring(start[i],
                                end[i]))) {
                            out.printLine("NO");
                            return;
                        }
                    }
                }
            }
            while (true) {
                boolean good = true;
                char c = 0;
                for (int i = 0; i < n; i++) {
                    if (change[i]) {
                        if (start[i] == 0) {
                            good = false;
                            break;
                        }
                        if (c == 0) {
                            c = w[i].charAt(start[i] - 1);
                        } else {
                            if (c != w[i].charAt(start[i] - 1)) {
                                good = false;
                                break;
                            }
                        }
                    }
                }
                if (!good) {
                    break;
                }
                for (int i = 0; i < n; i++) {
                    if (change[i]) {
                        start[i]--;
                    }
                }
            }
            while (true) {
                boolean good = true;
                char c = 0;
                for (int i = 0; i < n; i++) {
                    if (change[i]) {
                        if (end[i] == w[i].length()) {
                            good = false;
                            break;
                        }
                        if (c == 0) {
                            c = w[i].charAt(end[i]);
                        } else {
                            if (c != w[i].charAt(end[i])) {
                                good = false;
                                break;
                            }
                        }
                    }
                }
                if (!good) {
                    break;
                }
                for (int i = 0; i < n; i++) {
                    if (change[i]) {
                        end[i]++;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (change[i]) {
                    from = w[i].substring(start[i], end[i]);
                    to = w1[i].substring(start[i], end[i]);
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                int at = StringUtils.indexOf(w[i], from);
                if (change[i]) {
                    if (at != start[i]) {
                        out.printLine("NO");
                        return;
                    }
                } else if (at != -1) {
                    out.printLine("NO");
                    return;
                }
            }
            out.printLine("YES");
            out.printLine(from);
            out.printLine(to);
        }

    }

    static class StringUtils {
        public static int[] zAlgorithm(CharSequence s) {
            int length = s.length();
            int[] z = new int[length];
            int left = 0, right = 0;
            for (int i = 1; i < length; i++) {
                if (i > right) {
                    int j;
                    //noinspection StatementWithEmptyBody
                    for (j = 0; i + j < length && s.charAt(i + j) == s.charAt(j); j++) {
                        ;
                    }
                    z[i] = j;
                    left = i;
                    right = i + j - 1;
                } else if (z[i - left] < right - i + 1) {
                    z[i] = z[i - left];
                } else {
                    int j;
                    //noinspection StatementWithEmptyBody
                    for (j = 1; right + j < length && s.charAt(right + j) == s.charAt(right - i + j); j++) {
                        ;
                    }
                    z[i] = right - i + j;
                    left = i;
                    right = right + j - 1;
                }
            }
            return z;
        }

        public static int indexOf(final String s, final String target) {
            int[] z = zAlgorithm(new CharSequence() {
                public int length() {
                    return s.length() + target.length();
                }

                public char charAt(int index) {
                    if (index < target.length()) {
                        return target.charAt(index);
                    }
                    return s.charAt(index - target.length());
                }

                public CharSequence subSequence(int start, int end) {
                    throw new UnsupportedOperationException();
                }
            });
            for (int i = target.length(); i < z.length; i++) {
                if (z[i] >= target.length()) {
                    return i - target.length();
                }
            }
            return -1;
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

        public String[] readStringArray(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
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
}