#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;
const int mod = 998244353;

const int MAXN = 5e3+10;

typedef long long ll;
typedef unsigned long long ull;
int inf_int=1e9;
ll inf_ll=1e17;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
struct Edge{
    int a,b,c,flow,cost;
};
struct MIN_FLOW{
    vector<Edge> e;
    vector<int> g[MAXN];
    int n,s,t;

    int id[MAXN];
    ll dis[MAXN];
    int from[MAXN];
    void init(int N,int S,int T){
        n= N;
        s= S;
        t=T;
    }
    int add_edge(int a,int b,int c,int cost){
        int id = e.size();
        Edge e1 = {a,b,c,0,cost};
        Edge e2 = {b,a,0,0,-cost};
        g[a].pb(e.size());
        e.pb(e1);
        g[b].pb(e.size());;
        e.pb(e2);
        return id;
    }

    ll get_val(int k){
        int flow = 0;
        ll cost = 0;

        while(1){
            queue<int> q;
            fill(id,id+n,0);
            fill(dis,dis+n,inf_ll);
            dis[s]=0;
            id[s]=1;
            q.push(s);
            while(!q.empty()){
                int v = q.front(); q.pop();
                id[v] = 0;
                for(int ind:g[v]){
                    Edge& edge = e[ind];
                    int to = edge.b;
                    if(edge.c >edge.flow && dis[edge.b] > dis[v] + edge.cost){
                        if(id[to] == 0){
                            q.push(to);
                            id[to] = 1;
                        }
                        dis[to] = dis[v] + edge.cost;
                        from[to] = ind;
                    }
                }

            }
            if(dis[t]==inf_ll)
                break;

            int addflow = min(inf_int,k-flow);
            int v = t;
            while(v!=s){
                int ind = from[v];
                addflow = min(addflow,e[ind].c - e[ind].flow);
                v = e[ind].a;
            }

            v = t;
            while(v!=s){
                int ind = from[v];
                cost += 1ll*e[ind].cost * addflow;
                e[ind].flow+=addflow;
                e[ind^1].flow-=addflow;
                v = e[ind].a;
            }
            flow+=addflow;
            if(flow==k)
                break;
        }

        if(flow < k){
                return -1;
        }
        return cost;
    }

} flow;

bool fucked[N];
vector < int > v[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int d, n;
        cin >> d >> n;
        vector < int > a(n, 0);
        for(int i = 0; i < n; i++){
                string s;
                cin >> s;
                for(int j = 0; j < d; j++){
                        if(s[j] == '1'){
                                a[i] |= (1 << j);
                        }
                }
        }
        flow.init(2 * n + 10, 0, 2 * n + 1);

        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        if(i != j && (a[i] & a[j]) == a[i]){
                                flow.add_edge(i + 1, n + j + 1, 1, __builtin_popcount(a[i] ^ a[j]));
                        }
                }
                flow.add_edge(0, n + i + 1, 1, __builtin_popcount(a[i]) + 1);

                flow.add_edge(0, i + 1, 1, 0);

                flow.add_edge(n + i + 1, 2 * n + 1, 1, 0);
        }

        int res = flow.get_val(n) - 1;
        cout << res << "\n";

        for(auto p: flow.e){
                if(p.flow > 0 && p.cost > 0){
                        v[p.a].push_back(p.b - n);
                }
        }
        int put = 0;
        for(int x: v[0]){
                if(put){
                        cout << "R ";
                }
                put = 1;

                int cur = 0, y = x;
                while(true){
                        for(int i = 0; i < d; i++){
                                if((cur ^ a[y - 1]) & (1 << i)){
                                        cout << i << " ";
                                }
                        }
                        if(v[y].empty()){
                                break;
                        }
                        assert(v[y].size() == 1);
                        cur = a[y - 1];
                        y = v[y][0];
                }
        }
}