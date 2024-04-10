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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int a = in.readInt();
            int b = in.readInt();
            int[] u = new int[m];
            int[] v = new int[m];
            int[] c = new int[m];
            in.readIntArrays(u, v, c);
            MiscUtils.decreaseByOne(u, v);
            IndependentSetSystem setSystem = new RecursiveIndependentSetSystem(n);
            for (int i = 0; i < m; i++) {
                if (c[i] == a) {
                    setSystem.join(u[i], v[i]);
                }
            }
            int[] color = ArrayUtils.createArray(n, -1);
            int next = 0;
            boolean[] forbidden = new boolean[m];
            for (int i = 0; i < m; i++) {
                if (setSystem.get(u[i]) == setSystem.get(v[i]) && c[i] == b) {
                    forbidden[i] = true;
                }
            }
            for (int i = 0; i < n; i++) {
                if (setSystem.get(i) == i) {
                    int qty = 0;
                    for (int j = 0; j < n; j++) {
                        if (setSystem.get(j) == i) {
                            qty++;
                        }
                    }
                    if (qty >= 4) {
                        for (int j = 0; j < n; j++) {
                            if (setSystem.get(j) == i) {
                                color[j] = next;
                            }
                        }
                        next++;
                    }
                }
            }
            IntGraph small = IntBidirectionalGraph.createWeightedGraph(n, u, v, c);
/*        IntGraph big = new IntGraph(n * (1 << next));
        for (int i = 0; i < big.vertexCount(); i++) {
            int smallV = i >> next;
            int mask = i & ((1 << next) - 1);
            for (int j = small.firstOutbound(smallV); j != -1; j = small.nextOutbound(j)) {
                if (forbidden[j >> 1]) {
                    continue;
                }
                int weight = c[j >> 1];
                int to = small.destination(j);
                if (weight == a || color[to] == -1) {
                    big.addWeightedEdge(i, (to << next) + mask, weight);
                } else if ((mask >> color[to] & 1) == 0) {
                    big.addWeightedEdge(i, (to << next) + mask + (1 << color[to]), weight);
                }
            }
        }*/
            int start = 0;
            if (color[0] != -1) {
                start = 1 << color[0];
            }
            long[] dist = dijkstraAlgorithm(small, start, next, color, a, b, forbidden);
            long[] answer = ArrayUtils.createArray(n, (long) Long.MAX_VALUE);
            for (int i = 0; i < dist.length; i++) {
                answer[i >> next] = Math.min(answer[i >> next], dist[i]);
            }
            out.printLine(answer);
        }

        public static long[] dijkstraAlgorithm(IntGraph graph, int source, int mult, int[] color, int a, int b,
                                               boolean[] forbidden) {
            int vertexCount = graph.vertexCount() << mult;
            final long[] distance = new long[vertexCount];
            Arrays.fill(distance, Long.MAX_VALUE);
            distance[source] = 0;
            Heap heap = new Heap(vertexCount, new IntComparator() {
                public int compare(int first, int second) {
                    return IntegerUtils.longCompare(distance[first], distance[second]);
                }
            }, vertexCount);
            heap.add(source);
            while (!heap.isEmpty()) {
                int current = heap.poll();
                int vert = current >> mult;
                int mask = current & ((1 << mult) - 1);
                int id = graph.firstOutbound(vert);
                while (id != -1) {
                    int next = graph.destination(id);
                    int col = color[next];
                    if (graph.weight(id) == b && col != -1 && (mask >> col & 1) == 1 || forbidden[id >> 1]) {
                        id = graph.nextOutbound(id);
                        continue;
                    }
                    long total = graph.weight(id) + distance[current];
                    next <<= mult;
                    next += mask;
                    if (col != -1) {
                        next |= 1 << col;
                    }
                    if (distance[next] > total) {
                        distance[next] = total;
                        if (heap.getIndex(next) == -1) {
                            heap.add(next);
                        } else {
                            heap.shiftUp(heap.getIndex(next));
                        }
                    }
                    id = graph.nextOutbound(id);
                }
            }
            return distance;
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
    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

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

    static class MiscUtils {
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
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

    static class IntBidirectionalGraph extends IntGraph {
        public int[] transposedEdge;

        public IntBidirectionalGraph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public IntBidirectionalGraph(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            transposedEdge = new int[2 * edgeCapacity];
        }

        public static IntBidirectionalGraph createWeightedGraph(int vertexCount, int[] from, int[] to, int[] weight) {
            IntBidirectionalGraph graph = new IntBidirectionalGraph(vertexCount, from.length);
            for (int i = 0; i < from.length; i++) {
                graph.addWeightedEdge(from[i], to[i], weight[i]);
            }
            return graph;
        }

        public int addEdge(int fromID, int toID, int weight, long capacity, int reverseEdge) {
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

    static class IntegerUtils {
        public static int longCompare(long a, long b) {
            if (a < b) {
                return -1;
            }
            if (a > b) {
                return 1;
            }
            return 0;
        }

    }

    static interface IntCollection extends IntStream {
    }

    static class IntGraph {
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
        private int[] weight;
        public long[] capacity;
        private int[] reverseEdge;
        private int[] flags;

        public IntGraph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public IntGraph(int vertexCount, int edgeCapacity) {
            this.vertexCount = vertexCount;
            firstOutbound = new int[vertexCount];
            Arrays.fill(firstOutbound, -1);

            from = new int[edgeCapacity];
            to = new int[edgeCapacity];
            nextOutbound = new int[edgeCapacity];
            flags = new int[edgeCapacity];
        }

        public int addEdge(int fromID, int toID, int weight, long capacity, int reverseEdge) {
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
                    this.weight = new int[from.length];
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

        public final int addFlowWeightedEdge(int from, int to, int weight, long capacity) {
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

        public final int addWeightedEdge(int from, int to, int weight) {
            return addFlowWeightedEdge(from, to, weight, 0);
        }

        public final int vertexCount() {
            return vertexCount;
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

        public final int weight(int id) {
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
                int newSize = Math.max(size, 4 * from.length / 3);
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

    static class ArrayUtils {
        public static int[] createArray(int count, int value) {
            int[] array = new int[count];
            Arrays.fill(array, value);
            return array;
        }

        public static long[] createArray(int count, long value) {
            long[] array = new long[count];
            Arrays.fill(array, value);
            return array;
        }

    }

    static interface Edge {
    }

    static interface IndependentSetSystem {
        public boolean join(int first, int second);

        public int get(int index);

        public static interface Listener {
            public void joined(int joinedRoot, int root);

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
}