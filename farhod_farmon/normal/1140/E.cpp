#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
int k;
int a[N];
int f[N];
int d[N];
int pp[N];
int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        int pw = 1;
        f[0] = 1;
        pp[0] = 1;
        for(int i = 1; i < N; i++){
                pw = 1ll * pw * (k - 1) % mod;
                pp[i] = pw;
                f[i] = pw - f[i - 1];
                d[i] = pw - d[i - 1];
                if(f[i] < 0){
                        f[i] += mod;
                }
                if(d[i] < 0){
                        d[i] += mod;
                }
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int res = 1;
        for(int it = 0; it < 2; it++){
                int cnt = 0, last = -1, gg = 1;
                for(int j = 1 + it; j <= n; j += 2){
                        if(a[j] == -1){
                                cnt++;
                        } else{
                                if(last == a[j] && cnt == 0){
                                        gg = 0;
                                }
                                if(cnt > 0){
                                        if(last == -1){
                                                gg = 1ll * gg * pp[cnt] % mod;
                                        } else if(last == a[j]){
                                                gg = 1ll * gg * d[cnt] % mod;
                                        } else{
                                                gg = 1ll * gg * f[cnt] % mod;
                                        }
                                }
                                cnt = 0;
                                last = a[j];
                        }
                }
                if(cnt > 0){
                        if(last == -1){
                                gg = 1ll * gg * k % mod;
                                cnt--;
                        }
                        gg = 1ll * gg * pp[cnt] % mod;
                }
                res = 1ll * res * gg % mod;
        }
        cout << res << "\n";
}