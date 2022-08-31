import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;
import java.io.Writer;
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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int[] sx = new int[m];
            int[] sy = new int[m];
            in.readIntArrays(sx, sy);
            int[] fx = new int[m];
            int[] fy = new int[m];
            in.readIntArrays(fx, fy);
            if (n == 1) {
                out.printLine(0);
                return;
            }
            List<Pair<IntIntPair, IntIntPair>> answer = new ArrayList<>();
            if (n == 2) {
                Map<IntIntPair, IntIntPair> moves = new HashMap<>();
                moves.put(new IntIntPair(1, 1), new IntIntPair(1, 2));
                moves.put(new IntIntPair(1, 2), new IntIntPair(2, 2));
                moves.put(new IntIntPair(2, 2), new IntIntPair(2, 1));
                moves.put(new IntIntPair(2, 1), new IntIntPair(1, 1));
                while (sx[0] != fx[0] || sy[0] != fy[0]) {
                    IntIntPair move = moves.get(new IntIntPair(sx[0], sy[0]));
                    if (m == 2 && sx[1] == move.first && sy[1] == move.second) {
                        IntIntPair move2 = moves.get(move);
                        answer.add(Pair.makePair(move, move2));
                        sx[1] = move2.first;
                        sy[1] = move2.second;
                    }
                    answer.add(Pair.makePair(new IntIntPair(sx[0], sy[0]), move));
                    sx[0] = move.first;
                    sy[0] = move.second;
                }
                if (m == 2) {
                    while (sx[1] != fx[1] || sy[1] != fy[1]) {
                        IntIntPair move = moves.get(new IntIntPair(sx[1], sy[1]));
                        answer.add(Pair.makePair(new IntIntPair(sx[1], sy[1]), move));
                        sx[1] = move.first;
                        sy[1] = move.second;
                    }
                }
                out.printLine(answer.size());
                for (Pair<IntIntPair, IntIntPair> pair : answer) {
                    out.printLine(pair.first.first, pair.first.second, pair.second.first, pair.second.second);
                }
                return;
            }
            boolean invert = false;
            int sum = (int) (ArrayUtils.sumArray(sx) - m + n * m - ArrayUtils.sumArray(fx));
            if (sum > (n - 1) * m) {
                invert = true;
                for (int i = 0; i < m; i++) {
                    sx[i] = n + 1 - sx[i];
                    fx[i] = n + 1 - fx[i];
                }
            }
            int current = 1;
            IntList firstRow = new IntArrayList();
            IntList other = new IntArrayList();
            for (int i = 0; i < m; i++) {
                if (sx[i] == 1) {
                    firstRow.add(i);
                } else {
                    other.add(i);
                }
            }
            firstRow.sort((a, b) -> sy[a] - sy[b]);
            for (int i : firstRow) {
                while (sy[i] > current) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i], sy[i] - 1)));
                    sy[i]--;
                }
                current++;
            }
            other.sort((a, b) -> sx[a] == sx[b] ? sy[b] - sy[a] : sx[a] - sx[b]);
            for (int i : other) {
                while (sy[i] < current) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i], sy[i] + 1)));
                    sy[i]++;
                }
                while (sx[i] > 1) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i] - 1, sy[i])));
                    sx[i]--;
                }
                while (sy[i] > current) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i], sy[i] - 1)));
                    sy[i]--;
                }
                current++;
            }
            int[] all = ArrayUtils.createOrder(m);
            ArrayUtils
                    .sort(all, (a, b) -> fx[a] != fx[b] ? fx[a] - fx[b] : (fx[a] == n ? fy[a] - fy[b] : fy[b] - fy[a]));
            current = n - m + 1;
            for (int i : all) {
                answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i] + 1, sy[i])));
                sx[i]++;
                while (sy[i] < current) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i], sy[i] + 1)));
                    sy[i]++;
                }
                while (sy[i] > current) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i], sy[i] - 1)));
                    sy[i]--;
                }
                while (sx[i] < n) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i] + 1, sy[i])));
                    sx[i]++;
                }
                current++;
            }
            IntList lastRow = new IntArrayList();
            other = new IntArrayList();
            for (int i = 0; i < m; i++) {
                if (fx[i] == n) {
                    lastRow.add(i);
                } else {
                    other.add(i);
                }
            }
            other.sort((a, b) -> fx[a] != fx[b] ? fx[a] - fx[b] : fy[b] - fy[a]);
            for (int i : other) {
                while (sy[i] > fy[i]) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i], sy[i] - 1)));
                    sy[i]--;
                }
                answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i] - 1, sy[i])));
                sx[i]--;
                while (sy[i] < fy[i]) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i], sy[i] + 1)));
                    sy[i]++;
                }
                while (sx[i] > fx[i]) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i] - 1, sy[i])));
                    sx[i]--;
                }
            }
            lastRow.sort((a, b) -> fy[a] - fy[b]);
            for (int i : lastRow) {
                while (sy[i] > fy[i]) {
                    answer.add(Pair.makePair(new IntIntPair(sx[i], sy[i]), new IntIntPair(sx[i], sy[i] - 1)));
                    sy[i]--;
                }
            }
            out.printLine(answer.size());
            for (Pair<IntIntPair, IntIntPair> pair : answer) {
                if (invert) {
                    out.printLine(n + 1 - pair.first.first, pair.first.second, n + 1 - pair.second.first,
                            pair.second.second);
                } else {
                    out.printLine(pair.first.first, pair.first.second, pair.second.first, pair.second.second);
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

    static interface IntCollection extends IntStream {
        public int size();

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public int[] toArray() {
            int size = size();
            int[] array = new int[size];
            int i = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                array[i++] = it.value();
            }
            return array;
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static class Range {
        public static IntList range(int from, int to) {
            int[] result = new int[Math.abs(from - to)];
            int current = from;
            if (from <= to) {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current++;
                }
            } else {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current--;
                }
            }
            return new IntArray(result);
        }

    }

    static interface IntComparator {
        public int compare(int first, int second);

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

        default public long sum() {
            long result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result += it.value();
            }
            return result;
        }

    }

    static class ArrayUtils {
        public static long sumArray(int[] array) {
            return new IntArray(array).sum();
        }

        public static int[] range(int from, int to) {
            return Range.range(from, to).toArray();
        }

        public static int[] createOrder(int size) {
            return range(0, size);
        }

        public static int[] sort(int[] array, IntComparator comparator) {
            return sort(array, 0, array.length, comparator);
        }

        public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
            if (from == 0 && to == array.length) {
                new IntArray(array).sort(comparator);
            } else {
                new IntArray(array).subList(from, to).sort(comparator);
            }
            return array;
        }

    }

    static class Sorter {
        private static final int INSERTION_THRESHOLD = 16;

        private Sorter() {
        }

        public static void sort(IntList list, IntComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
            if (to - from < INSERTION_THRESHOLD) {
                insertionSort(list, from, to, comparator);
                return;
            }
            if (remaining == 0) {
                heapSort(list, from, to, comparator);
                return;
            }
            remaining--;
            int pivotIndex = (from + to) >> 1;
            int pivot = list.get(pivotIndex);
            list.swap(pivotIndex, to);
            int storeIndex = from;
            int equalIndex = to;
            for (int i = from; i < equalIndex; i++) {
                int value = comparator.compare(list.get(i), pivot);
                if (value < 0) {
                    list.swap(storeIndex++, i);
                } else if (value == 0) {
                    list.swap(--equalIndex, i--);
                }
            }
            quickSort(list, from, storeIndex - 1, remaining, comparator);
            for (int i = equalIndex; i <= to; i++) {
                list.swap(storeIndex++, i);
            }
            quickSort(list, storeIndex, to, remaining, comparator);
        }

        private static void heapSort(IntList list, int from, int to, IntComparator comparator) {
            for (int i = (to + from - 1) >> 1; i >= from; i--) {
                siftDown(list, i, to, comparator, from);
            }
            for (int i = to; i > from; i--) {
                list.swap(from, i);
                siftDown(list, from, i - 1, comparator, from);
            }
        }

        private static void siftDown(IntList list, int start, int end, IntComparator comparator, int delta) {
            int value = list.get(start);
            while (true) {
                int child = ((start - delta) << 1) + 1 + delta;
                if (child > end) {
                    return;
                }
                int childValue = list.get(child);
                if (child + 1 <= end) {
                    int otherValue = list.get(child + 1);
                    if (comparator.compare(otherValue, childValue) > 0) {
                        child++;
                        childValue = otherValue;
                    }
                }
                if (comparator.compare(value, childValue) >= 0) {
                    return;
                }
                list.swap(start, child);
                start = child;
            }
        }

        private static void insertionSort(IntList list, int from, int to, IntComparator comparator) {
            for (int i = from + 1; i <= to; i++) {
                int value = list.get(i);
                for (int j = i - 1; j >= from; j--) {
                    if (comparator.compare(list.get(j), value) <= 0) {
                        break;
                    }
                    list.swap(j, j + 1);
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

    static class Pair<U, V> implements Comparable<Pair<U, V>> {
        public final U first;
        public final V second;

        public static <U, V> Pair<U, V> makePair(U first, V second) {
            return new Pair<U, V>(first, second);
        }

        private Pair(U first, V second) {
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

            Pair pair = (Pair) o;

            return !(first != null ? !first.equals(pair.first) : pair.first != null) &&
                    !(second != null ? !second.equals(pair.second) : pair.second != null);
        }

        public int hashCode() {
            int result = first != null ? first.hashCode() : 0;
            result = 31 * result + (second != null ? second.hashCode() : 0);
            return result;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) first).compareTo(o.first);
            if (value != 0) {
                return value;
            }
            return ((Comparable<V>) second).compareTo(o.second);
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

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

        default public IntList sort(IntComparator comparator) {
            Sorter.sort(this, comparator);
            return this;
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

        public int[] toArray() {
            return Arrays.copyOf(data, size);
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

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static class IntArray extends IntAbstractStream implements IntList {
        private int[] data;

        public IntArray(int[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public int get(int at) {
            return data[at];
        }

        public void addAt(int index, int value) {
            throw new UnsupportedOperationException();
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

        public void set(int index, int value) {
            data[index] = value;
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

        public int compareTo(IntIntPair o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }

    static interface IntReversableCollection extends IntCollection {
    }
}