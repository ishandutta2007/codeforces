#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,k,x;
ll t[15][400005];

ll get(int idx, int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t[idx][v];
    int tm = (tl + tr) / 2;
    return get(idx, v + v, tl, tm, l, min(r, tm))
        + get(idx, v + v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int idx, int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) t[idx][v] = val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(idx, v + v, tl, tm, pos, val);
        else update(idx, v + v + 1, tm + 1, tr, pos, val);
        t[idx][v] = t[idx][v + v] + t[idx][v + v + 1];
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        --x;
        update(1, 1, 0, n-1, x, 1);
        for (int j = 2; j <= k + 1; ++j)
            update(j, 1, 0, n-1, x, get(j - 1, 1, 0, n-1, 0, x - 1));
    }
    for (int i = 0; i < n; ++i)
        ans += get(k + 1, 1, 0, n-1, i, i);
    cout << ans;

    return 0;
}