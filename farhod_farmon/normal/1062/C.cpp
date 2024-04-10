#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int q;
int s[N];
int f[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                s[i] = s[i - 1] + c - '0';
        }
        f[1] = 1;
        int x = 1;
        for(int i = 2; i < N; i++){
                f[i] = f[i - 1] + x;
                x += x;
                if(f[i] >= mod){
                        f[i] -= mod;
                }
                if(x >= mod){
                        x -= mod;
                }
        }
        for(int i = 2; i < N; i++){
                f[i] += f[i - 1];
                if(f[i] >= mod){
                        f[i] -= mod;
                }
        }
        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                int x = s[r] - s[l - 1];
                l = r - l + 1;
                int ans = f[l] - f[l - x];
                if(ans < 0){
                        ans += mod;
                }
                cout << ans << "\n";
        }
}