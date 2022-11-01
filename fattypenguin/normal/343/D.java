import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author sheep
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        firstEdge = new Edge[n];
        for (int i = 0; i < n - 1; ++i) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            new Edge(u, v);
            new Edge(v, u);
        }
        timeStamp = 0;
        begin = new int[n];
        end = new int[n];
        getDfsOrder(0, -1);
//        for (int i = 0; i < n; ++i) {
//            out.println(begin[i] + " " + end[i]);
//        }

        IntervalTree fillTree = new IntervalTree(n);
        IntervalTree emptyTree = new IntervalTree(n);
        int m = in.nextInt();
        for (int i = 1; i <= m; ++i) {
            int op = in.nextInt();
            int node = in.nextInt() - 1;
            switch (op) {
                case 1: {
                    fillTree.insert(begin[node], end[node], i);
                    break;
                }
                case 2: {
                    emptyTree.insert(begin[node], i);
                    break;
                }
                case 3: {
                    int lastFillTime = fillTree.getMaxValue(begin[node], begin[node]);
//                    out.println("begin = " + begin[node]);
                    int lastEmptyTime = emptyTree.getMaxValue(begin[node], end[node]);
//                    out.println(lastEmptyTime + " " + lastFillTime);
                    if (lastFillTime == Integer.MIN_VALUE || lastEmptyTime > lastFillTime) {
                        out.println(0);
                    } else {
                        out.println(1);
                    }
                    break;
                }
                default: throw new RuntimeException();
            }
        }

    }

    private int timeStamp;
    private int[] begin, end;

    private void getDfsOrder(int x, int father) {
        begin[x] = timeStamp++;
        for (Edge e = firstEdge[x]; e != null; e = e.next) {
            if (e.to != father) {
                getDfsOrder(e.to, x);
            }
        }
        end[x] = timeStamp - 1;
    }

    Edge firstEdge[];

    private class Edge {
        int to;
        Edge next;

        public Edge(int from, int to) {
            this.to = to;
            this.next = firstEdge[from];
            firstEdge[from] = this;
        }
    }


    static class IntervalTree {
        int size;
        int val[], cover[];

        IntervalTree(int length) {
            this.size = length;
            val = new int[length * 4 + 100];
            cover = new int[length * 4 + 100];
            Arrays.fill(val, Integer.MIN_VALUE);
            Arrays.fill(cover, Integer.MIN_VALUE);
        }

        private void down(int x) {
            if (cover[x] != Integer.MIN_VALUE) {
                cover[x * 2] = Math.max(cover[x * 2], cover[x]);
                val[x * 2] = Math.max(val[x * 2], cover[x]);
                cover[x * 2 + 1] = Math.max(cover[x * 2 + 1], cover[x]);
                val[x * 2 + 1] = Math.max(val[x * 2 + 1], cover[x]);
                cover[x] = Integer.MIN_VALUE;
            }
        }

        int getMaxValue(int left, int right, int l, int r, int x) {
            if (l <= left && r >= right) {
                return val[x];
            }
            int mid = (left + right) >> 1;
            down(x);
            int ret = Integer.MIN_VALUE;
            if (l <= mid) ret = getMaxValue(left, mid, l, r, x * 2);
            if (r > mid) ret = Math.max(ret, getMaxValue(mid + 1, right, l, r, x * 2 + 1));
            return ret;
        }

        int getMaxValue(int left, int right) {
            return getMaxValue(0, size - 1, left, right, 1);
        }

        void insert(int left, int right, int pos, int x, int value) {
            if (left == right) {
                val[x] = Math.max(val[x], value);
                return;
            }

            int mid = (left + right) >> 1;
            down(x);
            if (pos <= mid) {
                insert(left, mid, pos, x * 2, value);
            } else {
                insert(mid + 1, right, pos, x * 2 + 1, value);
            }

            val[x] = Math.max(val[x * 2], val[x * 2 + 1]);
        }
        void insert(int left, int right, int l, int r, int x, int value) {
            if (l <= left && r >= right) {
                val[x] = Math.max(val[x], value);
                cover[x] = Math.max(cover[x], value);
//                System.err.println("left = " + left + " right = " + right + " value = " + value);
                return;
            }

            int mid = (left + right) >> 1;
            down(x);
            if (l <= mid) {
                insert(left, mid, l, r, x * 2, value);
            }
            if (r > mid) {
                insert(mid + 1, right, l, r, x * 2 + 1, value);
            }

            val[x] = Math.max(val[x * 2], val[x * 2 + 1]);
        }

        void insert(int pos, int value) {
            insert(0, size - 1, pos, 1, value);
        }

        void insert(int l, int r, int value) {
//            System.err.println(l + " " + r + " " + value);
            insert(0, size - 1, l, r, 1, value);
        }


    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }