#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000300;

using namespace std;

int n;
int m;
int b[N], t[N];
pair<int, int> a[N];

void upd(int x, int g)
{
        while(x < N){
                t[x] += g;
                x += x & -x;
        }
}

int get(int x)
{
        int res = 0;
        while(x > 0){
                res += t[x];
                x -= x & -x;
        }
        return res;
}

int f[4 * N];
int lz[4 * N];

void upd(int x, int l, int r, int tl, int tr, int g)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                f[x] += g;
                lz[x] += g;
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), g);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
        f[x] = min(f[x * 2], f[x * 2 + 1]) + lz[x];
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        for(int i = 1; i <= m; i++){
                cin >> b[i];
        }
        for(int i = 1; i <= n; i++){
                t[i] = 0;
        }
        for(int i = 1; i <= 4 * n; i++){
                f[i] = lz[i] = 0;
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        long long res = 0;
        for(int i = 1; i <= n; i++){
                if(i > 1 && a[i].fi != a[i - 1].fi){
                        int j = i - 1;
                        while(a[j].fi == a[i - 1].fi){
                                upd(a[j].se, 1);
                                j -= 1;
                        }
                }
                res += get(n) - get(a[i].se);
                upd(1, 1, n + 1, i + 1, n + 1, 1);
        }
        for(int i = 1, j = 1, h = 1; i <= m; i++){
                while(j <= n && a[j].fi <= b[i]){
                        upd(1, 1, n + 1, a[j].se + 1, n + 1, -1);
                        j += 1;
                }
                while(h <= n && a[h].fi < b[i]){
                        upd(1, 1, n + 1, 1, a[h].se, 1);
                        h += 1;
                }
                res += f[1];
        }
        cout << res << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}