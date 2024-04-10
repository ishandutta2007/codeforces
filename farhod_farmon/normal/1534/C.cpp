#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const int mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int b[N];
int c[N];
int used[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                used[i] = 0;
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                c[b[i]] = i;
        }
        int res = 1;
        for(int i = 1; i <= n; i++){
                if(used[i]){
                        continue;
                }
                int x = i;
                while(!used[x]){
                        used[x] = true;
                        x = c[a[x]];
                }
                res += res;
                if(res >= mod){
                        res -= mod;
                }
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