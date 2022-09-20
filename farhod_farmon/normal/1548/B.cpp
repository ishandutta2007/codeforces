#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
long long a[N];
long long t[N][20];

long long gcd(long long x, long long y)
{
        if(!y){
                return x;
        }
        return gcd(y, x % y);
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int res = 1;
        for(int i = 1; i < n; i++){
                t[i][0] = abs(a[i] - a[i + 1]);
        }
        for(int i = 1; (1 << i) < n; i++){
                for(int j = 1; j + (1 << i) <= n; j++){
                        t[j][i] = gcd(t[j][i - 1], t[j + (1 << i - 1)][i - 1]);
                }
        }
        for(int i = 1; i < n; i++){
                if(t[i][0] == 1){
                        continue;
                }
                int h = i;
                long long f = t[i][0];
                for(int j = 19; j >= 0; j--){
                        if(h + (1 << j) <= n && gcd(f, t[h][j]) > 1){
                                f = gcd(f, t[h][j]);
                                h += (1 << j);
                        }
                }
                res = max(res, h - i + 1);
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