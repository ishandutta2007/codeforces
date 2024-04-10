#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int q;
long long a[N];
long long s[N];
long long t[4 * N];
long long lz[4 * N];

void push(int x)
{
        if(lz[x]){
                t[x * 2] += lz[x];
                lz[x * 2] += lz[x];
                t[x * 2 + 1] += lz[x];
                lz[x * 2 + 1] += lz[x];
                lz[x] = 0;
        }
}

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = s[l] - 2 * s[l - 1];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

void upd(int x, int l, int r, int tl, int tr, long long y)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                t[x] += y;
                lz[x] += y;
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r)
{
        if(t[x] < 0){
                return -1;
        }
        if(l == r){
                if(t[x] == 0){
                        return l;
                }
                return -1;
        }
        push(x);
        int m = (l + r) / 2;
        int g = get(x * 2, l, m);
        if(g != -1){
                return g;
        }
        return get(x * 2 + 1, m + 1, r);
}

void solve()
{
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s[i] = s[i - 1] + a[i];
        }
        build(1, 1, n);
        for(int i = 1; i <= q; i++){
                long long x, y;
                cin >> x >> y;
                upd(1, 1, n, x, x, y - a[x]);
                upd(1, 1, n, x + 1, n, a[x] - y);
                a[x] = y;
                cout << get(1, 1, n) << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}