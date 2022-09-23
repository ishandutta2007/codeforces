#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300300;

using namespace std;

struct edge
{
    int ul, ur, dl, dr, a, al, ar;
    long long xl, xr;
};

edge comb(edge a, edge b, int sa, int sb)
{
    edge g;
    g.a = max(a.a, b.a);
    g.al = a.al;
    g.xl = a.xl;
    g.ul = a.ul;
    g.dl = a.dl;
    g.ar = b.ar;
    g.xr = b.xr;
    g.ur = b.ur;
    g.dr = b.dr;
    if(a.xr == b.xl){
        return g;
    }
    else if(a.xr > b.xl){
        g.a = max(g.a, a.ar + b.dl);
        if(sb == b.dl)
            g.ar = a.ar + b.dl;
        if(sa == a.a)
            g.al = a.a + b.dl;
        if(sa == a.dl)
            g.dl += b.dl;
        if(sb == b.ur)
            g.ur += a.ur;
        //g.a = max(g.a, max(g.al, g.ar));
        return g;
    }
    else{
        g.a = max(g.a, a.dr + b.al);
        if(sb == b.a)
            g.ar = a.dr + b.a;
        if(sa == a.dr)
            g.al = a.dr + b.al;
        if(sb == b.dr)
            g.dr += a.dr;
        if(sa == a.ul)
            g.ul += b.ul;
        //g.a = max(g.a, max(g.al, g.ar));
        return g;
    }
}

edge t[4 * N];
int n;
int a[N];
long long lz[4 * N];

void push(int x)
{
    if(lz[x] == 0)
        return;
    t[x * 2].xl += lz[x];
    t[x * 2].xr += lz[x];
    t[x * 2 + 1].xl += lz[x];
    t[x * 2 + 1].xr += lz[x];
    lz[x * 2] += lz[x];
    lz[x * 2 + 1] += lz[x];
    lz[x] = 0;
}

void build(int x, int l, int r)
{
    if(l == r){
        t[x].xl = t[x].xr = a[l];
        t[x].a = t[x].al = t[x].ar = t[x].dl = t[x].dr = t[x].ul = t[x].ur = 1;
        return;
    }
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    t[x] = comb(t[x * 2], t[x * 2 + 1], m - l + 1, r - m);
}

void upd(int x, int l, int r, int tl, int tr, long long d)
{
    if(tl > tr)
        return;
    if(l == tl && r == tr){
        lz[x] += d;
        t[x].xl += d;
        t[x].xr += d;
        return;
    }
    push(x);
    int m = (l + r) / 2;
    upd(x * 2, l, m, tl, min(m, tr), d);
    upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, d);
    t[x] = comb(t[x * 2], t[x * 2 + 1], m - l + 1, r - m);
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
        int l, r, d;
        sc("%d%d%d", &l, &r, &d);
        upd(1, 1, n, l, r, d);
        pr("%d\n", t[1].a);
    }
}