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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] p = IOUtils.readIntArray(in, n);
            MiscUtils.decreaseByOne(p);
            IndependentSetSystem setSystem = new RecursiveIndependentSetSystem(n);
            for (int i = 0; i < n; i++) {
                setSystem.join(i, p[i]);
            }
            out.printLine(setSystem.getSetCount());
        }

    }

    static interface IndependentSetSystem {
        public boolean join(int first, int second);

        public int getSetCount();

        public static interface Listener {
            public void joined(int joinedRoot, int root);

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

        public int getSetCount() {
            return setCount;
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