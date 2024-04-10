import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.ArrayList;
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
import java.util.stream.Collectors;
import java.util.List;
import java.util.AbstractMap;
import java.util.Map.Entry;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Map<Set<String>, List<String>> sets = new CPPMap<>(ArrayList::new);
            Map<String, Set<String>> sites = new CPPMap<>(EHashSet::new);
            int n = in.readInt();
            for (int i = 0; i < n; i++) {
                String url = in.readString();
                int slash = url.indexOf('/', 7);
                if (slash == -1) {
                    slash = url.length();
                }
                sites.get(url.substring(0, slash)).add(url.substring(slash));
            }
            for (Map.Entry<String, Set<String>> entry : sites.entrySet()) {
                sets.get(entry.getValue()).add(entry.getKey());
            }
            List<Map.Entry<Set<String>, List<String>>> result =
                    sets.entrySet().stream().filter(x -> x.getValue().size() > 1).collect(Collectors.toList());
            out.printLine(result.size());
            for (Map.Entry<Set<String>, List<String>> entry : result) {
                out.printLine(entry.getValue().toArray());
            }
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

    static class CPPMap<K, V> extends EHashMap<K, V> {
        private final Factory<V> defaultValueFactory;

        public CPPMap(Factory<V> defaultValueFactory) {
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

    static interface Factory<V> {
        public V create();

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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

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
}