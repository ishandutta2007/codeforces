#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
#define debug(x) cerr << #x << ": <" << x << ">\n"
#define sz(x) (int)x.size()
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

vvi graph;
vi color;

bool bi(int idx, int c = 1) {
    color[idx] = c;
    for (auto& i : graph[idx]) {
        if (!color[i]) {
            if (!bi(i, c ^ 3))
                return false;
        }
        else if (color[i] == c)
            return false;
    }
    return true;
}

int main() {
    ioThings();

    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    color.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int rm = 0;
    for (int i = 1; i <= n; i++)
        if (!color[i] && !bi(i))
            rm++;

    cout << ((n - rm) % 2 ? rm + 1 : rm);

    return 0;
}