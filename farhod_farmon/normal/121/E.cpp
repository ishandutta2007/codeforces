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

int n, m;
int a[N];
int b[N];
int id[N];
int lazy[4 * N];
vector < int > g;
pair < int, int > t[4 * N];

void lucky(int x)
{
    if(x > (int)1e5)
        return;
    g.pb(x);
    lucky(x * 10 + 4);
    lucky(x * 10 + 7);
}

void push(int x)
{
    if(lazy[x] == 0)
        return;
    t[x * 2].fi -= lazy[x];
    t[x * 2 + 1].fi -= lazy[x];
    lazy[x * 2] += lazy[x];
    lazy[x * 2 + 1] += lazy[x];
    lazy[x] = 0;
}

pair < int, int > comb(pair < int, int > x, pair < int, int > y)
{
    if(x.fi < y.fi)
        return x;
    else if(x.fi > y.fi)
        return y;
    return {x.fi, x.se + y.se};
}

void build(int x, int l, int r)
{
    if(l == r){
        t[x] = {b[l], 1};
        return;
    }
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

pair < int, int > get_a(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)
        return {1e4 + 1, 0};
    if(l == tl && r == tr)
        return t[x];
    push(x);
    int m = (l + r) / 2;
    return comb(get_a(x * 2, l, m, tl, min(m, tr)), get_a(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void upd(int x, int l, int r, int tl, int tr, int y)
{
    if(tl > tr)
        return;
    if(l == tl && r == tr){
        t[x].fi -= y;
        lazy[x] += y;
        return;
    }
    push(x);
    int m = (l + r) / 2;
    upd(x * 2, l, m, tl, min(m, tr), y);
    upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
    t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

void fix(int x, int l, int r)
{
    if(l == r){
        int y = g[id[l]] - t[x].fi;
        while(g[id[l]] - y < 0)
            id[l]++;
        t[x].fi = g[id[l]] - y;
        return;
    }
    push(x);
    int m = (l + r) / 2;
    if(t[x * 2].fi < 0)
        fix(x * 2, l, m);
    if(t[x * 2 + 1].fi < 0)
        fix(x * 2 + 1, m + 1, r);
    t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    lucky(0);
    sort(g.begin(), g.end());
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < g.size(); j++){
            if(g[j] >= a[i]){
                id[i] = j;
                b[i] = g[j] - a[i];
                break;
            }
        }
    }
    build(1, 1, n);
    for(int i = 1; i <= m; i++){
        string s;
        int l, r, d;
        cin >> s >> l >> r;
        if(s == "count"){
            pair < int, int > p = get_a(1, 1, n, l, r);
            if(p.fi == 0)
                cout << p.se << endl;
            else
                cout << 0 << endl;
        }
        else{
            cin >> d;
            upd(1, 1, n, l, r, d);
            fix(1, 1, n);
        }
    }
}