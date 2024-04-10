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
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.SortedMap;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int i = in.readInt();
            int[] a = in.readIntArray(n);
            int memory = 8 * i;
            memory /= n;
            if (memory >= 20) {
                out.printLine(0);
                return;
            }
            memory = 1 << memory;
            NavigableMap<Integer, Integer> map = new CPPTreeMap<>(() -> 0);
            for (int j : a) {
                map.put(j, map.get(j) + 1);
            }
            int[] all = new int[map.size()];
            int at = 0;
            for (int j : map.values()) {
                all[at++] = j;
            }
            if (all.length <= memory) {
                out.printLine(0);
                return;
            }
            long[] sums = ArrayUtils.partialSums(all);
            long answer = 0;
            for (int j = memory; j <= all.length; j++) {
                answer = Math.max(answer, sums[j] - sums[j - memory]);
            }
            out.printLine(n - answer);
        }

    }

    static interface Factory<V> {
        public V create();

    }

    static class CPPTreeMap<K, V> extends TreeMap<K, V> {
        private final Factory<V> defaultValueFactory;

        public CPPTreeMap(Factory<V> defaultValueFactory) {
            this.defaultValueFactory = defaultValueFactory;
        }

        public V get(Object key) {
            if (containsKey(key)) {
                return super.get(key);
            }
            V value = defaultValueFactory.create();
            try {
                //noinspection unchecked
                super.put((K) key, value);
                return value;
            } catch (ClassCastException e) {
                return value;
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

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static class ArrayUtils {
        public static long[] partialSums(int[] array) {
            long[] result = new long[array.length + 1];
            for (int i = 0; i < array.length; i++) {
                result[i + 1] = result[i] + array[i];
            }
            return result;
        }

    }
}