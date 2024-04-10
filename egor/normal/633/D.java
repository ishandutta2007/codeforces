import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.Set;
import java.io.IOException;
import java.util.AbstractMap;
import java.io.Writer;
import java.util.Map.Entry;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] a = IOUtils.readIntArray(in, n);
            Set<IntIntPair> processed = new EHashSet<>();
            IntHashMap qty = new IntHashMap();
            for (int i : a) {
                int count = qty.contains(i) ? qty.get(i) : 0;
                qty.put(i, count + 1);
            }
            int answer = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    IntIntPair key = new IntIntPair(a[i], a[j]);
                    if (processed.contains(key)) {
                        continue;
                    }
                    processed.add(key);
                    int last = a[i];
                    int current = a[j];
                    boolean cycle = false;
                    IntList suffix = new IntArrayList();
                    suffix.add(last);
                    suffix.add(current);
                    while (true) {
                        int next = last + current;
                        if (!qty.contains(next)) {
                            break;
                        }
                        key = new IntIntPair(current, next);
                        if (processed.contains(key)) {
                            cycle = true;
                            break;
                        }
                        processed.add(key);
                        suffix.add(next);
                        last = current;
                        current = next;
                    }
                    if (cycle) {
                        IntHashMap local = new IntHashMap();
                        for (int k = 0; k < suffix.size(); k++) {
                            int val = suffix.get(k);
                            int count = local.contains(val) ? local.get(val) : 0;
                            count++;
                            local.put(val, count);
                        }
                        int full = Integer.MAX_VALUE;
                        for (int k = 0; k < suffix.size(); k++) {
                            int val = suffix.get(k);
                            full = Math.min(full, qty.get(val) / local.get(val));
                        }
                        IntList all = new IntArrayList(suffix);
                        all.addAll(suffix);
                        IntHashMap nLocal = new IntHashMap();
                        for (int k = 0; k < suffix.size(); k++) {
                            int val = suffix.get(k);
                            nLocal.put(val, full * local.get(val));
                        }
                        answer = updateAnswer(qty, nLocal, answer, all, full * suffix.size());
                    } else {
                        IntList prefix = new IntArrayList();
                        last = a[j];
                        current = a[i];
                        while (true) {
                            int next = last - current;
                            if (!qty.contains(next)) {
                                break;
                            }
                            processed.add(new IntIntPair(next, current));
                            prefix.add(next);
                            last = current;
                            current = next;
                        }
                        prefix.inPlaceReverse();
                        IntList all = (IntList) prefix.addAll(suffix);
                        answer = updateAnswer(qty, new IntHashMap(), answer, all, 0);
                    }
                }
            }
            out.printLine(answer);
        }

        protected int updateAnswer(IntHashMap qty, IntHashMap local, int answer, IntList all, int additional) {
            int start = 0;
            for (int k = 0; k < all.size(); k++) {
                int val = all.get(k);
                int count = local.contains(val) ? local.get(val) : 0;
                count++;
                local.put(val, count);
                while (local.get(val) > qty.get(val)) {
                    int prev = all.get(start++);
                    local.put(prev, local.get(prev) - 1);
                }
                answer = Math.max(answer, k - start + 1 + additional);
            }
            return answer;
        }

    }

    static class EHashSet<E> extends AbstractSet<E> {
        private static final Object VALUE = new Object();
        private final Map<E, Object> map;

        public EHashSet() {
            this(4);
        }

        public EHashSet(int maxSize) {
            map = new EHashMap<E, Object>(maxSize);
        }

        public EHashSet(Collection<E> collection) {
            this(collection.size());
            addAll(collection);
        }


        public boolean contains(Object o) {
            return map.containsKey(o);
        }


        public boolean add(E e) {
            if (e == null) {
                return false;
            }
            return map.put(e, VALUE) == null;
        }


        public boolean remove(Object o) {
            if (o == null) {
                return false;
            }
            return map.remove(o) != null;
        }


        public void clear() {
            map.clear();
        }


        public Iterator<E> iterator() {
            return map.keySet().iterator();
        }


        public int size() {
            return map.size();
        }

    }

    static class EHashMap<E, V> extends AbstractMap<E, V> {
        private static final int[] shifts = new int[10];
        private int size;
        private HashEntry<E, V>[] data;
        private int capacity;
        private Set<Entry<E, V>> entrySet;

        static {
            Random random = new Random(System.currentTimeMillis());
            for (int i = 0; i < 10; i++) {
                shifts[i] = 1 + 3 * i + random.nextInt(3);
            }
        }

        public EHashMap() {
            this(4);
        }

        private void setCapacity(int size) {
            capacity = Integer.highestOneBit(4 * size);
            //noinspection unchecked
            data = new HashEntry[capacity];
        }

        public EHashMap(int maxSize) {
            setCapacity(maxSize);
            entrySet = new AbstractSet<Entry<E, V>>() {

                public Iterator<Entry<E, V>> iterator() {
                    return new Iterator<Entry<E, V>>() {
                        private HashEntry<E, V> last = null;
                        private HashEntry<E, V> current = null;
                        private HashEntry<E, V> base = null;
                        private int lastIndex = -1;
                        private int index = -1;

                        public boolean hasNext() {
                            if (current == null) {
                                for (index++; index < capacity; index++) {
                                    if (data[index] != null) {
                                        base = current = data[index];
                                        break;
                                    }
                                }
                            }
                            return current != null;
                        }

                        public Entry<E, V> next() {
                            if (!hasNext()) {
                                throw new NoSuchElementException();
                            }
                            last = current;
                            lastIndex = index;
                            current = current.next;
                            if (base.next != last) {
                                base = base.next;
                            }
                            return last;
                        }

                        public void remove() {
                            if (last == null) {
                                throw new IllegalStateException();
                            }
                            size--;
                            if (base == last) {
                                data[lastIndex] = last.next;
                            } else {
                                base.next = last.next;
                            }
                        }
                    };
                }


                public int size() {
                    return size;
                }
            };
        }

        public EHashMap(Map<E, V> map) {
            this(map.size());
            putAll(map);
        }


        public Set<Entry<E, V>> entrySet() {
            return entrySet;
        }


        public void clear() {
            Arrays.fill(data, null);
            size = 0;
        }

        private int index(Object o) {
            return getHash(o.hashCode()) & (capacity - 1);
        }

        private int getHash(int h) {
            int result = h;
            for (int i : shifts) {
                result ^= h >>> i;
            }
            return result;
        }


        public V remove(Object o) {
            if (o == null) {
                return null;
            }
            int index = index(o);
            HashEntry<E, V> current = data[index];
            HashEntry<E, V> last = null;
            while (current != null) {
                if (current.key.equals(o)) {
                    if (last == null) {
                        data[index] = current.next;
                    } else {
                        last.next = current.next;
                    }
                    size--;
                    return current.value;
                }
                last = current;
                current = current.next;
            }
            return null;
        }


        public V put(E e, V value) {
            if (e == null) {
                return null;
            }
            int index = index(e);
            HashEntry<E, V> current = data[index];
            if (current != null) {
                while (true) {
                    if (current.key.equals(e)) {
                        V oldValue = current.value;
                        current.value = value;
                        return oldValue;
                    }
                    if (current.next == null) {
                        break;
                    }
                    current = current.next;
                }
            }
            if (current == null) {
                data[index] = new HashEntry<E, V>(e, value);
            } else {
                current.next = new HashEntry<E, V>(e, value);
            }
            size++;
            if (2 * size > capacity) {
                HashEntry<E, V>[] oldData = data;
                setCapacity(size);
                for (HashEntry<E, V> entry : oldData) {
                    while (entry != null) {
                        HashEntry<E, V> next = entry.next;
                        index = index(entry.key);
                        entry.next = data[index];
                        data[index] = entry;
                        entry = next;
                    }
                }
            }
            return null;
        }


        public V get(Object o) {
            if (o == null) {
                return null;
            }
            int index = index(o);
            HashEntry<E, V> current = data[index];
            while (current != null) {
                if (current.key.equals(o)) {
                    return current.value;
                }
                current = current.next;
            }
            return null;
        }


        public boolean containsKey(Object o) {
            if (o == null) {
                return false;
            }
            int index = index(o);
            HashEntry<E, V> current = data[index];
            while (current != null) {
                if (current.key.equals(o)) {
                    return true;
                }
                current = current.next;
            }
            return false;
        }


        public int size() {
            return size;
        }

        private static class HashEntry<E, V> implements Entry<E, V> {
            private final E key;
            private V value;
            private HashEntry<E, V> next;

            private HashEntry(E key, V value) {
                this.key = key;
                this.value = value;
            }

            public E getKey() {
                return key;
            }

            public V getValue() {
                return value;
            }

            public V setValue(V value) {
                V oldValue = this.value;
                this.value = value;
                return oldValue;
            }

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

    }

    static class IntegerUtils {
        public static int gcd(int a, int b) {
            a = Math.abs(a);
            b = Math.abs(b);
            while (b != 0) {
                int temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }

    }

    static interface IntReversableCollection extends IntCollection {
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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

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

    static class IntHashMap {
        private static final Random RND = new Random();
        private static final int[] SHIFTS = new int[4];
        private static final byte PRESENT_MASK = 1;
        private int size;
        private int realSize;
        private int[] keys;
        private int[] values;
        private byte[] present;
        private int step;
        private int ratio;

        static {
            for (int i = 0; i < 4; i++) {
                SHIFTS[i] = RND.nextInt(31) + 1;
            }
        }

        public IntHashMap() {
            this(3);
        }

        public IntHashMap(int capacity) {
            capacity = Math.max(capacity, 1);
            keys = new int[capacity];
            present = new byte[capacity];
            values = new int[capacity];
            ratio = 2;
            initStep(capacity);
        }

        private void initStep(int capacity) {
            step = RND.nextInt(capacity - 2) + 1;
            while (IntegerUtils.gcd(step, capacity) != 1) {
                step++;
            }
        }

        public void put(int key, int value) {
            ensureCapacity((realSize + 1) * ratio + 2);
            int current = getHash(key);
            while (present[current] != 0) {
                if ((present[current] & PRESENT_MASK) != 0 && keys[current] == key) {
                    values[current] = value;
                    return;
                }
                current += step;
                if (current >= values.length) {
                    current -= values.length;
                }
            }
            while ((present[current] & PRESENT_MASK) != 0) {
                current += step;
                if (current >= keys.length) {
                    current -= keys.length;
                }
            }
            if (present[current] == 0) {
                realSize++;
            }
            present[current] = PRESENT_MASK;
            keys[current] = key;
            values[current] = value;
            size++;
        }

        private int getHash(int key) {
            int result = key;
            for (int i : SHIFTS) {
                result ^= key >> i;
            }
            result %= keys.length;
            if (result < 0) {
                result += keys.length;
            }
            return result;
        }

        private void ensureCapacity(int capacity) {
            if (keys.length < capacity) {
                capacity = Math.max(capacity * 2, keys.length);
                rebuild(capacity);
            }
        }

        private void rebuild(int capacity) {
            initStep(capacity);
            int[] oldKeys = keys;
            byte[] oldPresent = present;
            int[] oldValues = values;
            keys = new int[capacity];
            present = new byte[capacity];
            values = new int[capacity];
            size = 0;
            realSize = 0;
            for (int i = 0; i < oldKeys.length; i++) {
                if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK) {
                    put(oldKeys[i], oldValues[i]);
                }
            }
        }

        public boolean contains(int key) {
            int current = getHash(key);
            while (present[current] != 0) {
                if (keys[current] == key && (present[current] & PRESENT_MASK) != 0) {
                    return true;
                }
                current += step;
                if (current >= keys.length) {
                    current -= keys.length;
                }
            }
            return false;
        }

        public int get(int key) {
            int current = getHash(key);
            while (present[current] != 0) {
                if (keys[current] == key && (present[current] & PRESENT_MASK) != 0) {
                    return values[current];
                }
                current += step;
                if (current >= keys.length) {
                    current -= keys.length;
                }
            }
            throw new NoSuchElementException();
        }

    }
}