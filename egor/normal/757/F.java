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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int s = in.readInt() - 1;
            int[] u = new int[m];
            int[] v = new int[m];
            int[] w = new int[m];
            IOUtils.readIntArrays(in, u, v, w);
            MiscUtils.decreaseByOne(u, v);
            Graph g = BidirectionalGraph.createWeightedGraph(n, u, v, ArrayUtils.asLong(w));
            long[] distance = new long[n];
            Arrays.fill(distance, Long.MAX_VALUE);
            int[] source = new int[n];
            Arrays.fill(source, -1);
            Heap heap = new Heap(n, (x, y) -> Long.compare(distance[x], distance[y]), n);
            distance[s] = 0;
            heap.add(s);
            while (heap.size() > 0) {
                int current = heap.poll();
                for (int i = g.firstOutbound(current); i != -1; i = g.nextOutbound(i)) {
                    long candidate = distance[current] + g.weight(i);
                    int to = g.destination(i);
                    if (candidate < distance[to]) {
                        distance[to] = candidate;
                        if (heap.getIndex(to) == -1) {
                            heap.add(to);
                        } else {
                            heap.shiftUp(heap.getIndex(to));
                        }
                        source[to] = current == s ? to : source[current];
                    } else if (candidate == distance[to]) {
                        if (source[to] != source[current]) {
                            source[to] = to;
                        }
                    }
                }
            }
            Counter<Integer> counter = new Counter<>();
            for (int i : source) {
                if (i >= 0) {
                    counter.add(i);
                }
            }
            long answer = 0;
            for (Long aLong : counter.values()) {
                answer = Math.max(answer, aLong);
            }
            out.printLine(answer);
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

    static interface IntCollection extends IntStream {
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

    }

    static class EHashMap<E, V> extends AbstractMap<E, V> {
        private static final int[] shifts = new int[10];
        private int size;
        private EHashMap.HashEntry<E, V>[] data;
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
            data = new EHashMap.HashEntry[capacity];
        }

        public EHashMap(int maxSize) {
            setCapacity(maxSize);
            entrySet = new AbstractSet<Entry<E, V>>() {

                public Iterator<Entry<E, V>> iterator() {
                    return new Iterator<Entry<E, V>>() {
                        private EHashMap.HashEntry<E, V> last = null;
                        private EHashMap.HashEntry<E, V> current = null;
                        private EHashMap.HashEntry<E, V> base = null;
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
            EHashMap.HashEntry<E, V> current = data[index];
            EHashMap.HashEntry<E, V> last = null;
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
            EHashMap.HashEntry<E, V> current = data[index];
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
                data[index] = new EHashMap.HashEntry<E, V>(e, value);
            } else {
                current.next = new EHashMap.HashEntry<E, V>(e, value);
            }
            size++;
            if (2 * size > capacity) {
                EHashMap.HashEntry<E, V>[] oldData = data;
                setCapacity(size);
                for (EHashMap.HashEntry<E, V> entry : oldData) {
                    while (entry != null) {
                        EHashMap.HashEntry<E, V> next = entry.next;
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
            EHashMap.HashEntry<E, V> current = data[index];
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
            EHashMap.HashEntry<E, V> current = data[index];
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
            private EHashMap.HashEntry<E, V> next;

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
        public static void readIntArrays(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
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

    static interface IntComparator {
        public static final IntComparator DEFAULT = (first, second) -> {
            if (first < second) {
                return -1;
            }
            if (first > second) {
                return 1;
            }
            return 0;
        };

        public int compare(int first, int second);

    }

    static class Graph {
        public static final int REMOVED_BIT = 0;
        protected int vertexCount;
        protected int edgeCount;
        private int[] firstOutbound;
        private int[] firstInbound;
        private Edge[] edges;
        private int[] nextInbound;
        private int[] nextOutbound;
        private int[] from;
        private int[] to;
        private long[] weight;
        public long[] capacity;
        private int[] reverseEdge;
        private int[] flags;

        public Graph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public Graph(int vertexCount, int edgeCapacity) {
            this.vertexCount = vertexCount;
            firstOutbound = new int[vertexCount];
            Arrays.fill(firstOutbound, -1);

            from = new int[edgeCapacity];
            to = new int[edgeCapacity];
            nextOutbound = new int[edgeCapacity];
            flags = new int[edgeCapacity];
        }

        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            ensureEdgeCapacity(edgeCount + 1);
            if (firstOutbound[fromID] != -1) {
                nextOutbound[edgeCount] = firstOutbound[fromID];
            } else {
                nextOutbound[edgeCount] = -1;
            }
            firstOutbound[fromID] = edgeCount;
            if (firstInbound != null) {
                if (firstInbound[toID] != -1) {
                    nextInbound[edgeCount] = firstInbound[toID];
                } else {
                    nextInbound[edgeCount] = -1;
                }
                firstInbound[toID] = edgeCount;
            }
            this.from[edgeCount] = fromID;
            this.to[edgeCount] = toID;
            if (capacity != 0) {
                if (this.capacity == null) {
                    this.capacity = new long[from.length];
                }
                this.capacity[edgeCount] = capacity;
            }
            if (weight != 0) {
                if (this.weight == null) {
                    this.weight = new long[from.length];
                }
                this.weight[edgeCount] = weight;
            }
            if (reverseEdge != -1) {
                if (this.reverseEdge == null) {
                    this.reverseEdge = new int[from.length];
                    Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
                }
                this.reverseEdge[edgeCount] = reverseEdge;
            }
            if (edges != null) {
                edges[edgeCount] = createEdge(edgeCount);
            }
            return edgeCount++;
        }

        protected final GraphEdge createEdge(int id) {
            return new GraphEdge(id);
        }

        public final int addFlowWeightedEdge(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int lastEdgeCount = edgeCount;
                addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
                return addEdge(from, to, weight, capacity, lastEdgeCount);
            }
        }

        protected int entriesPerEdge() {
            return 1;
        }

        public final int addWeightedEdge(int from, int to, long weight) {
            return addFlowWeightedEdge(from, to, weight, 0);
        }

        protected final int edgeCapacity() {
            return from.length;
        }

        public final int firstOutbound(int vertex) {
            int id = firstOutbound[vertex];
            while (id != -1 && isRemoved(id)) {
                id = nextOutbound[id];
            }
            return id;
        }

        public final int nextOutbound(int id) {
            id = nextOutbound[id];
            while (id != -1 && isRemoved(id)) {
                id = nextOutbound[id];
            }
            return id;
        }

        public final int destination(int id) {
            return to[id];
        }

        public final long weight(int id) {
            if (weight == null) {
                return 0;
            }
            return weight[id];
        }

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, REMOVED_BIT);
        }

        protected void ensureEdgeCapacity(int size) {
            if (from.length < size) {
                int newSize = Math.max(size, 2 * from.length);
                if (edges != null) {
                    edges = resize(edges, newSize);
                }
                from = resize(from, newSize);
                to = resize(to, newSize);
                nextOutbound = resize(nextOutbound, newSize);
                if (nextInbound != null) {
                    nextInbound = resize(nextInbound, newSize);
                }
                if (weight != null) {
                    weight = resize(weight, newSize);
                }
                if (capacity != null) {
                    capacity = resize(capacity, newSize);
                }
                if (reverseEdge != null) {
                    reverseEdge = resize(reverseEdge, newSize);
                }
                flags = resize(flags, newSize);
            }
        }

        protected final int[] resize(int[] array, int size) {
            int[] newArray = new int[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        private long[] resize(long[] array, int size) {
            long[] newArray = new long[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        private Edge[] resize(Edge[] array, int size) {
            Edge[] newArray = new Edge[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        protected class GraphEdge implements Edge {
            protected int id;

            protected GraphEdge(int id) {
                this.id = id;
            }

        }

    }

    static class Counter<K> extends EHashMap<K, Long> {
        public Counter() {
            super();
        }

        public Counter(int capacity) {
            super(capacity);
        }

        public long add(K key) {
            long result = get(key);
            put(key, result + 1);
            return result + 1;
        }


        public Long get(Object key) {
            if (containsKey(key)) {
                return super.get(key);
            }
            return 0L;
        }

    }

    static interface IntQueue extends IntCollection {
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

    static class BidirectionalGraph extends Graph {
        public int[] transposedEdge;

        public BidirectionalGraph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public BidirectionalGraph(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            transposedEdge = new int[2 * edgeCapacity];
        }

        public static BidirectionalGraph createWeightedGraph(int vertexCount, int[] from, int[] to, long[] weight) {
            BidirectionalGraph graph = new BidirectionalGraph(vertexCount, from.length);
            for (int i = 0; i < from.length; i++) {
                graph.addWeightedEdge(from[i], to[i], weight[i]);
            }
            return graph;
        }


        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int lastEdgeCount = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
            this.transposedEdge[lastEdgeCount] = lastEdgeCount + 1;
            this.transposedEdge[lastEdgeCount + 1] = lastEdgeCount;
            return lastEdgeCount;
        }


        protected int entriesPerEdge() {
            return 2;
        }


        protected void ensureEdgeCapacity(int size) {
            if (size > edgeCapacity()) {
                super.ensureEdgeCapacity(size);
                transposedEdge = resize(transposedEdge, edgeCapacity());
            }
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface Edge {
    }

    static class ArrayUtils {
        public static long[] asLong(int[] array) {
            long[] result = new long[array.length];
            for (int i = 0; i < array.length; i++) {
                result[i] = array[i];
            }
            return result;
        }

    }

    static class Heap implements IntQueue {
        private IntComparator comparator;
        private int size = 0;
        private int[] elements;
        private int[] at;

        public Heap(int maxElement) {
            this(10, maxElement);
        }

        public Heap(IntComparator comparator, int maxElement) {
            this(10, comparator, maxElement);
        }

        public Heap(int capacity, int maxElement) {
            this(capacity, IntComparator.DEFAULT, maxElement);
        }

        public Heap(int capacity, IntComparator comparator, int maxElement) {
            this.comparator = comparator;
            elements = new int[capacity];
            at = new int[maxElement];
            Arrays.fill(at, -1);
        }

        public int size() {
            return size;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public void add(int element) {
            ensureCapacity(size + 1);
            elements[size] = element;
            at[element] = size;
            shiftUp(size++);
        }

        public void shiftUp(int index) {
            //		if (index < 0 || index >= size)
            //			throw new IllegalArgumentException();
            int value = elements[index];
            while (index != 0) {
                int parent = (index - 1) >>> 1;
                int parentValue = elements[parent];
                if (comparator.compare(parentValue, value) <= 0) {
                    elements[index] = value;
                    at[value] = index;
                    return;
                }
                elements[index] = parentValue;
                at[parentValue] = index;
                index = parent;
            }
            elements[0] = value;
            at[value] = 0;
        }

        public void shiftDown(int index) {
            if (index < 0 || index >= size) {
                throw new IllegalArgumentException();
            }
            while (true) {
                int child = (index << 1) + 1;
                if (child >= size) {
                    return;
                }
                if (child + 1 < size && comparator.compare(elements[child], elements[child + 1]) > 0) {
                    child++;
                }
                if (comparator.compare(elements[index], elements[child]) <= 0) {
                    return;
                }
                swap(index, child);
                index = child;
            }
        }

        public int getIndex(int element) {
            return at[element];
        }

        private void swap(int first, int second) {
            int temp = elements[first];
            elements[first] = elements[second];
            elements[second] = temp;
            at[elements[first]] = first;
            at[elements[second]] = second;
        }

        private void ensureCapacity(int size) {
            if (elements.length < size) {
                int[] oldElements = elements;
                elements = new int[Math.max(2 * elements.length, size)];
                System.arraycopy(oldElements, 0, elements, 0, this.size);
            }
        }

        public int poll() {
            if (isEmpty()) {
                throw new IndexOutOfBoundsException();
            }
            int result = elements[0];
            at[result] = -1;
            if (size == 1) {
                size = 0;
                return result;
            }
            elements[0] = elements[--size];
            at[elements[0]] = 0;
            shiftDown(0);
            return result;
        }


        public IntIterator intIterator() {
            return new IntIterator() {
                private int at;


                public int value() throws NoSuchElementException {
                    return elements[at];
                }


                public boolean advance() throws NoSuchElementException {
                    return ++at < size;
                }


                public boolean isValid() {
                    return at < size;
                }


                public void remove() throws NoSuchElementException {
                    throw new UnsupportedOperationException();
                }
            };
        }

    }
}