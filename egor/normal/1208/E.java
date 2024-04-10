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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int w = in.readInt();
            int[][] a = new int[n][];
            for (int i = 0; i < n; i++) {
                a[i] = in.readIntArray(in.readInt());
            }
            long[] answer = new long[w];
            long base = 0;
            int[] next = new int[n];
            int[] last = new int[n];
            for (int i = 0; i < n - 1; i++) {
                next[i] = i + 1;
                last[i + 1] = i;
            }
            next[n - 1] = -1;
            last[0] = -1;
            int start = 0;
            int[] firstBack = ArrayUtils.createArray(w, -1);
            int[] nextBack = new int[n];
            int[][] queue = new int[n][];
            int[] front = new int[n];
            int[] back = new int[n];
            for (int i = 0; i < n; i++) {
                if (2 * a[i].length <= w) {
                    nextBack[i] = firstBack[w - a[i].length];
                    firstBack[w - a[i].length] = i;
                }
                queue[i] = new int[a[i].length];
            }
            for (int i = 0; i < w; i++) {
                for (int j = firstBack[i]; j != -1; j = nextBack[j]) {
                    if (start != -1) {
                        last[start] = j;
                    }
                    next[j] = start;
                    last[j] = -1;
                    start = j;
                    base -= Math.max(0, a[j][queue[j][front[j]]]);
                }
                answer[i] = base;
                for (int j = start; j != -1; j = next[j]) {
                    if (i < a[j].length) {
                        while (front[j] < back[j] && a[j][queue[j][back[j] - 1]] < a[j][i]) {
                            back[j]--;
                        }
                        queue[j][back[j]++] = i;
                    }
                    if (a[j].length - queue[j][front[j]] > w - i) {
                        front[j]++;
                    }
                    int add = a[j][queue[j][front[j]]];
                    if (add < 0 && (i >= a[j].length || w - i > a[j].length)) {
                        add = 0;
                    }
                    answer[i] += add;
                    if (i == a[j].length - 1 && 2 * a[j].length <= w) {
                        base += Math.max(0, a[j][queue[j][front[j]]]);
                        int p = last[j];
                        int q = next[j];
                        if (q != -1) {
                            last[q] = p;
                        }
                        if (p != -1) {
                            next[p] = q;
                        }
                        if (j == start) {
                            start = q;
                        }
                    }
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

    }

    static class ArrayUtils {
        public static int[] createArray(int count, int value) {
            int[] array = new int[count];
            Arrays.fill(array, value);
            return array;
        }

    }
}