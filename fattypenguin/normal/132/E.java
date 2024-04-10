import java.io.*;
import java.util.*;
import java.util.concurrent.ConcurrentLinkedQueue;

public class Main 
{
    public static int getBits(int x)
    {
        int ret = 0;
        for (;x!=0;x-=(x&-x))
            ++ret;
        return ret;
    }
    public static void main(String args[]) throws Exception
    {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext())
        {           
            int n = cin.nextInt(), m = cin.nextInt(), total = 0;
            int a[] = new int[n], pre[] = new int[n];
            HashMap<Integer,Integer> hash = new HashMap<Integer,Integer>();
            hash.clear();
            for (int i = 0;i < n;++i)
            {
                a[i] = cin.nextInt();
                total += getBits(a[i]);
                if (hash.get(a[i]) == null)
                    pre[i] = -1;
                else pre[i] = hash.get(a[i]);
                hash.put(a[i], i);
            }
            
            MinCostMaxFlow flow = new MinCostMaxFlow(2*n+2,2*n,2*n+1);
            int s = 2 * n, t = 2*n + 1;
            for (int i = 0;i < n;++i)
            {
                flow.insert(i, i+n, 1, -10000);
                flow.insert(i, i+n, 1000, 0);
                if (i != n-1) flow.insert(i+n, i+1, 1000, 0);
                if (pre[i] != -1)
                    flow.insert(pre[i]+n, i, 1, - getBits(a[i]));
            }
            flow.insert(s, 0, m, 0);
            flow.insert(2*n-1, t, m, 0);
            
            flow.minCostMaxFlow();
            
        //  System.out.println(flow.flow);
        //  System.out.println(flow.cost);
            
            int ans = - 10000 * n - flow.getCost();

            hash.clear();
            int stand[] = new int[m]; 
            Arrays.fill(stand, -1);
            
            ArrayList<String> pot = new ArrayList<String>();
            
            for (int i = 0;i < n;++i)
            {
                int empty = -1;
                for (int j = 0;j < m;++j)
                    if (stand[j] == -1)
                    {
                        empty = j;
                        break;
                    }
                if (hash.get(a[i]) == null && -1 == empty) throw new Exception();
                if (hash.get(a[i]) == null)
                {
                    hash.put(a[i], empty);
                    stand[empty] = a[i];
                    pot.add((char)('a'+empty)+"="+a[i]);
                }
                pot.add("print("+(char)('a'+hash.get(a[i]))+")");
                boolean flag = false;
                for (MinCostMaxFlow.Edge e = flow.vertex[i+n]; e != null; e = e.next)
                    if (e.c == 0 && e.w < 0)
                    {
                    //  System.out.println(i+" "+e.v);
                        flag = true;
                        break;
                    }
                if (!flag)
                {
                    stand[hash.get(a[i])] = -1;
                    hash.remove(a[i]);
                }
            }
            System.out.println(pot.size()+" "+(total-ans));
            for (String ss : pot)
                System.out.println(ss);
        }       
    }   
}

class MinCostMaxFlow
{
    public class Edge
    {
        public int u,v,c,w;
        public Edge next,r;
        
        public Edge(int u,int v,int c,int w)
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
        public int dis,bb;
        public Info pre;
        public boolean in;
        public Edge belong;
        void reset()
        {
            dis = 1<<30;
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
    public int s, t, n, cost, flow;
    
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
    
    public void insert(int u,int v,int c,int w)
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
                if (e.c > 0 && node[e.v].dis > node[now].dis + e.w)
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
        return node[t].dis < (1 << 30);
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
        int flow = 0, cost = 0, tmp;
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
    
    public int getCost()
    {
        return cost;
    }
}