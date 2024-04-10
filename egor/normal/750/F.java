import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;
import java.io.Writer;
import java.util.Collections;
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
        TaskF solver = new TaskF();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
//        in = new InputReader(System.in);
//        out = new OutputWriter(System.out);
            int h = in.readInt();
            IntList way = new IntArrayList();
            List<int[]> neighbors = new ArrayList<>();
            int vertex = 1;
            int questions = 0;
            while (true) {
                out.printLine("?", vertex);
                questions++;
                out.flush();
                int qty = in.readInt();
                int[] current = IOUtils.readIntArray(in, qty);
                if (qty == 2) {
                    out.printLine("!", vertex);
                    out.flush();
                    return;
                }
                way.add(vertex);
                neighbors.add(current);
                if (qty == 1) {
                    break;
                }
                vertex = current[0];
                if (way.size() > 1 && way.get(way.size() - 2) == vertex) {
                    vertex = current[1];
                }
            }
            way.inPlaceReverse();
            Collections.reverse(neighbors);
            vertex = neighbors.get(neighbors.size() - 1)[0];
            if (way.size() > 1 && way.get(way.size() - 2) == vertex) {
                vertex = neighbors.get(neighbors.size() - 1)[1];
            }
            while (true) {
                out.printLine("?", vertex);
                questions++;
                out.flush();
                int qty = in.readInt();
                int[] current = IOUtils.readIntArray(in, qty);
                if (qty == 2) {
                    out.printLine("!", vertex);
                    out.flush();
                    return;
                }
                way.add(vertex);
                neighbors.add(current);
                if (qty == 1) {
                    break;
                }
                vertex = current[0];
                if (way.size() > 1 && way.get(way.size() - 2) == vertex) {
                    vertex = current[1];
                }
            }
            int curHeight = (way.size() + 1) / 2;
            while (curHeight < 4) {
                int next = neighbors.get(curHeight - 1)[0];
                if (next == way.get(curHeight - 2) || next == way.get(curHeight)) {
                    next = neighbors.get(curHeight - 1)[1];
                }
                if (next == way.get(curHeight - 2) || next == way.get(curHeight)) {
                    next = neighbors.get(curHeight - 1)[2];
                }
                way = new IntArrayList(way.subList(0, curHeight));
                neighbors = new ArrayList<>(neighbors.subList(0, curHeight));
                vertex = next;
                while (true) {
                    out.printLine("?", vertex);
                    questions++;
                    out.flush();
                    int qty = in.readInt();
                    int[] current = IOUtils.readIntArray(in, qty);
                    if (qty == 2) {
                        out.printLine("!", vertex);
                        out.flush();
                        return;
                    }
                    way.add(vertex);
                    neighbors.add(current);
                    if (qty == 1) {
                        break;
                    }
                    vertex = current[0];
                    if (way.size() > 1 && way.get(way.size() - 2) == vertex) {
                        vertex = current[1];
                    }
                }
                curHeight = (way.size() + 1) / 2;
            }
            int next = neighbors.get(curHeight - 1)[0];
            if (next == way.get(curHeight - 2) || next == way.get(curHeight)) {
                next = neighbors.get(curHeight - 1)[1];
            }
            if (next == way.get(curHeight - 2) || next == way.get(curHeight)) {
                next = neighbors.get(curHeight - 1)[2];
            }
            int last = way.get(curHeight - 1);
            List<IntIntPair> level = new ArrayList<>();
            level.add(new IntIntPair(next, last));
            for (int i = 0; i < level.size(); i++) {
                IntIntPair pair = level.get(i);
                if (questions == 16) {
                    out.printLine("!", pair.first);
                    out.flush();
                    return;
                }
                out.printLine("?", pair.first);
                out.flush();
                int qty = in.readInt();
                questions++;
                int[] current = IOUtils.readIntArray(in, qty);
                if (qty == 2) {
                    out.printLine("!", pair.first);
                    out.flush();
                    return;
                }
                for (int j : current) {
                    if (j != pair.second) {
                        level.add(new IntIntPair(j, pair.first));
                    }
                }
            }
        }

    }

    static abstract class IntAbstractStream implements IntStream {

        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }


        public boolean equals(Object o) {
            if (!(o instanceof IntStream)) {
                return false;
            }
            IntStream c = (IntStream) o;
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }


        public int hashCode() {
            int result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }

    }

    static class IntIntPair implements Comparable<IntIntPair> {
        public final int first;
        public final int second;

        public IntIntPair(int first, int second) {
            this.first = first;
            this.second = second;
        }


        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            IntIntPair pair = (IntIntPair) o;

            return first == pair.first && second == pair.second;
        }


        public int hashCode() {
            int result = first;
            result = 31 * result + second;
            return result;
        }


        public String toString() {
            return "(" + first + "," + second + ")";
        }

        @SuppressWarnings({"unchecked"})
        public int compareTo(IntIntPair o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
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

        public void flush() {
            writer.flush();
        }

    }

    static class IntArrayList extends IntAbstractStream implements IntList {
        private int size;
        private int[] data;

        public IntArrayList() {
            this(3);
        }

        public IntArrayList(int capacity) {
            data = new int[capacity];
        }

        public IntArrayList(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public IntArrayList(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public IntArrayList(IntArrayList c) {
            size = c.size();
            data = c.data.clone();
        }

        public IntArrayList(int[] arr) {
            size = arr.length;
            data = arr.clone();
        }

        public int size() {
            return size;
        }

        public int get(int at) {
            if (at >= size) {
                throw new IndexOutOfBoundsException("at = " + at + ", size = " + size);
            }
            return data[at];
        }

        private void ensureCapacity(int capacity) {
            if (data.length >= capacity) {
                return;
            }
            capacity = Math.max(2 * data.length, capacity);
            data = Arrays.copyOf(data, capacity);
        }

        public void addAt(int index, int value) {
            ensureCapacity(size + 1);
            if (index > size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index);
            }
            data[index] = value;
            size++;
        }

        public void removeAt(int index) {
            if (index >= size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size - 1) {
                System.arraycopy(data, index + 1, data, index, size - index - 1);
            }
            size--;
        }

        public void set(int index, int value) {
            if (index >= size) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            data[index] = value;
        }

    }

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void set(int index, int value);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

        default public void swap(int first, int second) {
            if (first == second) {
                return;
            }
            int temp = get(first);
            set(first, get(second));
            set(second, temp);
        }

        default public IntIterator intIterator() {
            return new IntIterator() {
                private int at;
                private boolean removed;

                public int value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && at < size();
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }


        default public void add(int value) {
            addAt(size(), value);
        }

        default public void inPlaceReverse() {
            for (int i = 0, j = size() - 1; i < j; i++, j--) {
                swap(i, j);
            }
        }

        default public IntList subList(final int from, final int to) {
            return new IntList() {
                private final int shift;
                private final int size;

                {
                    if (from < 0 || from > to || to > IntList.this.size()) {
                        throw new IndexOutOfBoundsException("from = " + from + ", to = " + to + ", size = " + size());
                    }
                    shift = from;
                    size = to - from;
                }

                public int size() {
                    return size;
                }

                public int get(int at) {
                    if (at < 0 || at >= size) {
                        throw new IndexOutOfBoundsException("at = " + at + ", size = " + size());
                    }
                    return IntList.this.get(at + shift);
                }

                public void addAt(int index, int value) {
                    throw new UnsupportedOperationException();
                }

                public void removeAt(int index) {
                    throw new UnsupportedOperationException();
                }

                public void set(int at, int value) {
                    if (at < 0 || at >= size) {
                        throw new IndexOutOfBoundsException("at = " + at + ", size = " + size());
                    }
                    IntList.this.set(at + shift, value);
                }

                public IntList compute() {
                    return new IntArrayList(this);
                }
            };
        }

    }

    static interface IntReversableCollection extends IntCollection {
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

    static interface IntCollection extends IntStream {
        public int size();

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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

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

        public String next() {
            return readString();
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
}