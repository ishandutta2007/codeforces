#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;
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
                long long x;
                cin >> x;
                if(x % 2050){
                        cout << -1 << "\n";
                        continue;
                }
                x /= 2050;
                int res = 0;
                while(x){
                        res += x % 10;
                        x /= 10;
                }
                cout << res << "\n";
        }
}