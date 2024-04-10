import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.NoSuchElementException;

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
        GKrestikiNolikiNaDereve solver = new GKrestikiNolikiNaDereve();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class GKrestikiNolikiNaDereve {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] u = new int[n - 1];
            int[] v = new int[n - 1];
            in.readIntArrays(u, v);
            MiscUtils.decreaseByOne(u, v);
            char[] color = in.readCharArray(n);
            if (ArrayUtils.count(color, 'W') >= 3) {
                out.printLine("White");
                return;
            }
            Graph graph = BidirectionalGraph.createGraph(n, u, v);
            int[] degree = new int[n];
            for (int i = 0; i < n - 1; i++) {
                degree[u[i]]++;
                degree[v[i]]++;
            }
            int qty3 = 0;
            for (int i = 0; i < n; i++) {
                if (degree[i] > 3) {
                    out.printLine("White");
                    return;
                }
                if (degree[i] == 3) {
                    qty3++;
                }
            }
            if (qty3 + ArrayUtils.count(color, 'W') >= 3) {
                out.printLine("White");
                return;
            }
            if (ArrayUtils.count(color, 'W') == 2) {
                if (n % 2 == 1) {
                    out.printLine("White");
                    return;
                }
                for (int i = 0; i < n; i++) {
                    if (color[i] == 'W' && degree[i] > 1) {
                        out.printLine("White");
                        return;
                    }
                }
                out.printLine("Draw");
                return;
            }
            if (n <= 3) {
                out.printLine("Draw");
                return;
            }
            for (int i = 0; i < n; i++) {
                if (degree[i] == 3) {
                    int q = 0;
                    for (int j = graph.firstOutbound(i); j != -1; j = graph.nextOutbound(j)) {
                        if (degree[graph.destination(j)] > 1) {
                            q++;
                        }
                    }
                    if (q >= 2) {
                        out.printLine("White");
                        return;
                    }
                }
            }
            LCA lca = new LCA(graph);
            if (ArrayUtils.count(color, 'W') == 1) {
                int w = ArrayUtils.find(color, 'W');
                if (degree[w] > 1) {
                    out.printLine("White");
                    return;
                }
                int d3 = ArrayUtils.find(degree, 3);
                if (d3 != -1 && lca.getPathLength(w, d3) % 2 == 1) {
                    out.printLine("White");
                    return;
                }
                out.printLine("Draw");
                return;
            }
            if (qty3 <= 1) {
                out.printLine("Draw");
                return;
            }
            int d1 = ArrayUtils.find(degree, 3);
            degree[d1] = 0;
            int d2 = ArrayUtils.find(degree, 3);
            if (lca.getPathLength(d1, d2) % 2 == 0) {
                out.printLine("White");
            } else {
                out.printLine("Draw");
            }
        }

    }

    static class CharArray extends CharAbstractStream implements CharList {
        private char[] data;

        public CharArray(char[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public char get(int at) {
            return data[at];
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

    }

    static interface IntCollection extends IntStream {
        public int size();

    }

    static interface CharList extends CharReversableCollection {
        public abstract char get(int index);

        public abstract void removeAt(int index);

        default public CharIterator charIterator() {
            return new CharIterator() {
                private int at;
                private boolean removed;

                public char value() {
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

        default public int find(char value) {
            int size = size();
            for (int i = 0; i < size; i++) {
                if (get(i) == value) {
                    return i;
                }
            }
            return -1;
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

        public int getPathLength(int first, int second) {
            return level[first] + level[second] - 2 * level[getLCA(first, second)];
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

    static interface IntReversableCollection extends IntCollection {
    }

    static abstract class CharAbstractStream implements CharStream {
        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (CharIterator it = charIterator(); it.isValid(); it.advance()) {
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
            if (!(o instanceof CharStream)) {
                return false;
            }
            CharStream c = (CharStream) o;
            CharIterator it = charIterator();
            CharIterator jt = c.charIterator();
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
            for (CharIterator it = charIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }

    }

    static interface CharCollection extends CharStream {
        public int size();

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

        public char[] readCharArray(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
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

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
        }

        public String next() {
            return readString();
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

    static interface CharIterator {
        public char value() throws NoSuchElementException;

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

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

    }

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void removeAt(int index);

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

        default public int find(int value) {
            int size = size();
            for (int i = 0; i < size; i++) {
                if (get(i) == value) {
                    return i;
                }
            }
            return -1;
        }

    }

    static interface CharStream extends Iterable<Character>, Comparable<CharStream> {
        public CharIterator charIterator();

        default public Iterator<Character> iterator() {
            return new Iterator<Character>() {
                private CharIterator it = charIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Character next() {
                    char result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(CharStream c) {
            CharIterator it = charIterator();
            CharIterator jt = c.charIterator();
            while (it.isValid() && jt.isValid()) {
                char i = it.value();
                char j = jt.value();
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

        default public int count(char value) {
            int result = 0;
            for (CharIterator it = charIterator(); it.isValid(); it.advance()) {
                if (it.value() == value) {
                    result++;
                }
            }
            return result;
        }

    }

    static class ArrayUtils {
        public static int count(char[] array, char value) {
            return new CharArray(array).count(value);
        }

        public static int find(int[] array, int value) {
            return new IntArray(array).find(value);
        }

        public static int find(char[] array, char value) {
            return new CharArray(array).find(value);
        }

    }

    static interface CharReversableCollection extends CharCollection {
    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }
}