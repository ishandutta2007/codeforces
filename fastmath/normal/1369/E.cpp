#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1e6 +7;
vector <int> g[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;

    vector <int> w(n+1), cost(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        cost[i] = w[i];
    }

    struct Friend {
        int u, v, i;
    };  
    vector <Friend> d;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        d.app({u, v, i+1});
        g[u].app(v);
        g[v].app(u);
        --cost[u]; --cost[v];
    }
    
    queue <int> q;
    for (int i = 1; i <= n; ++i) {
        if (cost[i] >= 0) {
            q.push(i);
        }   
    }   

    vector <int> ord;
    while (q.size()) {
        int u = q.front(); q.pop();
        ord.app(u);

        //cout << "u " << u << endl;

        for (int v : g[u]) {
            ++cost[v];
            if (cost[v] == 0) {
                q.push(v);
            }
        }   
    }   

    vector <int> pos(n+1, N);
    for (int i = 0; i < ord.size(); ++i)
        pos[ord[i]] = i;

    auto comp = [&](Friend a, Friend b) {
        return min(pos[a.u], pos[a.v]) > min(pos[b.u], pos[b.v]);
    };

    sort(all(d), comp);

    for (auto e : d) {
        if (!w[e.u] && !w[e.v]) {
            cout << "DEAD" << endl;
            exit(0);
        }
        if (w[e.u]) {  
            --w[e.u];
        }
        if (w[e.v]) {  
            --w[e.v];
        }
    }   
    cout << "ALIVE" << endl;
    for (auto e : d)
        cout << e.i << ' ';
    cout << endl;
}