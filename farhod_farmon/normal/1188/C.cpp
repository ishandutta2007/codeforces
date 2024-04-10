#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int k;
int a[N];
int l[N];
int r[N];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int pos(int m)
{
        l[0] = r[n + 1] = 1;
        for(int i = 1, j = 1; i <= n; i++){
                l[i] = l[i - 1];
                while(j + 1 < i && a[i] - a[j + 1] >= m) j += 1;
                if(j < i && a[i] - a[j] >= m) l[i] = max(l[i], l[j] + 1);
        }
        for(int i = n, j = n; i >= 1; i--){
                r[i] = r[i + 1];
                while(j - 1 > i && a[j - 1] - a[i] >= m) j -= 1;
                if(j > i && a[j] - a[i] >= m) r[i] = max(r[i], r[j] + 1);
        }
        int res = 0;
        for(int i = 1, j = 1; i <= n; i++){
                while(j + 1 < i && a[i] - a[j + 1] >= m) j += 1;
                if(j < i && a[i] - a[j] == m) res = max(res, l[j] + r[i]);
        }
        return res;
}

int all[1010];
int d[1010][1010];

int solve(int m)
{
        for(int i = 1; i <= k; i++){
                all[i] = 0;
        }
        int h = 1;
        for(int i = 1; i <= n; i++){
                while(h < i && a[i] - a[h] >= m){
                        for(int j = 1; j <= k; j++){
                                add(all[j], d[h][j]);
                        }
                        h += 1;
                }
                d[i][1] = 1;
                for(int j = 2; j <= k; j++){
                        d[i][j] = all[j - 1];
                }
        }
        while(h <= n){
                for(int j = 1; j <= k; j++){
                        add(all[j], d[h][j]);
                }
                h += 1;
        }
        return all[k];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int res = 0, ot = 0;
        for(int i = 100000; i >= 0; i--){
                if(pos(i) < k){
                        continue;
                }
                int cur = solve(i);
                cur -= ot;
                if(cur < 0){
                        cur += mod;
                }
                add(res, 1ll * cur * i % mod);
                add(ot, cur);
        }
        cout << res << "\n";
}