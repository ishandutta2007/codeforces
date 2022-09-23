#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300200;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

long long n, start, len;
long long f[N];
long long q[N];
long long a[N];
long long b[N];
long long d[N];
bool used[N];
pair < long long, long long > t[4 * N];

pair < long long, long long > comb(pair < long long, long long > x, pair < long long, long long > y)
{
        pair < long long, long long > p;
        p.se = x.se + y.se;
        if(x.fi + x.se >= y.fi){
                p.fi = x.fi;
        }
        else{
                p.fi = y.fi - x.se;
        }
        return p;
}

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = {-(b[r] - b[l - 1]), b[r] - b[l - 1]};
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

pair < long long, long long > get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return {-1e18, 0};
        }
        if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

long long get1(int i, int j)
{
        if(f[i] + len <= f[j]){
                return -1;
        }
        if(f[i - 1] + len + 1 > f[j + 1]){
                return -2;
        }
        return max(f[i - 1] + 1, f[j] - len + 1);
}

void solve()
{
        long long a, b, c, d;
        cin >> n >> a >> b >> c >> d >> start >> len;
        for(int i = 1; i <= n; i++){
                cin >> f[i] >> q[i];
                ::a[i] = ::a[i - 1] + (a + b) * q[i] - b;
                ::b[i] = ::b[i - 1] + (c + d) * q[i] - d;
        }
        for(int i = 1; i <= n; i++){
                used[i] |= used[i - 1];
                if(start + ::a[i] < 0){
                        used[i] = 1;
                }
        }
        for(int i = n; i >= 1; i--){
                ::d[i] = max(0ll, ::d[i + 1]) - ((a + b) * q[i] - b);
                ::d[i] = max(0ll, ::d[i]);
        }
        f[0] = -1;
        f[n + 1] = 1e11;
        long long ans = 1e18;
        if(used[n] == false){
                ans = f[n] + 1;
        }
        build(1, 1, n);
        for(int i = 1, j = 1; j <= n; j++){
                long long g = get1(i, j);
                if(g == -2){
                        continue;
                }
                while(g == -1){
                        i++;
                        g = get1(i, j);
                }
                while(i <= j && g != -2){
                        if(!used[i - 1]){
                                long long cur = start + ::a[i - 1];
                                pair < long long, long long > p = get(1, 1, n, i, j);
                                if(cur >= max(0ll, p.fi)){
                                        ans = min(ans, g);
                                }
                        }
                        i++;
                        g = get1(i, j);
                }
                i = max(1, i - 1);
        }
        if(ans == 1e18){
                ans = -1;
        }
        cout << ans << "\n";
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