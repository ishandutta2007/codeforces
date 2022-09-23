#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

lli d[N], a[N], i, j, h, n, cnt, t[4 * N];

lli comb(lli x, lli y)
{
    return (a[x] > a[y] ? x : y);
}

void build(lli x, lli l, lli r)
{
    if(l == r){
        t[x] = l;
        return;
    }
    lli m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

lli get(lli x, lli l, lli r, lli tl, lli tr)
{
    if(tl > tr)
        return 0;
    if(l == tl && r == tr)
        return t[x];
    lli m = (l + r) / 2;
    return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(i = 1; i < n; i++)
        cin >> a[i];
    a[n] = n;
    build(1, 1, n);
    for(i = n - 1; i >= 1; i--){
        h = get(1, 1, n, i + 1, a[i]);
        d[i] = d[h] - (a[i] - h) + n - i;
        cnt += d[i];
    }
    cout << cnt << endl;
}