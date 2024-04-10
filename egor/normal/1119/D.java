import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        DFretsOnFire solver = new DFretsOnFire();
        solver.solve(1, in, out);
        out.close();
    }

    static class DFretsOnFire {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            long[] s = in.readLongArray(n);
            new LongArray(s).sort();
            s = ArrayUtils.unique(s);
            long[] diff = new long[s.length - 1];
            for (int i = 0; i < diff.length; i++) {
                diff[i] = s[i + 1] - s[i];
            }
            new LongArray(diff).sort();
            LongIntervalTree tree = new SumIntervalTree(diff);
            int q = in.readInt();
            long[] answer = new long[q];
            for (int i = 0; i < q; i++) {
                long l = in.readLong();
                long r = in.readLong();
                long len = r - l + 1;
                int at = Arrays.binarySearch(diff, len);
                if (at < 0) {
                    at = -at - 1;
                }
                answer[i] = tree.query(0, at - 1) + (diff.length - at + 1) * len;
            }
            out.printLine(answer);
        }

    }

    static class SumIntervalTree extends LongIntervalTree {
        private final long[] array;

        public SumIntervalTree(int size) {
            super(size);
            array = null;
        }

        public SumIntervalTree(long[] array) {
            super(array.length, false);
            this.array = array;
            init();
        }

        protected long initValue(int index) {
            if (array == null) {
                return 0;
            }
            return array[index];
        }

        protected long joinValue(long left, long right) {
            return left + right;
        }

        protected long joinDelta(long was, long delta) {
            return was + delta;
        }

        protected long accumulate(long value, long delta, int length) {
            return value + delta * length;
        }

        protected long neutralValue() {
            return 0;
        }

        protected long neutralDelta() {
            return 0;
        }

    }

    static class LongArray extends LongAbstractStream implements LongList {
        private long[] data;

        public LongArray(long[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public long get(int at) {
            return data[at];
        }

        public void addAt(int index, long value) {
            throw new UnsupportedOperationException();
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

        public void set(int index, long value) {
            data[index] = value;
        }

    }

    static interface LongComparator {
        public static final LongComparator DEFAULT = (first, second) -> {
            if (first < second) {
                return -1;
            }
            if (first > second) {
                return 1;
            }
            return 0;
        };

        public int compare(long first, long second);

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

    static interface LongList extends LongReversableCollection {
        public abstract long get(int index);

        public abstract void set(int index, long value);

        public abstract void addAt(int index, long value);

        public abstract void removeAt(int index);

        default public void swap(int first, int second) {
            if (first == second) {
                return;
            }
            long temp = get(first);
            set(first, get(second));
            set(second, temp);
        }

        default public LongIterator longIterator() {
            return new LongIterator() {
                private int at;
                private boolean removed;

                public long value() {
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

        default public void add(long value) {
            addAt(size(), value);
        }

        default public LongList sort() {
            sort(LongComparator.DEFAULT);
            return this;
        }

        default public LongList sort(LongComparator comparator) {
            Sorter.sort(this, comparator);
            return this;
        }

        default LongList unique() {
            long last = Long.MIN_VALUE;
            LongList result = new LongArrayList();
            int size = size();
            for (int i = 0; i < size; i++) {
                long current = get(i);
                if (current != last) {
                    result.add(current);
                    last = current;
                }
            }
            return result;
        }

    }

    static interface LongStream extends Iterable<Long>, Comparable<LongStream> {
        public LongIterator longIterator();

        default public Iterator<Long> iterator() {
            return new Iterator<Long>() {
                private LongIterator it = longIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Long next() {
                    long result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(LongStream c) {
            LongIterator it = longIterator();
            LongIterator jt = c.longIterator();
            while (it.isValid() && jt.isValid()) {
                long i = it.value();
                long j = jt.value();
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

    static interface LongIterator {
        public long value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static abstract class IntervalTree {
        protected int size;

        protected IntervalTree(int size) {
            this(size, true);
        }

        public IntervalTree(int size, boolean shouldInit) {
            this.size = size;
            int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
            initData(size, nodeCount);
            if (shouldInit) {
                init();
            }
        }

        protected abstract void initData(int size, int nodeCount);

        protected abstract void initAfter(int root, int left, int right, int middle);

        protected abstract void initBefore(int root, int left, int right, int middle);

        protected abstract void initLeaf(int root, int index);

        protected abstract long queryPostProcess(int root, int left, int right, int from, int to, int middle,
                                                 long leftResult, long rightResult);

        protected abstract void queryPreProcess(int root, int left, int right, int from, int to, int middle);

        protected abstract long queryFull(int root, int left, int right, int from, int to);

        protected abstract long emptySegmentResult();

        public void init() {
            if (size == 0) {
                return;
            }
            init(0, 0, size - 1);
        }

        private void init(int root, int left, int right) {
            if (left == right) {
                initLeaf(root, left);
            } else {
                int middle = (left + right) >> 1;
                initBefore(root, left, right, middle);
                init(2 * root + 1, left, middle);
                init(2 * root + 2, middle + 1, right);
                initAfter(root, left, right, middle);
            }
        }

        public long query(int from, int to) {
            return query(0, 0, size - 1, from, to);
        }

        protected long query(int root, int left, int right, int from, int to) {
            if (left > to || right < from) {
                return emptySegmentResult();
            }
            if (left >= from && right <= to) {
                return queryFull(root, left, right, from, to);
            }
            int middle = (left + right) >> 1;
            queryPreProcess(root, left, right, from, to, middle);
            long leftResult = query(2 * root + 1, left, middle, from, to);
            long rightResult = query(2 * root + 2, middle + 1, right, from, to);
            return queryPostProcess(root, left, right, from, to, middle, leftResult, rightResult);
        }

    }

    static class Sorter {
        private static final int INSERTION_THRESHOLD = 16;

        private Sorter() {
        }

        public static void sort(LongList list, LongComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(LongList list, int from, int to, int remaining, LongComparator comparator) {
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
            long pivot = list.get(pivotIndex);
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

        private static void heapSort(LongList list, int from, int to, LongComparator comparator) {
            for (int i = (to + from - 1) >> 1; i >= from; i--) {
                siftDown(list, i, to, comparator, from);
            }
            for (int i = to; i > from; i--) {
                list.swap(from, i);
                siftDown(list, from, i - 1, comparator, from);
            }
        }

        private static void siftDown(LongList list, int start, int end, LongComparator comparator, int delta) {
            long value = list.get(start);
            while (true) {
                int child = ((start - delta) << 1) + 1 + delta;
                if (child > end) {
                    return;
                }
                long childValue = list.get(child);
                if (child + 1 <= end) {
                    long otherValue = list.get(child + 1);
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

        private static void insertionSort(LongList list, int from, int to, LongComparator comparator) {
            for (int i = from + 1; i <= to; i++) {
                long value = list.get(i);
                for (int j = i - 1; j >= from; j--) {
                    if (comparator.compare(list.get(j), value) <= 0) {
                        break;
                    }
                    list.swap(j, j + 1);
                }
            }
        }

    }

    static abstract class LongIntervalTree extends IntervalTree {
        protected long[] value;
        protected long[] delta;

        protected LongIntervalTree(int size) {
            this(size, true);
        }

        public LongIntervalTree(int size, boolean shouldInit) {
            super(size, shouldInit);
        }

        protected void initData(int size, int nodeCount) {
            value = new long[nodeCount];
            delta = new long[nodeCount];
        }

        protected abstract long joinValue(long left, long right);

        protected abstract long joinDelta(long was, long delta);

        protected abstract long accumulate(long value, long delta, int length);

        protected abstract long neutralValue();

        protected abstract long neutralDelta();

        protected long initValue(int index) {
            return neutralValue();
        }

        protected void initAfter(int root, int left, int right, int middle) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
            delta[root] = neutralDelta();
        }

        protected void initBefore(int root, int left, int right, int middle) {
        }

        protected void initLeaf(int root, int index) {
            value[root] = initValue(index);
            delta[root] = neutralDelta();
        }

        protected void pushDown(int root, int left, int middle, int right) {
            value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root], middle - left + 1);
            value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root], right - middle);
            delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
            delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
            delta[root] = neutralDelta();
        }

        protected long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult,
                                        long rightResult) {
            return joinValue(leftResult, rightResult);
        }

        protected void queryPreProcess(int root, int left, int right, int from, int to, int middle) {
            pushDown(root, left, middle, right);
        }

        protected long queryFull(int root, int left, int right, int from, int to) {
            return value[root];
        }

        protected long emptySegmentResult() {
            return neutralValue();
        }

    }

    static interface LongReversableCollection extends LongCollection {
    }

    static interface LongCollection extends LongStream {
        public int size();

        default public void add(long value) {
            throw new UnsupportedOperationException();
        }

        default public long[] toArray() {
            int size = size();
            long[] array = new long[size];
            int i = 0;
            for (LongIterator it = longIterator(); it.isValid(); it.advance()) {
                array[i++] = it.value();
            }
            return array;
        }

        default public LongCollection addAll(LongStream values) {
            for (LongIterator it = values.longIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static abstract class LongAbstractStream implements LongStream {
        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (LongIterator it = longIterator(); it.isValid(); it.advance()) {
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
            if (!(o instanceof LongStream)) {
                return false;
            }
            LongStream c = (LongStream) o;
            LongIterator it = longIterator();
            LongIterator jt = c.longIterator();
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
            for (LongIterator it = longIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
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

        public long[] readLongArray(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
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

        public long readLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

    static class LongArrayList extends LongAbstractStream implements LongList {
        private int size;
        private long[] data;

        public LongArrayList() {
            this(3);
        }

        public LongArrayList(int capacity) {
            data = new long[capacity];
        }

        public LongArrayList(LongCollection c) {
            this(c.size());
            addAll(c);
        }

        public LongArrayList(LongStream c) {
            this();
            if (c instanceof LongCollection) {
                ensureCapacity(((LongCollection) c).size());
            }
            addAll(c);
        }

        public LongArrayList(LongArrayList c) {
            size = c.size();
            data = c.data.clone();
        }

        public LongArrayList(long[] arr) {
            size = arr.length;
            data = arr.clone();
        }

        public int size() {
            return size;
        }

        public long get(int at) {
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

        public void addAt(int index, long value) {
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

        public void set(int index, long value) {
            if (index >= size) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            data[index] = value;
        }

    }

    static class ArrayUtils {
        public static long[] unique(long[] array) {
            return new LongArray(array).unique().toArray();
        }

    }
}