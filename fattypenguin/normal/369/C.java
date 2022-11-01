import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        first = new Edge[n];
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            u = in.nextInt() - 1;
            v = in.nextInt() - 1;
            w = in.nextInt();
            new Edge(u, v, w);
            new Edge(v, u, w);
        }
        hasEdge = new boolean[n];
        color = new int[n];
        go(0, -1);
        answer = new ArrayList<Integer>();
        inSet = new boolean[n];
        find(0, -1);
        out.println(answer.size());
        for (int i = 0; i < answer.size(); ++i) {
            if (i > 0) out.print(" ");
            out.print(answer.get(i) + 1);
        }
        out.println();
    }

    int[] color;
    boolean[] inSet;
    ArrayList<Integer> answer;

    private void go(int x, int fa) {
        for (Edge e = first[x]; e != null; e = e.next) {
            if (e.to != fa) {
                if (e.w == 2) {
                    hasEdge[x] = true;
                }
                color[e.to] = e.w;
                go(e.to, x);
                hasEdge[x] |= hasEdge[e.to];
            }
        }
    }

    private void find(int x, int fa) {
        if (!hasEdge[x]) {
            if (fa != -1 && !inSet[x] && color[x] == 2) {
                answer.add(x);
                inSet[x] = true;
            }
            return;
        }
        boolean isLeaf = true;
        for (Edge e = first[x]; e != null; e = e.next) {
            if (e.to != fa) {
                find(e.to, x);
                isLeaf = false;
            }
        }
    }

    boolean[] hasEdge;
    Edge first[];

    class Edge
    {
        int to, w;
        Edge next;

        public Edge(int from, int to, int w) {
            // TODO Auto-generated constructor stub
            this.to = to;
            this.w = w;
            this.next = first[from];
            first[from] = this;
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