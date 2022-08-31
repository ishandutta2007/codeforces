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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int maxW = in.readInt();
            int[] w = IOUtils.readIntArray(in, n);
            int[] b = IOUtils.readIntArray(in, n);
            int[] x = new int[m];
            int[] y = new int[m];
            IOUtils.readIntArrays(in, x, y);
            MiscUtils.decreaseByOne(x, y);
            IndependentSetSystem setSystem = new RecursiveIndependentSetSystem(n);
            for (int i = 0; i < m; i++) {
                setSystem.join(x[i], y[i]);
            }
            int[] answer = new int[maxW + 1];
            int[] next = new int[maxW + 1];
            for (int i = 0; i < n; i++) {
                if (setSystem.get(i) != i) {
                    continue;
                }
                System.arraycopy(answer, 0, next, 0, maxW + 1);
                int sumW = 0;
                int sumB = 0;
                for (int j = 0; j < n; j++) {
                    if (setSystem.get(j) == i) {
                        sumW += w[j];
                        sumB += b[j];
                        apply(answer, next, w[j], b[j]);
                    }
                }
                apply(answer, next, sumW, sumB);
                int[] temp = answer;
                answer = next;
                next = temp;
            }
            out.printLine(answer[maxW]);
        }

        private void apply(int[] answer, int[] next, int w, int b) {
            for (int i = answer.length - 1; i >= w; i--) {
                next[i] = Math.max(next[i], answer[i - w] + b);
            }
        }

    }

    static interface IndependentSetSystem {
        public boolean join(int first, int second);

        public int get(int index);

        public static interface Listener {
            public void joined(int joinedRoot, int root);

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

        public static void readIntArrays(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
                }
            }
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

    static class RecursiveIndependentSetSystem implements IndependentSetSystem {
        private final int[] color;
        private final int[] rank;
        private int setCount;
        private IndependentSetSystem.Listener listener;

        public RecursiveIndependentSetSystem(int size) {
            color = new int[size];
            rank = new int[size];
            for (int i = 0; i < size; i++) {
                color[i] = i;
            }
            setCount = size;
        }

        public RecursiveIndependentSetSystem(RecursiveIndependentSetSystem other) {
            color = other.color.clone();
            rank = other.rank.clone();
            setCount = other.setCount;
        }

        public boolean join(int first, int second) {
            first = get(first);
            second = get(second);
            if (first == second) {
                return false;
            }
            if (rank[first] < rank[second]) {
                int temp = first;
                first = second;
                second = temp;
            } else if (rank[first] == rank[second]) {
                rank[first]++;
            }
            setCount--;
            color[second] = first;
            if (listener != null) {
                listener.joined(second, first);
            }
            return true;
        }

        public int get(int index) {
            int start = index;
            while (color[index] != index) {
                index = color[index];
            }
            while (start != index) {
                int next = color[start];
                color[start] = index;
                start = next;
            }
            return index;
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
}