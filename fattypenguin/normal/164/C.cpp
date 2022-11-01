/*================================================
| 
| input:    S, T, n - source, sink
| caution:  1.SPFA
|           2..
|             .(dis[T]<0)
===========================================*/

#include <assert.h>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>

#include <stdio.h>
#include <string.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
/*================================================
| 
| input:    S, T, n - source, sink
| caution:  1.SPFA
|           2..
|             .(dis[T]<0)
===========================================*/

const long long INFI = 1ll << 40ll;
struct NetFlow
{
    int tot, S, T, n;   //n
    int Q[2000000]; //spfa
    struct Edge
    {
        int flow, next, pot, cost;
    }edge[1000007];
    struct Node
    {
        int pre, arp, head;
        long long dis;
        bool inteam;
    }node[10007];
    bool spfa()
    {
        for (int i=0;i<=n;i++) {
            node[i].dis = INFI;
            node[i].inteam = 0;
        }
        int h = 1,t = 1,v,u;
        Q[1] = S;
        node[S].dis = 0;
        while (h <= t)
        {
            v = Q[h];
            node[v].inteam = false;
            for (int e=node[v].head;e!=-1;e=edge[e].next)
            if (edge[e].flow > 0 && node[v].dis + edge[e].cost < node[ edge[e].pot ].dis)
            {
                u = edge[e].pot;
                node[u].dis = node[v].dis + edge[e].cost;
                node[u].pre = v;
                node[u].arp = e;
                if (!node[u].inteam)
                {
                    node[u].inteam = true;
                    Q[++t] = u;
                }
            }
            h++;
        }
        return node[T].dis < INFI;
    }
    int argument()
    {
        int delta = 0x7f7f7f7f;
        for (int v=T;v!=S;v=node[v].pre)
        {
            if (edge[node[v].arp].flow < delta)
                delta = edge[node[v].arp].flow;
        }
        for (int v=T;v!=S;v=node[v].pre)
        {
            edge[node[v].arp].flow -= delta;
            edge[node[v].arp^1].flow += delta;
        }
        return delta;
    }
    long long mincost_flow(int &flow)
    {
        long long ret = 0;
        int ff = 0,tmp;
        while (spfa() && node[T].dis < 0)               //
        {
        //    cout << node[T].dis << endl;
        //  cout << "tmp = " << tmp << endl;
            tmp = argument();
            ff += tmp;              //
            ret += node[T].dis * tmp;  //
        }
        flow = ff;
        return ret;
    }
    void addedge(int a,int b,int c,int d)
    {
        edge[++tot].pot = b;
        edge[tot].flow = c;
        edge[tot].cost = d;
        edge[tot].next = node[a].head;

        node[a].head = tot;
    }
    void connect(int a,int b,int c,int d)
    {
        addedge(a,b,c,d);
        addedge(b,a,0,-d);
    }
    void reset()  //
    {
        tot = -1;
        for (int i=0;i<=10006;i++)
            node[i].head = -1;
    }
} Graph;

const int maxn=20000;
const int maxint = 1<<30;

void get_min(int &a,int b){
    if(b<a) a=b;
}

void get_max(int &a,int b){
    if(b>a) a=b;
}

int NEXT(int a,int b){
    return a%b;
}

struct Graph0{
    struct Adj{
        int v,f,c,w,b;
        Adj(int _v,int _c,int _w,int _b):v(_v),f(0),c(_c),w(_w),b(_b){}
    }*st[maxn];
    vector<Adj> adj[maxn];
    int n;
    void clear(){
        for(int i=0;i<n;i++){
            adj[i].clear();
        }
        n=0;
    }

    void insert(int u,int v,int c,int w,int d=0){
        get_max(n,max(u,v)+1);
        adj[u].push_back(Adj(v,c,w,adj[v].size()));
        adj[v].push_back(Adj(u,0,-w,adj[u].size()-1));
        if(d){
            adj[v].push_back(Adj(u,c,w,adj[u].size()));
            adj[u].push_back(Adj(v,0,-w,adj[v].size()-1));
        }
    }
    pair<int,int> mcmf(int S,int T){
        int d;
        int flow=0,cost=0;
        while((d=bell(S,T))){
            flow+=d;
            for(int v=T;v!=S;v=adj[st[v]->v][st[v]->b].v){
                cost+=st[v]->w*d;
                st[v]->f+=d;
                adj[st[v]->v][st[v]->b].f-=d;
            }
        }
        return make_pair(flow,cost);
    }
    int bell(int S,int T){
        int d[maxn],bfs[maxn],hash[maxn];
        fill(hash,hash+n,0);
        fill(d,d+n,maxint);
        hash[S]=1;d[S]=0;bfs[0]=S;
        for(int s=0,t=1;s!=t;hash[bfs[s]]=0,s=NEXT(s+1,n)){
            int v=bfs[s];
            for(vector<Adj>::iterator it=adj[v].begin();it!=adj[v].end();it++){
                if(it->f < it->c&&d[v]+it->w < d[it->v]){
                    d[it->v]=d[v]+it->w;
                    st[it->v]=&(*it);
                    if(hash[it->v]==0){
                        hash[it->v]=1;
                        bfs[t]=it->v;
                        t=NEXT(t+1,n);
                    }
                }
            }
        }
        if(d[T]==maxint){
            return 0;
        }
        int ans=maxint;
        for(int v=T;v!=S;v=adj[st[v]->v][st[v]->b].v){
            get_min(ans,st[v]->c - st[v]->f);
        }
        return ans;
    }
}G;


map<int, int> has;
int stand[10007], yy[10007];

struct pt3
{
    int x, y, z;
} task[10007];

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    REP(i, n) cin >> task[i].x >> task[i].y >> task[i].z;
    REP(i, n) has[task[i].x]=1, has[task[i].x + task[i].y] = 1;
    int total = 0;
    TR(it, has)
    {
        stand[total] = it->first;
        it->second = total++;
    }
    int m0 = total;
    int s = total++, t = total++;
    Graph.reset();
    Graph.n = Graph.tot = total;
    Graph.S = s, Graph.T = t;

    G.n = total;
    G.clear();
   // cout << "K = " << k << endl;
  //  cout << "total = " << total << " S = " << s << " T = " << t << endl;
    REP(i, n)
    {
        yy[i] = has[task[i].x+task[i].y];
   /*     for (int j = 0; j < m0; ++j)
            if (stand[j] >= task[i].x+task[i].y)
            {
                yy[i] = j;
                break;
            }*/
    }
    REP(i, m0-1)
    {
        Graph.connect(i, i+1, n, 0);
        G.insert(i, i+1, n, 0);
   //     cout << i << " " << i+1 << endl;
    }
    REP(i, n)
    {
       // assert(has[task[i].x+task[i].y] > has[task[i].x]);
       assert(task[i].x+task[i].y > task[i].x);
        Graph.connect(has[task[i].x], yy[i], 1, -task[i].z);
        G.insert(has[task[i].x], yy[i], 1, -task[i].z);
    }
    G.insert(s, 0, k, 0);
    G.insert(m0-1, t, k, 0);

    Graph.connect(s, 0, k, 0);
    Graph.connect(m0-1, t, k, 0);
    //cout << s << " " << 0 << endl;
   // cout << m0-1 << " " << t << endl;
    int fl = 0;
   // int ans = Graph.mincost_flow(fl);
    G.mcmf(s, t);
    //cout << fl << endl;
    //cout << ans << endl;
    REP(i, n)
    {
        bool ok = false;
        int v = has[task[i].x], w = yy[i];
        /*
        for (int e=Graph.node[v].head;e!=-1;e=Graph.edge[e].next)
            if (Graph.edge[e].flow == 0 && Graph.edge[e].pot == w && Graph.edge[e].cost == -task[i].z)
            {
                ++Graph.edge[e].flow;
                ok = true;
                break;
            }
        */
        for(vector<Graph0::Adj>::iterator it=G.adj[v].begin();it!=G.adj[v].end();it++)
            if (it->f == it->c && it->v == w && it->w == -task[i].z)
            {
                --(it->f);
                ok = true;
                break;
            }
        if (i) cout << " ";
        if (ok) cout << 1; else cout << 0;
    }
    cout << endl;
    return 0;
}