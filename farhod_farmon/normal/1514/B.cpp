#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 300200;
const int mod = 1e9 + 7;

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
                int n, k;
                cin >> n >> k;
                int res = 1;
                for(int i = 0; i < k; i++){
                        res = 1ll * res * n % mod;
                }
                cout << res << "\n";
        }
}