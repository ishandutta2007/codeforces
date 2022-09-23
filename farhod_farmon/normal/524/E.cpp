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

int n, m, k, q;
int t[4 * N];
int x1[N + N];
int x2[N + N];
int y1[N + N];
int y2[N + N];
bool ans[N + N];
vector < int > c_l[N], r_l[N], c_q[N], r_q[N];

void clr()
{
    for(int i = 0; i < 4 * N; i++)
        t[i] = 0;
}

void upd(int x, int l, int r, int g, int y)
{
    if(l == r){
        t[x] = y;
        return;
    }
    int m = (l + r) / 2;
    if(g <= m)
        upd(x * 2, l, m, g, y);
    else
        upd(x * 2 + 1, m + 1, r, g, y);
    t[x] = min(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)
        return 1e9;
    if(l == tl && r == tr)
        return t[x];
    int m = (l + r) / 2;
    return min(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 1; i <= k; i++){
        int x, y;
        sc("%d%d", &x, &y);
        r_l[x].pb(y);
        c_l[y].pb(x);
    }
    for(int i = 1; i <= q; i++){
        sc("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        r_q[x2[i]].pb(i);
        c_q[y2[i]].pb(i);
    }
    for(int i = 1; i <= n; i++){
        for(auto x: r_l[i])
            upd(1, 1, m, x, i);
        for(auto h: r_q[i]){
            int f = x1[h],
                l = y1[h],
                r = y2[h];
            if(get(1, 1, m, l, r) >= f)
                ans[h] = true;
        }
    }
    clr();
    for(int i = 1; i <= m; i++){
        for(auto x: c_l[i])
            upd(1, 1, n, x, i);
        for(auto h: c_q[i]){
            int f = y1[h],
                l = x1[h],
                r = x2[h];
            if(get(1, 1, n, l, r) >= f)
                ans[h] = true;
        }
    }
    for(int i = 1; i <= q; i++){
        if(ans[i])
            pr("YES\n");
        else
            pr("NO\n");
    }
}