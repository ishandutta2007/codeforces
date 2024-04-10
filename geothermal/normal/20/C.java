import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.AbstractCollection;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jay Leeds (Library inspired by Egor Kulikov's GitHub contributions)
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
            int n = in.nextInt();
            int m = in.nextInt();

            //int n = 50000;
            //int m = 99998;

            int[] from = new int[m], to = new int[m];
            long[] weights = new long[m];
            for (int i = 0; i < m; i++) {
                from[i] = in.nextInt() - 1;
                to[i] = in.nextInt() - 1;
                weights[i] = in.nextInt();
            }
        
        /*for (int i = 0; i < 49999; i++) {
            from[i] = 0;
            to[i] = i + 1;
            weights[i] = 99998 - 2 * i;
        }
        
        for (int i = 49999; i < m; i++) {
            from[i] = i - 49998;
            to[i] = i - 49999;
            weights[i] = 1;
        }*/


            UDGraph g = UDGraph.createWeightedGraph(n, from, to, weights);

            long[] dist = new long[n];
            int[] parent = new int[n];
            for (int i = 0; i < n; i++) {
                dist[i] = Long.MAX_VALUE;
                parent[i] = -1;
            }
            dist[0] = 0;

            PriorityQueue<TaskC.Pair> q = new PriorityQueue<>();
            q.add(new TaskC.Pair(0, 0));

            while (!q.isEmpty()) {
                TaskC.Pair p = q.poll();
                if (p.priority > dist[p.val]) continue;
                Graph.EdgeIterator e = g.edgesFrom(p.val);
                while (e.hasNext()) {
                    Graph.Edge ed = e.next();
                    long w = ed.getWeight();
                    int next = ed.getDestination();
                    if (dist[p.val] + w < dist[next]) {
                        dist[next] = dist[p.val] + w;
                        parent[next] = p.val;
                        q.add(new TaskC.Pair(next, dist[next]));
                    }
                }
            }
            ArrayList<Integer> path = new ArrayList<>();
            path.add(n - 1);
            while (parent[path.get(path.size() - 1)] != -1) {
                path.add(parent[path.get(path.size() - 1)]);
            }
            if (path.get(path.size() - 1) != 0) {
                out.printLine(-1);
                out.close();
            }
            for (int i = path.size() - 1; i >= 0; i--) {
                out.print((path.get(i) + 1) + " ");
            }
            out.printLine();
        }

        public static class Pair implements Comparable<TaskC.Pair> {
            int val;
            long priority;

            public Pair(int v, long p) {
                val = v;
                priority = p;
            }

            public int compareTo(TaskC.Pair p) {
                return new Long(priority).compareTo(p.priority);
            }

        }

    }

    static class UDGraph extends Graph {
        public UDGraph(int vertexCount) {
            super(vertexCount);
            Graph.ENTRIES_PER_EDGE = 2;
        }

        public UDGraph(int vertexCount, int edgeCapacity) {
            super(vertexCount, edgeCapacity * 2);
            Graph.ENTRIES_PER_EDGE = 2;
        }

        public static UDGraph createWeightedGraph(int vertexCount, int[] from, int[] to, long[] weight) {
            UDGraph graph = new UDGraph(vertexCount, from.length);
            for (int i = 0; i < from.length; i++) {
                graph.addWeightedEdge(from[i], to[i], weight[i]);
            }
            return graph;
        }


        public int addEdge(int from, int to, long weight, long capacity, int reverseEdge) {
            int lastEdgeCount = numEdges;
            super.addEdge(from, to, weight, capacity, lastEdgeCount + 1);
            super.addEdge(to, from, weight, capacity, lastEdgeCount);
            return lastEdgeCount;
        }


        public void removeEdge(int id) {
            super.removeEdge(id);
            super.removeEdge(reverse(id));
        }


        public void setFlag(int id, int bit) {
            super.setFlag(id, bit);
            super.setFlag(reverse(id), bit);
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

        public int nextInt() {
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

    static class Graph {
        protected static int REMOVED_BIT = 0;
        protected static int ENTRIES_PER_EDGE = 1;
        protected int edgeCapacity;
        protected int numEdges;
        protected int numVertices;
        private int[] firstIn;
        private int[] firstOut;
        private int[] nextIn;
        private int[] nextOut;
        private int[] from;
        private int[] to;
        private int[] reverseEdge;
        private int[] flags;
        private long[] weight;
        public long[] capacity;
        private Edge[] edges;

        public Graph(int vertexCount, int edgeCapacity) { //Graph class inspired by Egor Kulikov's GitHub contributions
            numVertices = vertexCount;
            numEdges = 0; //Rewritten and modified by me (Jay Leeds)
            this.edgeCapacity = edgeCapacity;
            firstOut = new int[vertexCount];
            this.numVertices = vertexCount;
            firstIn = new int[vertexCount];
            Arrays.fill(firstOut, -1);
            Arrays.fill(firstIn, -1);
            from = new int[edgeCapacity];
            to = new int[edgeCapacity];
            nextOut = new int[edgeCapacity];
            nextIn = new int[edgeCapacity];
            flags = new int[edgeCapacity];
            capacity = new long[edgeCapacity];
            weight = new long[edgeCapacity];

        }

        public Graph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            allocateEdges(numEdges + 1);
            if (firstOut[fromID] != -1) {
                nextOut[numEdges] = firstOut[fromID]; //Next out from the new edge is the edge that was first before.
            } else nextOut[numEdges] = -1; //First edge coming from this vertex!

            firstOut[fromID] = numEdges;
            if (firstIn != null) {
                if (firstIn[fromID] != -1) {
                    nextIn[numEdges] = firstIn[fromID];
                } else nextIn[numEdges] = -1;
                firstIn[fromID] = numEdges;
            }

            this.from[numEdges] = fromID;
            this.to[numEdges] = toID;

            if (capacity != 0) {
                if (this.capacity == null) {
                    this.capacity = new long[from.length];
                }
                this.capacity[numEdges] = capacity;
            }

            if (weight != 0) {
                if (this.weight == null) {
                    this.weight = new long[from.length];
                }
                this.weight[numEdges] = weight;
            }

            if (reverseEdge != 0) {
                if (this.reverseEdge == null) {
                    this.reverseEdge = new int[from.length];
                    Arrays.fill(this.reverseEdge, 0, numEdges, -1);
                }
                this.reverseEdge[numEdges] = reverseEdge;
            } else {
                if (this.reverseEdge != null) this.reverseEdge[numEdges] = -1;
            }

            if (edges != null) edges[numEdges] = createEdge(numEdges);
            return numEdges++;
        }

        public final int addFlowWeightedEdge(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int lastCount = numEdges;
                addEdge(to, from, -1 * weight, 0, lastCount + ENTRIES_PER_EDGE);
                return addEdge(from, to, weight, capacity, lastCount);
            }
        }

        public final int addWeightedEdge(int from, int to, long weight) {
            return addFlowWeightedEdge(from, to, weight, 0);
        }

        public final long weight(int id) {
            if (weight == null) return 0;
            return weight[id];
        }

        protected final void initEdges() {
            if (edges == null) {
                edges = new Edge[from.length];
                for (int i = 0; i < numEdges; i++) {
                    edges[i] = createEdge(i);
                }
            }
        }

        public void removeEdge(int id) {
            setFlag(id, REMOVED_BIT);
        }

        public final boolean isRemoved(int id) {
            return isFlagged(id, REMOVED_BIT);
        }

        protected final Edge createEdge(int id) {
            return new Edge(id);
        }

        public final int to(int id) {
            return to[id];
        }

        protected void allocateEdges(int num) {
            if (from.length < num) {
                int newS = Math.max(num, 2 * firstOut.length);
                if (edges != null) edges = addSpace(edges, newS);
                from = addSpace(from, newS);
                to = addSpace(to, newS);
                nextOut = addSpace(nextOut, newS);
                nextIn = addSpace(nextIn, newS);
                flags = addSpace(flags, newS);
                if (weight != null) weight = addSpace(weight, newS);
                if (capacity != null) capacity = addSpace(weight, newS);
                if (reverseEdge != null) reverseEdge = addSpace(reverseEdge, newS);
                if (flags != null) flags = addSpace(flags, newS);
            }
        }

        protected final int[] addSpace(int[] array, int size) {
            int[] result = new int[size];
            System.arraycopy(array, 0, result, 0, array.length);
            return result;
        }

        protected final long[] addSpace(long[] array, int size) {
            long[] result = new long[size];
            System.arraycopy(array, 0, result, 0, array.length);
            return result;
        }

        protected final Edge[] addSpace(Edge[] array, int size) {
            Edge[] result = new Edge[size];
            System.arraycopy(array, 0, result, 0, array.length);
            return result;
        }

        public final boolean isFlagged(int id, int bit) {
            return (flags[id] & (1 << bit)) > 0;
        }

        public void setFlag(int id, int bit) {
            flags[id] |= (1 << bit);
        }

        public final EdgeIterator edgesFrom(final int id) {
            initEdges();
            return new EdgeIterator(id, firstOut, nextOut);
        }

        public final int reverse(int id) {
            if (reverseEdge == null) return -1;
            return reverseEdge[id];
        }

        public class Edge {
            protected int id;

            protected Edge(int id) {
                this.id = id;
            }

            public int getDestination() {
                return to(id);
            }

            public long getWeight() {
                return weight(id);
            }

        }

        public class EdgeIterator implements Iterator<Edge> {
            private int edgeID;
            private final int[] next;
            private int lastID = -1;

            public EdgeIterator(int id, int[] first, int[] next) {
                this.next = next;
                edgeID = nextEdge(first[id]);
            }

            private int nextEdge(int id) {
                while (id != -1 && isRemoved(id)) {
                    id = next[id];
                }

                return id;
            }

            public boolean hasNext() {
                return edgeID != -1;
            }

            public Edge next() {
                if (edgeID == -1) {
                    return null;
                }
                lastID = edgeID;
                edgeID = nextEdge(next[lastID]);
                return edges[lastID];
            }

            public void remove() {
                if (lastID == -1) {
                    return;
                }
                removeEdge(lastID);
                lastID = -1;
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

        public void printLine() {
            writer.println();
        }

        public void printLine(int i) {
            writer.println(i);
        }

        public void close() {
            writer.close();
        }

    }
}