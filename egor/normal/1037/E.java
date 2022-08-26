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
        E solver = new E();
        solver.solve(1, in, out);
        out.close();
    }

    static class E {
        int[] first;
        int[] next;
        int[] last;
        int[] to;
        int[] degree;
        int enabled;
        boolean[] good;
        boolean[] inQueue;
        int[] queue;
        int size;
        int k;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            k = in.readInt();
            int[] x = new int[m];
            int[] y = new int[m];
            in.readIntArrays(x, y);
            MiscUtils.decreaseByOne(x, y);
            first = ArrayUtils.createArray(n, -1);
            next = new int[2 * m];
            last = ArrayUtils.createArray(2 * m, -1);
            to = new int[2 * m];
            for (int i = 0; i < m; i++) {
                to[2 * i] = y[i];
                next[2 * i] = first[x[i]];
                first[x[i]] = 2 * i;
                if (next[2 * i] != -1) {
                    last[next[2 * i]] = 2 * i;
                }
                to[2 * i + 1] = x[i];
                next[2 * i + 1] = first[y[i]];
                first[y[i]] = 2 * i + 1;
                if (next[2 * i + 1] != -1) {
                    last[next[2 * i + 1]] = 2 * i + 1;
                }
            }
            degree = new int[n];
            for (int i = 0; i < m; i++) {
                degree[x[i]]++;
                degree[y[i]]++;
            }
            enabled = n;
            good = ArrayUtils.createArray(n, true);
            queue = new int[n];
            inQueue = new boolean[n];
            size = 0;
            for (int i = 0; i < n; i++) {
                if (degree[i] < k) {
                    queue[size++] = i;
                    inQueue[i] = true;
                }
            }
            processQueue();
            int[] answer = new int[m];
            answer[m - 1] = enabled;
            for (int i = m - 1; i > 0; i--) {
                if (good[x[i]] && good[y[i]]) {
                    removeEdge(2 * i);
                    removeEdge(2 * i + 1);
                    size = 0;
                    if (degree[x[i]] < k) {
                        queue[size++] = x[i];
                    }
                    if (degree[y[i]] < k) {
                        queue[size++] = y[i];
                    }
                    processQueue();
                }
                answer[i - 1] = enabled;
            }
            for (int i : answer) {
                out.printLine(i);
            }
        }

        private void removeEdge(int edge) {
            degree[to[edge ^ 1]]--;
            int n = next[edge];
            int l = last[edge];
            if (n != -1) {
                last[n] = l;
            }
            if (l != -1) {
                next[l] = n;
            } else {
                first[to[edge ^ 1]] = n;
            }
        }

        private void processQueue() {
            for (int i = 0; i < size; i++) {
                int vertex = queue[i];
                good[vertex] = false;
                enabled--;
                for (int j = first[vertex]; j != -1; j = next[j]) {
                    removeEdge(j ^ 1);
                    if (degree[to[j]] < k && !inQueue[to[j]]) {
                        queue[size++] = to[j];
                        inQueue[to[j]] = true;
                    }
                }
            }
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

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static class MiscUtils {
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class ArrayUtils {
        public static int[] createArray(int count, int value) {
            int[] array = new int[count];
            Arrays.fill(array, value);
            return array;
        }

        public static boolean[] createArray(int count, boolean value) {
            boolean[] array = new boolean[count];
            Arrays.fill(array, value);
            return array;
        }

    }
}