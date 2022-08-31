import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
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
            int b = in.readInt();
            int[] t = new int[n];
            int[] d = new int[n];
            IOUtils.readIntArrays(in, t, d);
            long[] answer = new long[n];
            IntQueue queue = new IntArrayQueue(b + 1);
            for (int i = 0; i < n; i++) {
                while (!queue.isEmpty() && answer[queue.peek()] <= t[i]) {
                    int last = queue.poll();
                    if (!queue.isEmpty()) {
                        answer[queue.peek()] = answer[last] + d[queue.peek()];
                    }
                }
                if (queue.size() <= b) {
                    if (queue.isEmpty()) {
                        answer[i] = t[i] + d[i];
                    }
                    queue.add(i);
                } else {
                    answer[i] = -1;
                }
            }
            while (!queue.isEmpty()) {
                int last = queue.poll();
                if (!queue.isEmpty()) {
                    answer[queue.peek()] = answer[last] + d[queue.peek()];
                }
            }
            out.printLine(answer);
        }

    }

    static class IOUtils {
        public static void readIntArrays(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
                }
            }
        }

    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        public IntIterator intIterator();

        default public Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                private IntIterator it = intIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Integer next() {
                    int result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(IntStream c) {
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                int i = it.value();
                int j = jt.value();
                if (i < j) {
                    return -1;
                } else if (i > j) {
                    return 1;
                }
                it.advance();
                jt.advance();
            }
            if (it.isValid()) {
                return 1;
            }
            if (jt.isValid()) {
                return -1;
            }
            return 0;
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

    static interface IntQueue extends IntCollection {
        public int peek();

        public int poll();

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static class IntArrayQueue implements IntQueue {
        private int[] data;
        private int from;
        private int to;

        public IntArrayQueue(int capacity) {
            data = new int[Integer.highestOneBit(capacity) << 1];
        }

        public IntArrayQueue() {
            this(3);
        }

        public IntArrayQueue(int[] array) {
            this(array.length);
            to = array.length;
            System.arraycopy(array, 0, data, 0, to);
        }

        public IntArrayQueue(IntStream s) {
            addAll(s);
        }

        public IntArrayQueue(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public int size() {
            return (to - from) & (data.length - 1);
        }

        public void add(int v) {
            ensureCapacity(size() + 1);
            data[to++] = v;
            to &= data.length - 1;
        }

        public int poll() {
            if (from == to) {
                throw new NoSuchElementException();
            }
            int result = data[from++];
            from &= data.length - 1;
            return result;
        }

        public int peek() {
            if (from == to) {
                throw new NoSuchElementException();
            }
            return data[from];
        }

        public IntIterator intIterator() {
            return new IntIterator() {
                private int at = from;

                public int value() {
                    if (at == to) {
                        throw new NoSuchElementException();
                    }
                    return data[at];
                }

                public boolean advance() {
                    if (!isValid()) {
                        throw new NoSuchElementException();
                    }
                    at++;
                    at &= data.length - 1;
                    return isValid();
                }

                public boolean isValid() {
                    return at != to;
                }

                public void remove() {
                    throw new UnsupportedOperationException();
                }
            };
        }

        private void ensureCapacity(int capacity) {
            if (data.length <= capacity) {
                int[] newData = new int[Integer.highestOneBit(capacity) << 1];
                if (from <= to) {
                    System.arraycopy(data, from, newData, 0, size());
                } else {
                    System.arraycopy(data, from, newData, 0, data.length - from);
                    System.arraycopy(data, 0, newData, data.length - from, to);
                }
                to = size();
                from = 0;
                data = newData;
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

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

    static interface IntCollection extends IntStream {
        public int size();

        default public boolean isEmpty() {
            return size() == 0;
        }

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }
}