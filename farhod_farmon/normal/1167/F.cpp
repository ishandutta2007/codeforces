#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

struct seg
{
        long long t[4 * N];
        int lz[4 * N];

        void push(int x, int l, int r)
        {
                if(!lz[x]){
                        return;
                }
                int m = (l + r) / 2;
                t[x * 2] += 1ll * (m - l + 1) * lz[x];
                t[x * 2 + 1] += 1ll * (r - m) * lz[x];
                lz[x * 2] += lz[x];
                lz[x * 2 + 1] += lz[x];
                lz[x] = 0;
        }
        void upd(int x, int l, int r, int tl, int tr)
        {
                if(tl > tr){
                        return;
                }
                if(l == tl && r == tr){
                        t[x] += r - l + 1;
                        lz[x] += 1;
                        return;
                }
                push(x, l, r);
                int m = (l + r) / 2;
                upd(x * 2, l, m, tl, min(m, tr));
                upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
                t[x] = t[x * 2] + t[x * 2 + 1];
        }
        long long get(int x, int l, int r, int tl, int tr)
        {
                if(tl > tr){
                        return 0;
                }
                if(l == tl && r == tr){
                        return t[x];
                }
                push(x, l, r);
                int m = (l + r) / 2;
                return get(x * 2, l, m, tl, min(m, tr)) + get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
        }
};

int n;
seg f1, f2;
pair < int, int > a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        sort(a + 1, a + n + 1);
        long long res = 0;
        for(int ii = 1; ii <= n; ii++){
                int i = a[ii].se;
                long long c1 = f1.get(1, 1, n, 1, i) - f1.get(1, 1, n, i, i) * i;
                long long c2 = f2.get(1, 1, n, i, n) - f2.get(1, 1, n, i, i) * (n - i + 1);

                c1 %= mod;
                c2 %= mod;

                c1 = c1 * (n - i + 1) % mod;
                c2 = c2 * i % mod;

                c1 += c2;
                c1 += 1ll * i * (n - i + 1) % mod;

                c1 %= mod;
                res = (res + c1 * a[ii].fi) % mod;

                f1.upd(1, 1, n, 1, i);
                f2.upd(1, 1, n, i, n);
        }
        cout << res << "\n";
}