import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
            int q = in.readInt();
            int[] u = new int[n - 1];
            int[] v = new int[n - 1];
            in.readIntArrays(u, v);
            MiscUtils.decreaseByOne(u, v);
            BidirectionalGraph graph = BidirectionalGraph.createGraph(n, u, v);
            DFSOrder order = new DFSOrder(graph);
            LongIntervalTree tree = new TaskD.ModLongIntervalTree(n);
            int[] len = new int[n];
            for (int i = 0; i < n; i++) {
                len[order.position[i]] = order.end[i] - order.position[i] + 1;
            }
            int[] parent = new int[n];
            int[] son = new int[n];
            Arrays.fill(son, -1);
            parent[0] = -1;
            for (int i = 1; i < n; i++) {
                for (int j = graph.firstOutbound(i); j != -1; j = graph.nextOutbound(j)) {
                    if (len[order.position[graph.destination(j)]] > len[order.position[i]]) {
                        parent[order.position[i]] = order.position[graph.destination(j)];
                        if (len[order.position[graph.destination(j)]] <= 2 * len[order.position[i]]) {
                            son[order.position[graph.destination(j)]] = order.position[i];
                        }
                    }
                }
            }
            int[] id = new int[n];
            Arrays.fill(id, -1);
            int[] at = new int[n];
            int[] sz = new int[n];
            for (int i = 0; i < n; i++) {
                if (id[i] == -1) {
                    int ln = 0;
                    int cur = i;
                    while (parent[cur] != -1 && son[parent[cur]] == cur && id[cur] == -1) {
                        cur = parent[cur];
                        ln++;
                    }
                    if (id[cur] != -1) {
                        ln += at[cur];
                        cur = id[cur];
                    }
                    int root = cur;
                    sz[root] = Math.max(sz[root], ln + 1);
                    cur = i;
                    while (parent[cur] != -1 && son[parent[cur]] == cur && id[cur] == -1) {
                        at[cur] = ln--;
                        id[cur] = root;
                        cur = parent[cur];
                    }
                    if (id[cur] == -1) {
                        id[cur] = root;
                        at[cur] = ln;
                    }
                }
            }
            TaskD.ModLongIntervalTree[] trees = new TaskD.ModLongIntervalTree[n];
            for (int i = 0; i < n; i++) {
                if (id[i] == i) {
                    trees[i] = new TaskD.ModLongIntervalTree(sz[i]);
                }
            }
            long rev = IntegerUtils.reverse(n, MiscUtils.MODF);
            long[] exact = new long[n];
            for (int i = 0; i < q; i++) {
                int type = in.readInt();
                if (type == 1) {
                    int vertex = in.readInt() - 1;
                    int d = in.readInt();
                    tree.update(order.position[vertex], order.end[vertex], d);
                    vertex = order.position[vertex];
                    exact[vertex] += d;
                    exact[vertex] %= MiscUtils.MODF;
                    if (son[vertex] != -1) {
                        trees[id[vertex]].update(at[son[vertex]], at[son[vertex]],
                                (long) (n - len[son[vertex]]) * d % MiscUtils.MODF);
                    }
                    long delta = (long) len[vertex] * d % MiscUtils.MODF;
                    while (true) {
                        vertex = parent[id[vertex]];
                        if (vertex == -1) {
                            break;
                        }
                        if (son[vertex] != -1) {
                            trees[id[vertex]].update(at[son[vertex]], at[son[vertex]], delta);
                        }
                    }
                } else {
                    int vertex = in.readInt() - 1;
                    long answer =
                            tree.query(order.position[vertex], order.end[vertex]) - tree.query(order.position[vertex],
                                    order.position[vertex]) * len[order.position[vertex]] % MiscUtils.MODF;
                    vertex = order.position[vertex];
                    long lastLen = 0;
                    long treeLastLen = len[vertex];
                    long ignore = tree.query(vertex, vertex + len[vertex] - 1);
//                answer += exact[vertex] * (n - len[vertex]) % MODF;
                    while (vertex != -1) {
                        answer += exact[vertex] * (n - lastLen) % MiscUtils.MODF;
                        answer += trees[id[vertex]].query(0, at[vertex]);
                        answer += tree.query(vertex, vertex + len[vertex] - 1) - ignore -
                                tree.query(vertex, vertex) * (len[vertex] - treeLastLen) % MiscUtils.MODF;
                        if (id[vertex] == 0) {
                            break;
                        }
                        treeLastLen = lastLen = len[id[vertex]];
                        vertex = id[vertex];
                        ignore = tree.query(vertex, vertex + len[vertex] - 1);
                        vertex = parent[vertex];
                    }
                    answer %= MiscUtils.MODF;
                    if (answer < 0) {
                        answer += MiscUtils.MODF;
                    }
                    answer *= rev;
                    answer %= MiscUtils.MODF;
                    out.printLine(answer);
                }
            }
        }

        private static class ModLongIntervalTree extends LongIntervalTree {
            public ModLongIntervalTree(int n) {
                super(n);
            }

            protected long joinValue(long left, long right) {
                long val = (left + right);
                if (val >= MiscUtils.MODF) {
                    val -= MiscUtils.MODF;
                }
                return val;
            }

            protected long joinDelta(long was, long delta) {
                long val = was + delta;
                if (val >= MiscUtils.MODF) {
                    val -= MiscUtils.MODF;
                }
                return val;
            }

            protected long accumulate(long value, long delta, int length) {
                return (value + delta * length) % MiscUtils.MODF;
            }

            protected long neutralValue() {
                return 0;
            }

            protected long neutralDelta() {
                return 0;
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

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static interface Edge {
    }

    static class IntegerUtils {
        private static long _x;
        private static long _y;

        public static long trueMod(long a, long b) {
            a %= b;
            a += b;
            a %= b;
            return a;
        }

        public static long reverse(long number, long modulo) {
            extGcd(number, modulo);
            return trueMod(_x, modulo);
        }

        private static long extGcd(long a, long b) {
            if (a == 0) {
                _x = 0;
                _y = 1;
                return b;
            }
            long d = extGcd(b % a, a);
            long nx = _y - (b / a) * _x;
            _y = _x;
            _x = nx;
            return d;
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

    static class MiscUtils {
        public static final int MODF = 998_244_353;

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

    static class BidirectionalGraph extends Graph {
        public int[] transposedEdge;

        public BidirectionalGraph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public BidirectionalGraph(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            transposedEdge = new int[2 * edgeCapacity];
        }

        public static BidirectionalGraph createGraph(int vertexCount, int[] from, int[] to) {
            BidirectionalGraph graph = new BidirectionalGraph(vertexCount, from.length);
            for (int i = 0; i < from.length; i++) {
                graph.addSimpleEdge(from[i], to[i]);
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
}