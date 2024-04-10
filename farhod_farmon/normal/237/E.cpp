#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 220;
const int Q = 100100;

using namespace std;


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


int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        string s;
        vector < int > c(26, 0);
        cin >> s;
        for(char x: s){
                c[x - 'a'] += 1;
        }
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int cur = 26 + i;

                string t;
                int a;
                cin >> t >> a;
                flow.add_edge(0, cur, a, 0);
                vector < int > d(26, 0);
                for(char x: t){
                        d[x - 'a'] += 1;
                }
                for(int j = 0; j < 26; j++){
                        flow.add_edge(cur, j + 1, d[j], i);
                }
        }
        for(int i = 0; i < 26; i++){
                flow.add_edge(i + 1, 26 + n + 1, c[i], 0);
        }
        flow.init(26 + n + 2, 0, 26 + n + 1);
        cout << flow.get_val(s.size()) << "\n";
}