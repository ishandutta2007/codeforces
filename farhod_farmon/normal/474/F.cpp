#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n;
int a[N];
int g[N];
pair < pair < int, int >, int > t[4 * N];

pair < pair < int, int >, int > comb(pair < pair < int, int >, int > x, pair < pair < int, int >, int > y)
{
    if(x.se == 0)
        return y;
    if(y.se == 0)
        return x;
    if(x.fi.fi == y.fi.fi)
        x.fi.se += y.fi.se;
    else
        x.fi = min(x.fi, y.fi);
    x.se = __gcd(x.se, y.se);
    return x;
}

void build(int x, int l, int r)
{
    if(l == r){
        t[x] = {{a[l], 1}, a[l]};
        return;
    }
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

pair < pair < int, int >, int > get(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)
        return {{0, 0}, 0};
    if(l == tl && r == tr)
        return t[x];
    int m = (l + r) / 2;
    return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d", &n);
    for(int i = 1; i <= n; i++)
        sc("%d", &a[i]);
    build(1, 1, n);
    int m;
    sc("%d", &m);
    for(int i = 1; i <= m; i++){
        int l, r;
        sc("%d%d", &l, &r);
        pair < pair < int, int >, int > p = get(1, 1, n, l, r);
        if(p.fi.fi == p.se)
            pr("%d\n", r - l + 1 - p.fi.se);
        else
            pr("%d\n", r - l + 1);
    }
}