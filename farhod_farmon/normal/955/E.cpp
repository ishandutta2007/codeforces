#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
int t[4 * N];
int rl[4 * N];
int lz[4 * N];

void push(int x)
{
        if(lz[x]){
                t[x * 2] += lz[x];
                lz[x * 2] += lz[x];
                rl[x * 2] += lz[x];
                t[x * 2 + 1] += lz[x];
                lz[x * 2 + 1] += lz[x];
                rl[x * 2 + 1] += lz[x];
                lz[x] = 0;
        }
}

void up(int x)
{
        t[x] = min(t[x * 2], t[x * 2 + 1]);
        rl[x] = min(rl[x * 2], rl[x * 2 + 1]);
}

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = a[l] - l;
                rl[x] = a[l];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        up(x);
}

void upd(int x, int l, int r, int tl, int tr, int g)
{
        if(tl > tr){
                return;
        }
        if(tl == l && r == tr){
                t[x] += g;
                lz[x] += g;
                rl[x] += g;
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), g);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
        up(x);
}

int get(int x, int l, int r)
{
        if(t[x] >= 0){
                return n + 1;
        }
        if(l == r){
                return l;
        }
        push(x);
        int m = (l + r) / 2;
        if(t[x * 2] < 0){
                return get(x * 2, l, m);
        }
        else{
                return get(x * 2 + 1, m + 1, r);
        }
}

int get_real(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 1e9;
        }
        if(l == tl && r == tr){
                return rl[x];
        }
        push(x);
        int m = (l + r) / 2;
        return min(get_real(x * 2, l, m, tl, min(m, tr)), get_real(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] += i - 1;
        }
        build(1, 1, n);
        int ans = 1e9;
        for(int i = 1; i <= n; i++){
                int g = get(1, 1, n);
                if(g <= n){
                        ans = min(ans, max(get_real(1, 1, n, g, n), get_real(1, 1, n, 1, g - 1)));
                }
                upd(1, 1, n, 1, i, 1);
                upd(1, 1, n, i + 1, n, -1);
        }
        if(ans == 1e9){
                ans = -1;
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}