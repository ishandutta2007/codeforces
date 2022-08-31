import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.InputMismatchException;

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
        FBlizhaishiiList solver = new FBlizhaishiiList();
        solver.solve(1, in, out);
    }

    static class FBlizhaishiiList {
        long[] weight;
        Graph graph;
        int[] to;
        long[] answer;
        int[] v;
        int[] l;
        int[] r;
        int[] first;
        int[] next;
        LongIntervalTree tree;
        int n;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            new Thread(null, () -> {
                n = in.readInt();
                int q = in.readInt();
                int[] p = new int[n - 1];
                int[] w = new int[n - 1];
                in.readIntArrays(p, w);
                graph = new Graph(n);
                for (int i = 0; i < n - 1; i++) {
                    graph.addWeightedEdge(p[i] - 1, i + 1, w[i]);
                }
                weight = ArrayUtils.createArray(n, Long.MAX_VALUE / 2);
                to = new int[n];
                go(0, 0);
                tree = new ArrayBasedIntervalTree(weight) {

                    protected long joinValue(long left, long right) {
                        return Math.min(left, right);
                    }


                    protected long joinDelta(long was, long delta) {
                        return was + delta;
                    }


                    protected long accumulate(long value, long delta, int length) {
                        return value + delta;
                    }


                    protected long neutralValue() {
                        return Long.MAX_VALUE;
                    }


                    protected long neutralDelta() {
                        return 0;
                    }
                };
                v = new int[q];
                l = new int[q];
                r = new int[q];
                in.readIntArrays(v, l, r);
                MiscUtils.decreaseByOne(v, l, r);
                answer = new long[q];
                first = ArrayUtils.createArray(n, -1);
                next = new int[q];
                for (int i = 0; i < q; i++) {
                    next[i] = first[v[i]];
                    first[v[i]] = i;
                }
                dfs(0);
                for (long i : answer) {
                    out.printLine(i);
                }
                out.flush();
                out.close();
            }, "Main", 1 << 28).start();
        }

        private void dfs(int vertex) {
            for (int i = first[vertex]; i != -1; i = next[i]) {
                answer[i] = tree.query(l[i], r[i]);
            }
            for (int i = graph.firstOutbound(vertex); i != -1; i = graph.nextOutbound(i)) {
                int next = graph.destination(i);
                tree.update(0, n - 1, graph.weight(i));
                tree.update(next, to[next], -2 * graph.weight(i));
                dfs(next);
                tree.update(0, n - 1, -graph.weight(i));
                tree.update(next, to[next], 2 * graph.weight(i));
            }
        }

        private int go(int vertex, long w) {
            int result = vertex;
            if (graph.firstOutbound(vertex) == -1) {
                weight[vertex] = w;
            } else {
                for (int i = graph.firstOutbound(vertex); i != -1; i = graph.nextOutbound(i)) {
                    result = Math.max(result, go(graph.destination(i), w + graph.weight(i)));
                }
            }
            to[vertex] = result;
            return result;
        }

    }

    static abstract class ArrayBasedIntervalTree extends LongIntervalTree {
        private long[] array;

        protected ArrayBasedIntervalTree(long[] array) {
            super(array.length, false);
            this.array = array;
            init();
        }

        protected long initValue(int index) {
            return array[index];
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

        public void flush() {
            writer.flush();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static interface Edge {
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

    static class MiscUtils {
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
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

        protected void updatePostProcess(int root, int left, int right, int from, int to, long delta, int middle) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
        }

        protected void updatePreProcess(int root, int left, int right, int from, int to, long delta, int middle) {
            pushDown(root, left, middle, right);
        }

        protected void pushDown(int root, int left, int middle, int right) {
            value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root], middle - left + 1);
            value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root], right - middle);
            delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
            delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
            delta[root] = neutralDelta();
        }

        protected void updateFull(int root, int left, int right, int from, int to, long delta) {
            value[root] = accumulate(value[root], delta, right - left + 1);
            this.delta[root] = joinDelta(this.delta[root], delta);
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

        protected abstract void updatePostProcess(int root, int left, int right, int from, int to, long delta,
                                                  int middle);

        protected abstract void updatePreProcess(int root, int left, int right, int from, int to, long delta,
                                                 int middle);

        protected abstract void updateFull(int root, int left, int right, int from, int to, long delta);

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

        public void update(int from, int to, long delta) {
            update(0, 0, size - 1, from, to, delta);
        }

        protected void update(int root, int left, int right, int from, int to, long delta) {
            if (left > to || right < from) {
                return;
            }
            if (left >= from && right <= to) {
                updateFull(root, left, right, from, to, delta);
                return;
            }
            int middle = (left + right) >> 1;
            updatePreProcess(root, left, right, from, to, delta, middle);
            update(2 * root + 1, left, middle, from, to, delta);
            update(2 * root + 2, middle + 1, right, from, to, delta);
            updatePostProcess(root, left, right, from, to, delta, middle);
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
}