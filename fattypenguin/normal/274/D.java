import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collection;
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
    Edge first[];

    class Edge
    {
        int to;
        Edge next;

        public Edge(int from, int to) {
            // TODO Auto-generated constructor stub
          //  System.err.println("an edge from " + from + " " + to);
            this.to = to;
            this.next = first[from];
            first[from] = this;
        }
    }
    int column[];
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int nodes = n * m;
        first = new Edge[m + 4 * nodes];
        int totalNodes = first.length;
        column = new int[m];
        int last = m;

        for (int i = 0; i < n; ++i) {
            Integer order[] = new Integer[m];
            for (int j = 0; j < m; ++j) {
                order[j] = j;
                column[j] = in.nextInt();
            }
            Arrays.sort(order, new Comparator<Integer>() {
                @Override
                public int compare(Integer u, Integer v) {
                    return column[u] - column[v];
                }
            });

            ++last;
            for (int now = 0; now < m; ) {

                int next = now;
                while (next < m && column[order[now]] == column[order[next]]) {
                    ++next;
                }

                if (column[order[now]] != -1) {
                    for (int k = now; k < next; ++k) {
                        new Edge(last, order[k]);
                    }

                    ++last;
                    for (int k = now; k < next; ++k) {
                        new Edge(order[k], last);
                    }

                }

                now = next;
            }

        }

        Queue<Integer> q = new LinkedList<Integer>();
        int deg[] = new int[totalNodes];
        for (int i = 0; i < totalNodes; ++i) {
            for (Edge e = first[i]; e != null; e = e.next) {
                ++deg[e.to];
            }
        }

        ArrayList<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < totalNodes; ++i) {
            if (deg[i] == 0) {
                q.offer(i);
            }
        }

        int count = 0;

        while (!q.isEmpty()) {
            int now = q.poll();
            ++count;

            if (now < m) {
                result.add(now);
            }

            for (Edge e = first[now]; e != null; e = e.next) {
                --deg[e.to];
                if (0 == deg[e.to]) {
                    q.offer(e.to);
                }
            }
        }

      //  out.println(count + " " + totalNodes + " " + result.size());

        if (count != totalNodes) {
            out.println(-1);
        } else {
            for (Integer it : result) {
                out.print((it + 1) + " ");
            }
            out.println();
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