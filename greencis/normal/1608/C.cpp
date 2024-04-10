#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

vector<int> g[100100];
vector<int> gr[100100];
int u[100100];
int whichComp[100100];
vector<int> order, comp;

void dfs1(int v) {
    u[v] = 1;
    for (int to : g[v])
        if (!u[to])
            dfs1(to);
    order.push_back(v);
}

void dfs2(int v) {
    u[v] = 1;
    comp.push_back(v);
    for (int to : gr[v])
        if (!u[to])
            dfs2(to);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<pii> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = {x, i};
        }
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            b[i] = {x, i};
        }
        sort(all(a));
        sort(all(b));
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            gr[i].clear();
        }
        auto addArc = [&](int from, int to) {
            g[from].push_back(to);
            gr[to].push_back(from);
        };
        for (int i = 0; i + 1 < n; ++i) {
            addArc(a[i + 1].second, a[i].second);
            addArc(b[i + 1].second, b[i].second);
        }
        fill_n(u, n, 0);
        for (int i = 0; i < n; ++i) {
            if (!u[i]) {
                dfs1(i);
            }
        }
        fill_n(u, n, 0);
        reverse(all(order));
        int clr = 0;
        for (int i : order) {
            if (!u[i]) {
                ++clr;
                comp.clear();
                dfs2(i);
                for (int v : comp)
                    whichComp[v] = clr;
            }
        }
        string ans(n, '0');
        int clra = whichComp[a[n - 1].second];
        int clrb = whichComp[b[n - 1].second];
        for (int i = 0; i < n; ++i)
            if (whichComp[i] == clra || whichComp[i] == clrb)
                ans[i] = '1';
        cout << ans << '\n';
    }
}