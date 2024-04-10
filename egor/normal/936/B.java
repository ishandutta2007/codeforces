import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.io.IOException;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int[][] a = new int[n][];
            for (int i = 0; i < n; i++) {
                a[i] = in.readIntArray(in.readInt());
            }
            int s = in.readInt() - 1;
            MiscUtils.decreaseByOne(a);
            Graph doubleGraph = new Graph(2 * n, 2 * m);
            for (int i = 0; i < n; i++) {
                for (int j : a[i]) {
                    doubleGraph.addSimpleEdge(i, j + n);
                    doubleGraph.addSimpleEdge(i + n, j);
                }
            }
            long[] dist = ShortestDistance.dijkstraAlgorithm(doubleGraph, s).first;
            for (int i = 0; i < n; i++) {
                if (dist[i + n] != Long.MAX_VALUE && doubleGraph.firstOutbound(i + n) == -1) {
                    out.printLine("Win");
                    IntList path = ShortestDistance.dijkstraAlgorithm(doubleGraph, s, i + n).second;
                    int[] answer = new int[path.size() + 1];
                    for (int j = 0; j < path.size(); j++) {
                        answer[j] = doubleGraph.source(path.get(j)) % n + 1;
                    }
                    answer[path.size()] = i + 1;
                    out.printLine(answer);
                    return;
                }
            }
            Graph graph = new Graph(n, m);
            for (int i = 0; i < n; i++) {
                for (int j : a[i]) {
                    graph.addSimpleEdge(i, j);
                }
            }
            Pair<int[], Graph> kosaraju = StronglyConnectedComponents.kosaraju(graph);
            graph = kosaraju.second;
            int[] size = new int[graph.vertexCount()];
            for (int i : kosaraju.first) {
                size[i]++;
            }
            dist = ShortestDistance.dijkstraAlgorithm(graph, kosaraju.first[s]).first;
            for (int i = 0; i < graph.vertexCount(); i++) {
                if (dist[i] != Long.MAX_VALUE && size[i] > 1) {
                    out.printLine("Draw");
                    return;
                }
            }
            out.printLine("Lose");
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

        @SuppressWarnings({"unchecked"})
        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) first).compareTo(o.first);
            if (value != 0) {
                return value;
            }
            return ((Comparable<V>) second).compareTo(o.second);
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

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
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

        public final int addSimpleEdge(int from, int to) {
            return addWeightedEdge(from, to, 0);
        }

        public final int vertexCount() {
            return vertexCount;
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

        public final int firstInbound(int vertex) {
            initInbound();
            int id = firstInbound[vertex];
            while (id != -1 && isRemoved(id)) {
                id = nextInbound[id];
            }
            return id;
        }

        public final int nextInbound(int id) {
            initInbound();
            id = nextInbound[id];
            while (id != -1 && isRemoved(id)) {
                id = nextInbound[id];
            }
            return id;
        }

        public final int source(int id) {
            return from[id];
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

        public final void addVertices(int count) {
            ensureVertexCapacity(vertexCount + count);
            Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
            if (firstInbound != null) {
                Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
            }
            vertexCount += count;
        }

        private void initInbound() {
            if (firstInbound == null) {
                firstInbound = new int[firstOutbound.length];
                Arrays.fill(firstInbound, 0, vertexCount, -1);
                nextInbound = new int[from.length];
                for (int i = 0; i < edgeCount; i++) {
                    nextInbound[i] = firstInbound[to[i]];
                    firstInbound[to[i]] = i;
                }
            }
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

        private void ensureVertexCapacity(int size) {
            if (firstOutbound.length < size) {
                int newSize = Math.max(size, 2 * firstOutbound.length);
                firstOutbound = resize(firstOutbound, newSize);
                if (firstInbound != null) {
                    firstInbound = resize(firstInbound, newSize);
                }
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

        public final boolean isSparse() {
            return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
        }

        protected class GraphEdge implements Edge {
            protected int id;

            protected GraphEdge(int id) {
                this.id = id;
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

    static interface IntReversableCollection extends IntCollection {
    }

    static interface Edge {
    }

    static class ArrayUtils {
        public static int[] createArray(int count, int value) {
            int[] array = new int[count];
            Arrays.fill(array, value);
            return array;
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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static class ShortestDistance {
        public static Pair<long[], int[]> dijkstraAlgorithm(Graph graph, int source) {
            int vertexCount = graph.vertexCount();
            final long[] distance = new long[vertexCount];
            int[] last = new int[vertexCount];
            Arrays.fill(distance, Long.MAX_VALUE);
            Arrays.fill(last, -1);
            distance[source] = 0;
            if (graph.isSparse()) {
                Heap heap = new Heap(vertexCount, new IntComparator() {
                    public int compare(int first, int second) {
                        return IntegerUtils.longCompare(distance[first], distance[second]);
                    }
                }, vertexCount);
                heap.add(source);
                while (!heap.isEmpty()) {
                    int current = heap.poll();
                    int id = graph.firstOutbound(current);
                    while (id != -1) {
                        int next = graph.destination(id);
                        long total = graph.weight(id) + distance[current];
                        if (distance[next] > total) {
                            distance[next] = total;
                            if (heap.getIndex(next) == -1) {
                                heap.add(next);
                            } else {
                                heap.shiftUp(heap.getIndex(next));
                            }
                            last[next] = id;
                        }
                        id = graph.nextOutbound(id);
                    }
                }
            } else {
                boolean[] visited = new boolean[vertexCount];
                for (int i = 0; i < vertexCount; i++) {
                    int index = -1;
                    long length = Long.MAX_VALUE;
                    for (int j = 0; j < vertexCount; j++) {
                        if (!visited[j] && distance[j] < length) {
                            length = distance[j];
                            index = j;
                        }
                    }
                    if (index == -1) {
                        break;
                    }
                    visited[index] = true;
                    int id = graph.firstOutbound(index);
                    while (id != -1) {
                        int next = graph.destination(id);
                        if (!visited[next]) {
                            long total = graph.weight(id) + length;
                            if (distance[next] > total) {
                                distance[next] = total;
                                last[next] = id;
                            }
                        }
                        id = graph.nextOutbound(id);
                    }
                }
            }
            return Pair.makePair(distance, last);
        }

        public static Pair<Long, IntList> dijkstraAlgorithm(Graph graph, int source, int destination) {
            if (source == destination) {
                return Pair.makePair(0L, new IntArrayList());
            }
            Pair<long[], int[]> result = dijkstraAlgorithm(graph, source);
            if (result.second[destination] == -1) {
                return null;
            }
            IntList path = new IntArrayList();
            int id = destination;
            while (id != source) {
                path.add(result.second[id]);
                id = graph.source(result.second[id]);
            }
            path.inPlaceReverse();
            return Pair.makePair(result.first[destination], path);
        }

    }

    static class StronglyConnectedComponents {
        private final Graph graph;
        private int[] order;
        private boolean[] visited;
        private int index = 0;
        private int vertexCount;
        private int[] condensed;
        private int[] next;
        private int key;
        private int[] queue;
        private int queueSize;

        private StronglyConnectedComponents(Graph graph) {
            this.graph = graph;
            vertexCount = graph.vertexCount();
            order = new int[vertexCount];
            visited = new boolean[vertexCount];
            condensed = new int[vertexCount];
        }

        public static Pair<int[], Graph> kosaraju(Graph graph) {
            return new StronglyConnectedComponents(graph).kosaraju();
        }

        private Pair<int[], Graph> kosaraju() {
            for (int i = 0; i < vertexCount; i++) {
                if (!visited[i]) {
                    firstDFS(i);
                }
            }
            Arrays.fill(visited, false);
            Graph result = new Graph(0);
            index = 0;
            next = ArrayUtils.createArray(graph.vertexCount(), -1);
            queue = new int[graph.vertexCount()];
            for (int i = vertexCount - 1; i >= 0; i--) {
                if (!visited[order[i]]) {
                    key = i;
                    queueSize = 0;
                    secondDFS(order[i]);
                    result.addVertices(1);
                    for (int j = 0; j < queueSize; j++) {
                        result.addSimpleEdge(queue[j], index);
                    }
                    index++;
                }
            }
            return Pair.makePair(condensed, result);
        }

        private void secondDFS(int vertexID) {
            if (visited[vertexID]) {
                if (condensed[vertexID] != index) {
                    if (next[condensed[vertexID]] != key) {
                        next[condensed[vertexID]] = key;
                        queue[queueSize++] = condensed[vertexID];
                    }
                }
                return;
            }
            condensed[vertexID] = index;
            visited[vertexID] = true;
            int edgeID = graph.firstInbound(vertexID);
            while (edgeID != -1) {
                secondDFS(graph.source(edgeID));
                edgeID = graph.nextInbound(edgeID);
            }
        }

        private void firstDFS(int vertexID) {
            if (visited[vertexID]) {
                return;
            }
            visited[vertexID] = true;
            int edgeID = graph.firstOutbound(vertexID);
            while (edgeID != -1) {
                firstDFS(graph.destination(edgeID));
                edgeID = graph.nextOutbound(edgeID);
            }
            order[index++] = vertexID;
        }

    }
}