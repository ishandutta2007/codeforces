#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;
vector <int> g[N];

int sml[N], bgr[N];

ll res = 0;
int val[N];
vector <int> who[N];

int n;

void calc() {
    for (int i = 0; i < n; ++i) {
        int cnt1 = 0, cnt2 = 0;
        for (int j : g[i]) {
            if (val[j] < val[i]) ++cnt1;
            else ++cnt2;
        }
        res += (ll)cnt1 * cnt2;
    }
    for (int i = 0; i < n; ++i) {
        for (int j : g[i]) {
            if (val[j] < val[i]) who[j].push_back(i);
        }
    }
}

void del(int id) {
    res -= (ll)who[id].size() * ((ll)g[id].size() - who[id].size());
}

void add(int id) {
    res += (ll)who[id].size() * ((ll)g[id].size() - who[id].size());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) val[i] = i;
    calc();
    cout << res << '\n';
    int q;
    cin >> q;
    for (int t = 0; t < q; ++t) {
        int v;
        cin >> v;
        --v;
        del(v);
        for (int u : who[v]) {
            del(u);
            who[u].push_back(v);
            add(u);
        }
        who[v].clear();
        cout << res << '\n';
    }
}