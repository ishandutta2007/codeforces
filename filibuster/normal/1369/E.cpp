#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int a[N];
//pair<pii, pii> a[N];

vector<pii> g[N];
bool used[N];
bool is[N];
bool in_q[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int j = 0; j < m; j++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].emplace_back(u, j);
        g[u].emplace_back(v, j);

//        a[j].s.f >> a[j].s.s;
//
//        a[j].s.f--;
//        a[j].s.s--;
//
//        a[j].f.s = j;
//        a[j].f.f = b[a[j].s.f] + b[a[j].s.s];//max(b[a[j].s.f], b[a[j].s.s]);
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(a[i] >= g[i].size()) {
            q.push(i);
            in_q[i] = true;
        }
    }

    vector<int> ans;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        used[v] = true;

        for(auto p : g[v]) {
            int u = p.f, i = p.s;

            if(used[u])
                continue;

            ans.push_back(i);
            a[u]++;

            if(a[u] >= g[u].size() && !in_q[u]) {
                q.push(u);
                in_q[u] = true;
            }
        }
    }

    if(ans.size() < m) {
        cout << "DEAD" << endl;
        return 0;
    }

    cout << "ALIVE" << endl;
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] + 1 << ' ';
}