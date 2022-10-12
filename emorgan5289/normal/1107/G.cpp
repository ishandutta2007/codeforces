#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
struct rmq {

    vector<vector<T>> tree;

    // runs in O(nlogn).
    rmq(vector<T> data) {
        int n = data.size();
        int log2n = n == 0 ? 0 : ceil(log2(n));
        tree.assign(log2n+1, vector<T>(n));
        tree[0] = data;
        for (int i = 1; i <= log2n; i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                tree[i][j] = max(tree[i-1][j], tree[i-1][j+(1<<i-1)]);
    }

    // returns the maximum of the array on the interval [a..b] in O(1) time.
    T query(int a, int b) {
        int n = floor(log2(b-a+1));
        return max(tree[n][a], tree[n][b-(1<<n)+1]);
    }
};

const ll N = 3e5+5;
ll c[N], d[N], p[N];
set<array<ll, 2>> ord;
set<int> ind;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a; cin >> n >> a;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> c[i]; c[i] -= a;
        if (i > 0) ord.insert({-(d[i]-d[i-1])*(d[i]-d[i-1]), i});
        p[i+1] = c[i]+p[i];
        ans = max(ans, -c[i]);
    }
    rmq left(vector(p, p+n+1));
    for (int i = 0; i <= n; i++) p[i] = -p[i];
    rmq right(vector(p, p+n+1));
    ind.insert(0), ind.insert(n);
    for (auto& [gap, i] : ord) {
        auto it = ind.insert(i).first;
        auto it1 = it, it2 = it;
        int x = *(--it1), y = *(++it2);
        ans = max(ans, gap+left.query(x, i-1)+right.query(i+1, y));
    }
    cout << ans << "\n";
}