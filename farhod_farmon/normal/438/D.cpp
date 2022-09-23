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

pair < long long, long long > t[4 * N];
long long a[N];

void build(int x, int l, int r)
{
    if(l == r){
        t[x] = {a[l], a[l]};
        return;
    }
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    t[x].fi = t[x * 2].fi + t[x * 2 + 1].fi;
    t[x].se = max(t[x * 2].se, t[x * 2 + 1].se);
}

void md(int x, int l, int r, int tl, int tr, int m)
{
    if(tl > tr || t[x].se < m)
        return;
    if(l == r){
        t[x].fi %= m;
        t[x].se %= m;
        return;
    }
    int tm = (l + r) / 2;
    md(x * 2, l, tm, tl, min(tm, tr), m);
    md(x * 2 + 1, tm + 1, r, max(tm + 1, tl), tr, m);
    t[x].fi = t[x * 2].fi + t[x * 2 + 1].fi;
    t[x].se = max(t[x * 2].se, t[x * 2 + 1].se);
}

void upd(int x, int l, int r, int g, int c)
{
    if(l == r){
        t[x].fi = c;
        t[x].se = c;
        return;
    }
    int tm = (l + r) / 2;
    if(g <= tm)
        upd(x * 2, l, tm, g, c);
    else
        upd(x * 2 + 1, tm + 1, r, g, c);
    t[x].fi = t[x * 2].fi + t[x * 2 + 1].fi;
    t[x].se = max(t[x * 2].se, t[x * 2 + 1].se);
}

long long get(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)
        return 0;
    if(l == tl && r == tr){
        return t[x].fi;
    }
    int m = (l + r) / 2;
    return get(x * 2, l, m, tl, min(m, tr)) + get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

int n, m;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for(int i = 1; i <= m; i++){
        int t, l, r, x;
        cin >> t;
        if(t == 1){
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
        else if(t == 2){
            cin >> l >> r >> x;
            md(1, 1, n, l, r, x);
        }
        else{
            cin >> l >> x;
            upd(1, 1, n, l, x);
        }
    }
}