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
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int g = in.nextInt();

        int[] gender = new int[n];
        int[] cost = new int[n];

        for (int i = 0; i < n; ++i) {
            gender[i] = in.nextInt();
        }

        for (int i = 0; i < n; ++i) {
            cost[i] = in.nextInt();
        }

        int source = n + m, target = source + 1;
        MaxFlow maxFlow = new MaxFlow(n + m + 2, source, target);

        for (int i = 0; i < n; ++i) {
            if (gender[i] == 0) {
                maxFlow.insert(source, i, cost[i]);
            } else {
                maxFlow.insert(i, target, cost[i]);
            }
        }

        int[][] dogs = new int[m][];
        int[] appGender = new int[m];

        int costSum = 0;
        for (int i = 0; i < m; ++i) {
            int appointedGender = in.nextInt();
            int w = in.nextInt();
            int k = in.nextInt();

            dogs[i] = new int[k];

            appGender[i] = appointedGender;

            for (int j = 0; j < k; ++j) {
                int chosen = in.nextInt() - 1;
                dogs[i][j] = chosen;
                if (appointedGender == 0) {
                    maxFlow.insert(i + n, chosen, 0x3f3f3f3f);
                } else {
                    maxFlow.insert(chosen, i + n, 0x3f3f3f3f);
                }

            }

            Arrays.sort(dogs[i]);

            int isFriend = in.nextInt();

            costSum += w;
            int weight = (isFriend == 1 ? g + w : w);
            if (appointedGender == 0) {
                maxFlow.insert(source, i + n, weight);
            } else {
                maxFlow.insert(i + n, target, weight);
            }
        }

//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (appGender[i] == 0 && appGender[j] == 1) {
//                    if (intersect(dogs[i], dogs[j])) {
//                        maxFlow.insert(i + n, j + n, 0x3f3f3f3f);
//                    }
//                }
//            }
//        }

        out.println(costSum - maxFlow.maxFlow());
    }

    }

class MaxFlow
{
    public class Edge
    {
        public int u,v,c;
        public Edge next,r;

        public Edge(int u,int v,int c)
        {
            this.u = u;
            this.v = v;
            this.c = c;
            next = r = null;
        }
    }

    public Edge vertex[];
    public int height[], nheight[];
    public int s, t, n;

    public void init(int n,int s,int t)
    {
        height = new int[n+1];
        nheight = new int[n+1];
        vertex = new Edge[n+1];
        this.s = s;
        this.t = t;
        this.n = n;
    }

    public MaxFlow(int n,int s,int t)
    {
        init(n,s,t);
    }

    public void insert(int u,int v,int c)
    {
        Edge e = new Edge(u,v,c);
        Edge r = new Edge(v,u,0);
        e.r = r;
        r.r = e;
        e.next = vertex[u];
        vertex[u] = e;
        r.next = vertex[v];
        vertex[v] = r;
    }

    public int augPath(int u,int push)
    {
        if (u == t) return push;
        int flow = push, minheight = n-1;
        for (Edge e = vertex[u]; e != null; e = e.next)
            if (e.c != 0)
            {
                if (height[e.v] + 1 == height[e.u])
                {
                    int delta = flow < e.c ? flow : e.c;
                    if (delta > 0)
                        delta = augPath(e.v,delta);
                    e.c -= delta;
                    e.r.c += delta;
                    flow -= delta;
                    if (0 == flow || height[s] >= n) return push - flow;
                }
                minheight = Math.min(minheight, height[e.v]);
            }
        if (push == flow)
        {
            --nheight[height[u]];
            if (0 == nheight[height[u]]) height[s] = n;
            height[u] = ++minheight;
            ++nheight[height[u]];
        }
        return push - flow;
    }

    public int maxFlow()
    {
        Arrays.fill(height, 0);
        Arrays.fill(nheight, 0);
        nheight[0] = n;
        int flow = 0;
        while (height[s] < n)
            flow += augPath(s,Integer.MAX_VALUE);
        return flow;
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