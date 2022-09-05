#include <bits/stdc++.h>
using namespace std;

const int maxn = 610;
int n, e[maxn], dep[maxn], fa[maxn], perm[maxn];
vector<int> G[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    auto ask = [&](vector<int> V) {
        if (V.size() <= 1) return 0;
        cout << "? " << V.size();
        for (int x : V) cout << " " << x;
        cout << endl;
        int x; cin >> x;
        return x;
    };
    vector<int> V = {1};
    while (V.size() < n) {
        e[V.size() - 1] = ask(V);
        vector<int> cand;
        for (int i = 1; i <= n; i++) {
            bool flag = 0;
            for (int x : V) flag |= x == i;
            if (!flag) cand.push_back(i);
        }
        int l = 0, r = cand.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int e1 = ask(vector<int>(cand.begin(), cand.begin() + mid + 1));
            vector<int> _V = V;
            for (int i = 0; i <= mid; i++) _V.push_back(cand[i]);
            int e2 = ask(_V);
            if (e2 == e[V.size() - 1] + e1) l = mid + 1;
            else r = mid;
        }
        int p = r;
        l = 0, r = V.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            vector<int> _V(V.begin(), V.begin() + mid + 1);
            _V.push_back(cand[p]);
            if (e[mid] == ask(_V)) l = mid + 1;
            else r = mid;
        }
        assert(ask({V[r], cand[p]}) == 1);
        G[V[r]].push_back(cand[p]), G[cand[p]].push_back(V[r]);
        V.push_back(cand[p]);
    }
    vector<int> L, R;
    function<void(int)> dfs = [&](int v) {
        dep[v] & 1 ? L.push_back(v) : R.push_back(v);
        for (int u : G[v]) if (u ^ fa[v]) {
            fa[u] = v, dep[u] = dep[v] + 1, dfs(u);
        }
    };
    dfs(1);
    int el = ask(L), er = ask(R);
    if (!el && !er) {
        cout << "Y " << L.size() << endl;
        for (int x : L) cout << x << " ";
        cout << endl;
    } else {
        if (!el) swap(L, R);
        for (int i = 1; i < L.size(); i++) {
            int l = 0, r = i - 1, ans = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                vector<int> _V(L.begin(), L.begin() + mid + 1);
                _V.push_back(L[i]);
                if (ask(_V)) r = (ans = mid) - 1;
                else l = mid + 1;
            }
            if (~ans) {
                vector<int> pl, pr;
                int u = L[i], v = L[ans];
                while (u ^ v) {
                    if (dep[u] > dep[v]) {
                        pl.push_back(u), u = fa[u];
                    } else {
                        pr.push_back(v), v = fa[v];
                    }
                }
                reverse(pr.begin(), pr.end());
                cout << "N " << pl.size() + pr.size() + 1 << endl;
                for (int x : pl) cout << x << " ";
                cout << u << " ";
                for (int x : pr) cout << x << " ";
                cout << endl;
                break;
            }
        }
    }
    return 0;
}