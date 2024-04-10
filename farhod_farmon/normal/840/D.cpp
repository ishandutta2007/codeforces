
#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int q;
int a[N];
vector < int > v[4 * N], g[N];

int f(int l, int r, int x)
{
        return lower_bound(g[x].begin(), g[x].end(), r + 1) - lower_bound(g[x].begin(), g[x].end(), l);
}

void build(int x, int l, int r)
{
        if(l == r){
                v[x].push_back(a[l]);
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        set < int > s;
        for(int y: v[x * 2]){
                if(f(l, r, y) * 5 > (r - l + 1)){
                        s.insert(y);
                }
        }
        for(int y: v[x * 2 + 1]){
                if(f(l, r, y) * 5 > (r - l + 1)){
                        s.insert(y);
                }
        }
        for(int y: s){
                v[x].push_back(y);
        }
}

int get(int x, int l, int r, int tl, int tr, int a, int b, int k)
{
        if(tl > tr){
                return 1e9;
        }
        if(l == tl && r == tr){
                for(int y: v[x]){
                        if(f(a, b, y) * k > (b - a + 1)){
                                return y;
                        }
                }
                return 1e9;
        }
        int m = (l + r) / 2;
        return min(get(x * 2, l, m, tl, min(m, tr), a, b, k), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, a, b, k));
}

void solve()
{
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                g[i].push_back(0);
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                g[a[i]].push_back(i);
        }
        for(int i = 1; i <= n; i++){
                g[i].push_back(n + 1);
        }
        build(1, 1, n);
        for(int i = 1; i <= q; i++){
                int l, r, k;
                cin >> l >> r >> k;
                int g = get(1, 1, n, l, r, l, r, k);
                if(g == 1e9){
                        g = -1;
                }
                cout << g << "\n";
        }
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}