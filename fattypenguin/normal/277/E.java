import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Queue;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    private double dis(int x1, int y1, int x2, int y2) {
        return Math.sqrt((x1 - x2) * (double)(x1 - x2) + (y1 - y2) * (double)(y1 - y2));
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        MinCostMaxFlow flow = new MinCostMaxFlow(2 * n + 2, 2 * n, 2 * n + 1);
        int source = 2 * n, target = source + 1;
        int x[] = new int[n];
        int y[] = new int[n];
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }

        for (int i = 0; i < n; ++i) {
            int top = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && y[j] > y[i]) {
                    ++top;
                    flow.insert(2 * i, 2 * j + 1, 1, dis(x[i], y[i], x[j], y[j]));
                }
            }

            if (top != 0) flow.insert(source, 2 * i, 1, 0);
            flow.insert(2 * i + 1, target, 2, 0);
        }

        flow.minCostMaxFlow();
        if (flow.getFlow() != n - 1) {
            out.println(-1);
            return;
        }

        out.printf("%.12f\n", flow.getCost());
    }
}

class MinCostMaxFlow
{
    public class Edge
    {
        public int u,v,c;
        public double w;
        public Edge next,r;

        public Edge(int u,int v,int c,double w)
        {
            this.u = u;
            this.v = v;
            this.c = c;
            this.w = w;
            next = r = null;
        }
    }

    class Info
    {
        public double dis;
        public int bb;
        public Info pre;
        public boolean in;
        public Edge belong;
        void reset()
        {
            dis = 1e50;
            in = false;
            pre = null;
            belong = null;
        }
    }

    public MinCostMaxFlow(int n,int s,int t)
    {
        init(n,s,t);
    }

    public Edge vertex[];
    public Info node[];
    public int s, t, n, flow;
    public double cost;

    public void init(int n,int s,int t)
    {
        vertex = new Edge[n+1];
        node = new Info[n+1];
        this.s = s;
        this.t = t;
        this.n = n;
        for (int i = 0;i < n;++i)
            node[i] = new Info();
    }

    public void insert(int u,int v,int c,double w)
    {
        Edge e = new Edge(u,v,c,w);
        Edge r = new Edge(v,u,0,-w);
        e.r = r;
        r.r = e;
        e.next = vertex[u];
        vertex[u] = e;
        r.next = vertex[v];
        vertex[v] = r;
    }

    public boolean bellmanFord()
    {
        for (int i = 0;i < n;++i)
            node[i].reset();
        Queue<Integer> Q = new ConcurrentLinkedQueue<Integer>();
        Q.offer(s);
        node[s].dis = 0;
        while (!Q.isEmpty())
        {
            int now = Q.poll();
            for (Edge e = vertex[now]; e != null; e = e.next)
                if (e.c > 0 && node[e.v].dis > node[now].dis + e.w + 1e-10)
                {
                    node[e.v].dis = node[now].dis + e.w;
                    node[e.v].pre = node[now];
                    node[e.v].belong = e;
                    node[e.v].bb = now;
                    if (!node[e.v].in)
                    {
                        Q.offer(e.v);
                        node[e.v].in = true;
                    }
                }
            node[now].in = false;
        }
        return node[t].dis < 1e30;
    }

    public int augPath()
    {
        int delta = Integer.MAX_VALUE;
        for (Info i = node[t];i.belong != null;i = i.pre)
            delta = Math.min(delta, i.belong.c);
        for (Info i = node[t];i.belong != null;i = i.pre)
        {
            i.belong.c -= delta;
            i.belong.r.c += delta;
        }
        return delta;
    }

    public void minCostMaxFlow()
    {
        int flow = 0, tmp;
        double cost = 0;
        while (bellmanFord())
        {
            tmp = augPath();
            flow += tmp;
            cost += tmp * node[t].dis;
        }
        this.flow = flow;
        this.cost = cost;
    }

    public int getFlow()
    {
        return flow;
    }

    public double getCost()
    {
        return cost;
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