#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 100005, maxs = 320;
int n, m, s, f[maxs][maxn];
deque<int> d[maxs];

int qry(int l, int r, int k) {
    int x = 0;
    if (l/s == r/s) {
        for (int i = l%s; i <= r%s; i++)
            if (d[l/s][i] == k) x++;
        return x;
    }
    for (; l%s != 0; l++)
        if (d[l/s][l%s] == k) x++;
    for (; (r+1)%s != 0; r--)
        if (d[r/s][r%s] == k) x++;
    for (int i = l/s; i <= r/s; i++)
        x += f[i][k];
    return x;
}

void upd(int l, int r) {
    int k = d[r/s][r%s];
    f[l/s][k]++; f[r/s][k]--;
    d[r/s].erase(d[r/s].begin()+(r%s));
    d[l/s].insert(d[l/s].begin()+(l%s), k);
    for (int i = l/s; i < r/s; i++) {
        k = d[i].back();
        f[i][k]--; f[i+1][k]++;
        d[i+1].push_front(k); d[i].pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; s = sqrt(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        f[i/s][a]++;
        d[i/s].pb(a);
    }
    int a = 0, q; cin >> q;
    while (q--) {
        int t, l, r, k; cin >> t >> l >> r;
        if (t == 2) cin >> k;
        l = (l+a-1)%n; r = (r+a-1)%n; k = ((k+a-1)%n)+1;
        if (l > r) swap(l, r);
        if (t == 2) {
            a = qry(l, r, k); cout << a << "\n";
        } else {
            upd(l, r);
        }
    }
}