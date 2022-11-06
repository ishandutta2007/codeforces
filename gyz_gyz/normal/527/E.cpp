//why are you stalking me?
#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)
#define dbg(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, bool> node;
const int MAXN = 100010;

int N, M;
multiset<int> adj[MAXN];
vector<int> odds, tour;
vector<pii> add;

void dfs (int x) {
    //add to circuit
    while (!adj[x].empty()) {
        int t = *adj[x].begin();
        adj[x].erase(adj[x].begin());
        adj[t].erase(adj[t].find(x));
        dfs(t);
    }
    tour.push_back(x);
}

void addedge (int x, int y) {
    adj[x].insert(y);
    adj[y].insert(x);
    add.push_back(pii(x, y));
}

int main() {
    //why are you stalking me?
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i = 1; i <= N; i++) {
        if (adj[i].size() & 1) {
            odds.push_back(i);
        }
    }
    for (int i = 0, sz = odds.size(); i < sz; i += 2) {
        addedge(odds[i], odds[i + 1]);
    }
    if ((M + add.size()) & 1) {
        addedge(1, 1);
    }
    dfs(1);
    reverse(all(tour));
    cout << M + add.size() << '\n';
    for (int i = 0, sz = int(tour.size()) - 1; i < sz; i++) {
        int u = tour[i], v = tour[i + 1];
        if (i & 1) {
            swap(u, v);
        }
        cout << u << ' ' << v << '\n';
    }
}