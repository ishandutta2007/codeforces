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
        EStranaNN solver = new EStranaNN();
        solver.solve(1, in, out);
        out.close();
    }

    static class EStranaNN {
        int[][] edges;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] p = in.readIntArray(n - 1);
            BidirectionalGraph graph = new BidirectionalGraph(n);
            for (int i = 0; i < n - 1; i++) {
                graph.addSimpleEdge(i + 1, p[i] - 1);
            }
            int m = in.readInt();
            int[] a = new int[m];
            int[] b = new int[m];
            in.readIntArrays(a, b);
            MiscUtils.decreaseByOne(a, b);
            LCA lca = new LCA(graph);
            DFSOrder order = new DFSOrder(graph);
            int[] topmost = ArrayUtils.createOrder(n);
            for (int i = 0; i < m; i++) {
                int parent = lca.getLCA(a[i], b[i]);
                if (lca.getLevel(topmost[a[i]]) > lca.getLevel(parent)) {
                    topmost[a[i]] = parent;
                }
                if (lca.getLevel(topmost[b[i]]) > lca.getLevel(parent)) {
                    topmost[b[i]] = parent;
                }
            }
            int[] ltr = ArrayUtils.reversePermutation(order.position);
            for (int i = n - 1; i >= 0; i--) {
                int id = ltr[i];
                for (int j = graph.firstOutbound(id); j != -1; j = graph.nextOutbound(j)) {
                    int to = graph.destination(j);
                    if (order.position[to] > i && lca.getLevel(topmost[to]) < lca.getLevel(topmost[id])) {
                        topmost[id] = topmost[to];
                    }
                }
            }
            int[][] steps = new int[20][n];
            System.arraycopy(topmost, 0, steps[0], 0, n);
            for (int i = 1; i < 20; i++) {
                for (int j = 0; j < n; j++) {
                    steps[i][j] = steps[i - 1][steps[i - 1][j]];
                }
            }
            edges = new int[4 * n][];
            Graph buses = new BidirectionalGraph(n);
            for (int i = 0; i < m; i++) {
                buses.addSimpleEdge(order.position[a[i]], order.position[b[i]]);
            }
            init(0, 0, n - 1, buses);
            int q = in.readInt();
            for (int i = 0; i < q; i++) {
                int u = in.readInt() - 1;
                int v = in.readInt() - 1;
                int answer = 0;
                int parent = lca.getLCA(u, v);
                for (int j = 19; j >= 0; j--) {
                    if (lca.getLevel(steps[j][u]) > lca.getLevel(parent)) {
                        answer += 1 << j;
                        u = steps[j][u];
                    }
                    if (lca.getLevel(steps[j][v]) > lca.getLevel(parent)) {
                        answer += 1 << j;
                        v = steps[j][v];
                    }
                }
                if (u != parent && topmost[u] == u || v != parent && topmost[v] == v) {
                    out.printLine(-1);
                    continue;
                }
                if (u == parent || v == parent) {
                    out.printLine(answer + 1);
                    continue;
                }
                if (query(0, 0, n - 1, order.position[u], order.end[u], order.position[v], order.end[v])) {
                    answer++;
                } else {
                    answer += 2;
                }
                out.printLine(answer);
            }
        }

        private boolean query(int root, int left, int right, int lFrom, int lTo, int rFrom, int rTo) {
            if (right < lFrom || left > lTo) {
                return false;
            }
            if (left >= lFrom && right <= lTo) {
                int bs = Arrays.binarySearch(edges[root], rFrom);
                return (bs >= 0 || bs != Arrays.binarySearch(edges[root], rTo));
            }
            int middle = (left + right) >> 1;
            return query(2 * root + 1, left, middle, lFrom, lTo, rFrom, rTo) ||
                    query(2 * root + 2, middle + 1, right, lFrom, lTo, rFrom, rTo);
        }

        private IntList init(int root, int left, int right, Graph buses) {
            if (left == right) {
                IntList result = new IntArrayList();
                for (int i = buses.firstOutbound(left); i != -1; i = buses.nextOutbound(i)) {
                    result.add(buses.destination(i));
                }
                result.sort();
                result = result.unique();
                edges[root] = result.toArray();
                return result;
            }
            int middle = (left + right) >> 1;
            IntList l = init(2 * root + 1, left, middle, buses);
            IntList r = init(2 * root + 2, middle + 1, right, buses);
            int i = 0;
            int j = 0;
            IntList result = new IntArrayList();
            while (i < l.size() && j < r.size()) {
                if (l.get(i) == r.get(j)) {
                    result.add(l.get(i));
                    i++;
                    j++;
                } else if (l.get(i) < r.get(j)) {
                    result.add(l.get(i));
                    i++;
                } else {
                    result.add(r.get(j));
                    j++;
                }
            }
            for (; i < l.size(); i++) {
                result.add(l.get(i));
            }
            for (; j < r.size(); j++) {
                result.add(r.get(j));
            }
            edges[root] = result.toArray();
            return result;
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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

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

    static class LCA {
        private final long[] order;
        private final int[] position;
        private final Graph graph;
        private final IntervalTree lcaTree;
        private final int[] level;

        public LCA(Graph graph) {
            this(graph, 0);
        }

        public LCA(Graph graph, int root) {
            this.graph = graph;
            order = new long[2 * graph.vertexCount() - 1];
            position = new int[graph.vertexCount()];
            level = new int[graph.vertexCount()];
            int[] index = new int[graph.vertexCount()];
            for (int i = 0; i < index.length; i++) {
                index[i] = graph.firstOutbound(i);
            }
            int[] last = new int[graph.vertexCount()];
            int[] stack = new int[graph.vertexCount()];
            stack[0] = root;
            int size = 1;
            int j = 0;
            last[root] = -1;
            Arrays.fill(position, -1);
            while (size > 0) {
                int vertex = stack[--size];
                if (position[vertex] == -1) {
                    position[vertex] = j;
                }
                order[j++] = vertex;
                if (last[vertex] != -1) {
                    level[vertex] = level[last[vertex]] + 1;
                }
                while (index[vertex] != -1 && last[vertex] == graph.destination(index[vertex])) {
                    index[vertex] = graph.nextOutbound(index[vertex]);
                }
                if (index[vertex] != -1) {
                    stack[size++] = vertex;
                    stack[size++] = graph.destination(index[vertex]);
                    last[graph.destination(index[vertex])] = vertex;
                    index[vertex] = graph.nextOutbound(index[vertex]);
                }
            }
            lcaTree = new ReadOnlyIntervalTree(order) {

                protected long joinValue(long left, long right) {
                    if (left == -1) {
                        return right;
                    }
                    if (right == -1) {
                        return left;
                    }
                    if (level[((int) left)] < level[((int) right)]) {
                        return left;
                    }
                    return right;
                }


                protected long neutralValue() {
                    return -1;
                }
            };
            lcaTree.init();
        }

        public int getLCA(int first, int second) {
            return (int) lcaTree
                    .query(Math.min(position[first], position[second]), Math.max(position[first], position[second]));
        }

        public int getLevel(int vertex) {
            return level[vertex];
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

    static interface IntReversableCollection extends IntCollection {
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

    static class DFSOrder {
        public final int[] position;
        public final int[] end;

        public DFSOrder(Graph graph) {
            this(graph, 0);
        }

        public DFSOrder(Graph graph, int root) {
            int count = graph.vertexCount();
            position = new int[count];
            end = new int[count];
            int[] edge = new int[count];
            int[] stack = new int[count];
            for (int i = 0; i < count; i++) {
                edge[i] = graph.firstOutbound(i);
            }
            stack[0] = root;
            int size = 1;
            position[root] = 0;
            int index = 0;
            while (size > 0) {
                int current = stack[size - 1];
                if (edge[current] == -1) {
                    end[current] = index;
                    size--;
                } else {
                    int next = graph.destination(edge[current]);
                    edge[current] = graph.nextOutbound(edge[current]);
                    position[next] = ++index;
                    stack[size++] = next;
                }
            }
        }

        public DFSOrder(BidirectionalGraph graph) {
            this(graph, 0);
        }

        public DFSOrder(BidirectionalGraph graph, int root) {
            int count = graph.vertexCount();
            position = new int[count];
            end = new int[count];
            int[] edge = new int[count];
            int[] stack = new int[count];
            int[] last = new int[count];
            for (int i = 0; i < count; i++) {
                edge[i] = graph.firstOutbound(i);
            }
            stack[0] = root;
            last[root] = -1;
            int size = 1;
            position[root] = 0;
            int index = 0;
            while (size > 0) {
                int current = stack[size - 1];
                if (edge[current] == -1) {
                    end[current] = index;
                    size--;
                } else {
                    int next = graph.destination(edge[current]);
                    if (next == last[current]) {
                        edge[current] = graph.nextOutbound(edge[current]);
                        continue;
                    }
                    edge[current] = graph.nextOutbound(edge[current]);
                    position[next] = ++index;
                    last[next] = current;
                    stack[size++] = next;
                }
            }
        }

    }

    static interface Edge {
    }

    static class ArrayUtils {
        public static int[] range(int from, int to) {
            return Range.range(from, to).toArray();
        }

        public static int[] createOrder(int size) {
            return range(0, size);
        }

        public static int[] reversePermutation(int[] permutation) {
            int[] result = new int[permutation.length];
            for (int i = 0; i < permutation.length; i++) {
                result[permutation[i]] = i;
            }
            return result;
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

    static abstract class ReadOnlyIntervalTree extends IntervalTree {
        protected long[] value;
        protected long[] array;

        protected ReadOnlyIntervalTree(long[] array) {
            super(array.length, false);
            this.array = array;
            init();
        }


        protected void initData(int size, int nodeCount) {
            value = new long[nodeCount];
        }


        protected void initAfter(int root, int left, int right, int middle) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
        }


        protected void initBefore(int root, int left, int right, int middle) {
        }


        protected void initLeaf(int root, int index) {
            value[root] = array[index];
        }


        protected long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult,
                                        long rightResult) {
            return joinValue(leftResult, rightResult);
        }


        protected void queryPreProcess(int root, int left, int right, int from, int to, int middle) {
        }


        protected long queryFull(int root, int left, int right, int from, int to) {
            return value[root];
        }


        protected long emptySegmentResult() {
            return neutralValue();
        }

        protected abstract long neutralValue();

        protected abstract long joinValue(long left, long right);

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

        default public IntList sort() {
            sort(IntComparator.DEFAULT);
            return this;
        }

        default public IntList sort(IntComparator comparator) {
            Sorter.sort(this, comparator);
            return this;
        }

        default IntList unique() {
            int last = Integer.MIN_VALUE;
            IntList result = new IntArrayList();
            int size = size();
            for (int i = 0; i < size; i++) {
                int current = get(i);
                if (current != last) {
                    result.add(current);
                    last = current;
                }
            }
            return result;
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
}