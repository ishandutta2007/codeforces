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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] x = new int[n];
            int[] y = new int[n];
            in.readIntArrays(x, y);
            char[] s = in.readCharArray(n - 2);
            int last = 0;
            for (int i = 1; i < n; i++) {
                if (x[i] < x[last] || x[i] == x[last] && y[i] < y[last]) {
                    last = i;
                }
            }
            int[] answer = new int[n];
            answer[0] = last + 1;
            double angle = -Math.PI / 2;
            boolean[] used = new boolean[n];
            used[last] = true;
            for (int i = 1; i < n - 1; i++) {
                if (s[i - 1] == 'L') {
                    double minAngle = angle + Math.PI;
                    int at = -1;
                    for (int j = 0; j < n; j++) {
                        if (used[j]) {
                            continue;
                        }
                        double cur = Math.atan2(y[j] - y[last], x[j] - x[last]);
                        while (cur < angle) {
                            cur += 2 * Math.PI;
                        }
                        if (cur < minAngle) {
                            minAngle = cur;
                            at = j;
                        }
                    }
                    answer[i] = at + 1;
                    used[at] = true;
                    last = at;
                    angle = minAngle;
                } else {
                    double maxAngle = angle;
                    int at = -1;
                    for (int j = 0; j < n; j++) {
                        if (used[j]) {
                            continue;
                        }
                        double cur = Math.atan2(y[j] - y[last], x[j] - x[last]);
                        while (cur < angle) {
                            cur += 2 * Math.PI;
                        }
                        if (cur > maxAngle) {
                            maxAngle = cur;
                            at = j;
                        }
                    }
                    answer[i] = at + 1;
                    used[at] = true;
                    last = at;
                    angle = maxAngle - Math.PI;
                }
                while (angle < -Math.PI / 2) {
                    angle += 2 * Math.PI;
                }
            }
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    answer[n - 1] = i + 1;
                    break;
                }
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

        public char[] readCharArray(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public void readIntArrays(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}