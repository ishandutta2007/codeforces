#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,revidx[100105],nxt[100105];
ll r,h,v[100105];
ll dp[100105],ans;
pair<ll,int> p[100105];
ll t[400105];

void update(int v, int tl, int tr, int idx, ll val) {
    if (tl == tr)
        t[v] = val;
    else {
        int tm = (tl + tr) >> 1;
        if (idx <= tm)
            update(v + v, tl, tm, idx, val);
        else
            update(v + v + 1, tm + 1, tr, idx, val);
        t[v] = max(t[v + v], t[v + v + 1]);
    }
}

ll get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) >> 1;
    return max(get(v + v, tl, tm, l, min(r, tm)), get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> r >> h;
        v[i] = r * r * h;
        p[i] = make_pair(v[i], i);
    }
    sort(p, p + n);
    for (int i = 0; i < n; ++i)
        revidx[p[i].second] = i;
    for (int i = 0; i < n; ) {
        int idx = i;
        while (idx < n && p[i].first == p[idx].first)
            ++idx;
        while (i < idx)
            nxt[p[i++].second] = idx;
    }

    for (int i = n-1; i >= 0; --i) {
        dp[i] = get(1, 0, n - 1, nxt[i], n - 1) + v[i];
        update(1, 0, n - 1, revidx[i], dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << setprecision(17) << fixed << ld(ans) * acosl(ld(-1));

    return 0;
}