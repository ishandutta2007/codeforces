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

const int N = 1000010;

using namespace std;

struct edge
{
    int a;
    int up;
    int down;
};

int n;
char c[N];
bool lazy[4 * N];
edge t[4 * N];

edge comb(edge x, edge y, int l, int r)
{
    int m = (l + r) / 2;
    int xb = (m - l + 1) - x.a,
        yb = (r - m) - y.a;
    x.up = max(x.up + yb, x.a + y.up);
    x.down = max(x.down + y.a, xb + y.down);
    x.a += y.a;
    return x;
}

void build(int x, int l, int r)
{
    if(l == r){
        if(c[l] == '4')
            t[x].a = 1;
        else
            t[x].a = 0;
        t[x].up = t[x].down = 1;
        return;
    }
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    t[x] = comb(t[x * 2], t[x * 2 + 1], l, r);
}

void ch(int x, int sza)
{
    lazy[x] = 1 - lazy[x];
    swap(t[x].up, t[x].down);
    t[x].a = sza - t[x].a;
}


void upd(int x, int l, int r, int tl, int tr)
{
    if(lazy[x] && l != r){
        ch(x * 2, (l + r) / 2 - l + 1);
        ch(x * 2 + 1, r - (l + r) / 2);
        lazy[x] = false;
    }
    if(tl > tr)
        return;
    if(l == tl && r == tr){
        ch(x, r - l + 1);
        return;
    }
    int m = (l + r) / 2;
    upd(x * 2, l, m, tl, min(m, tr));
    upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
    t[x] = comb(t[x * 2], t[x * 2 + 1], l, r);
}

int m;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    build(1, 1, n);
    for(int i = 1; i <= m; i++){
        string s;
        int l, r;
        cin >> s;
        if(s == "count")
            cout << t[1].up << endl;
        else{
            cin >> l >> r;
            upd(1, 1, n, l, r);
        }
    }
}