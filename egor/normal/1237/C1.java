import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.NavigableMap;
import java.util.TreeMap;
import java.util.Map;
import java.util.Map.Entry;
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
        TaskC1 solver = new TaskC1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC1 {
        NavigableMap<Integer, TaskC1.X> map = new TreeMap<>();

        void add(int x, int y, int z, int id) {
            if (!map.containsKey(x)) {
                map.put(x, new TaskC1.X());
            }
            map.get(x).add(y, z, id);
        }

        void remove(int x, int y, int z) {
            TaskC1.X val = map.get(x);
            val.remove(y, z);
            if (val.redundant()) {
                map.remove(x);
            }
        }

        int closest(int x, int y, int z) {
            Map.Entry<Integer, TaskC1.X> entry = map.floorEntry(x);
            if (entry == null) {
                entry = map.firstEntry();
            }
            TaskC1.X val = entry.getValue();
            int result = val.closest(y, z);
            if (val.redundant()) {
                map.remove(entry.getKey());
            }
            return result;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] x = new int[n];
            int[] y = new int[n];
            int[] z = new int[n];
            in.readIntArrays(x, y, z);
            for (int i = 0; i < n; i++) {
                add(x[i], y[i], z[i], i);
            }
            boolean[] done = new boolean[n];
            int[][] answer = new int[n / 2][2];
            int at = 0;
            for (int i = 0; i < n; i++) {
                if (done[i]) {
                    continue;
                }
                answer[at][0] = i + 1;
                remove(x[i], y[i], z[i]);
                int closest = closest(x[i], y[i], z[i]);
                answer[at++][1] = closest + 1;
                done[closest] = true;
            }
            for (int[] pair : answer) {
                out.printLine(pair);
            }
        }

        static class Y {
            NavigableMap<Integer, Integer> map = new TreeMap<>();

            void add(int z, int id) {
                map.put(z, id);
            }

            boolean redundant() {
                return map.isEmpty();
            }

            public void remove(int z) {
                map.remove(z);
            }

            public int closest(int z) {
                Map.Entry<Integer, Integer> entry = map.floorEntry(z);
                if (entry == null) {
                    entry = map.firstEntry();
                }
                int result = entry.getValue();
                map.remove(entry.getKey());
                return result;
            }

        }

        static class X {
            NavigableMap<Integer, TaskC1.Y> map = new TreeMap<>();

            void add(int y, int z, int id) {
                if (!map.containsKey(y)) {
                    map.put(y, new TaskC1.Y());
                }
                map.get(y).add(z, id);
            }

            boolean redundant() {
                return map.isEmpty();
            }

            public void remove(int y, int z) {
                TaskC1.Y val = map.get(y);
                val.remove(z);
                if (val.redundant()) {
                    map.remove(y);
                }
            }

            public int closest(int y, int z) {
                Map.Entry<Integer, TaskC1.Y> entry = map.floorEntry(y);
                if (entry == null) {
                    entry = map.firstEntry();
                }
                TaskC1.Y val = entry.getValue();
                int result = val.closest(z);
                if (val.redundant()) {
                    map.remove(entry.getKey());
                }
                return result;
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
}