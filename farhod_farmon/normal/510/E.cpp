#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 220;
const int Q = 100100;

using namespace std;


struct edge{
    int a,b,c,flow;
};
const int MAXN = 200200;
const int inf_int = 1e9;
struct Flow{
    vector<int> g[MAXN];
    vector<edge> e;
    inline int add_edge(int a,int b,int c){
        edge e1 = {a,b,c,0};
        edge e2 = {b,a,0,0};
        int id = e.size();
        g[a].push_back(id);
        e.push_back(e1);
        g[b].push_back(id+1);
        e.push_back(e2);
        return id;
    }

    int s,t,n;
    int ptr[MAXN],dis[MAXN],q[MAXN];
    void init(int S,int T,int N){
        s = S;
        t = T;
        n = N;
    }


    bool bfs(){
        fill(dis,dis+n,inf_int);
        dis[s] = 0;
        int qh = 0,qt = 1;
        q[0] = s;
        while(qh<qt){
            int v = q[qh++];
            for(int id:g[v]){
                edge &r = e[id];
                int to = r.b;
                if(r.c > r.flow && dis[to]>dis[v]+1){
                    dis[to] = dis[v]+1;
                    q[qt++] = to;
                }
            }
        }
        return dis[t]!=inf_int;
    }



    int dfs(int v,int flow){
        if(v==t)
            return flow;
        for(;ptr[v]<g[v].size();++ptr[v]){
            int id = g[v][ptr[v]];
            edge &r = e[id];
            if(r.c > r.flow && dis[r.b]==dis[v]+1){
                int pushed = dfs(r.b, min(flow, r.c - r.flow));
                if(pushed){
                    e[id].flow+=pushed;
                    e[id^1].flow-=pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    void delete_all(){
        e.clear();
        for(int i = 0;i<n;++i){
            g[i].clear();
        }
    }

    void clear(){
        int m = e.size();
        for(int i = 0;i<m;++i){
            e[i].flow=0;
        }
    }


    int flow(){
        int res = 0;
        while(bfs()){
            fill(ptr,ptr+n,0);
            while(int pushed = dfs(s,inf_int)){
                res+=pushed;
            }
        }
        return res;
    }

} flow;

int n;
int a[N];
int used[Q];
int id[N][N];
vector < int > v[N];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        for(int i = 2; i < Q; i++) if(!used[i]){
                for(int j = i + i; j < Q; j += i){
                        used[j] = 1;
                }
        }

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int A = 0, B = 0;
        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        if(used[a[i] + a[j]] == 0){
                                if(a[i] & 1){
                                        id[i][j] = flow.add_edge(i, j, 1);
                                } else{
                                        id[i][j] = flow.add_edge(j, i, 1);
                                }
                        }
                }
                if(a[i] & 1){
                        A += 1;
                        flow.add_edge(0, i, 2);
                } else{
                        B += 1;
                        flow.add_edge(i, n + 1, 2);
                }
        }
        flow.init(0, n + 1, n + 2);
        if(A != B || flow.flow() != A * 2){
                cout << "Impossible" << "\n";
                return 0;
        }
        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++) if(!used[a[i] + a[j]]){
                        if(flow.e[id[i][j]].flow == 1){
                                v[i].push_back(j);
                                v[j].push_back(i);
                        }
                }
        }
        vector < int > used(n + 1, 0);
        vector < vector < int > > res;
        for(int i = 1; i <= n; i++) if(!used[i]){
                int x = i;
                res.push_back({});
                while(!used[x]){
                        used[x] = 1;
                        res.back().push_back(x);
                        for(int y: v[x]){
                                if(!used[y]){
                                        x = y;
                                        break;
                                }
                        }
                }
        }
        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.size() << " ";
                for(int x: p) cout << x << " ";
                cout << "\n";
        }
}