#include <bits/stdc++.h>

#define fi first
#define se second
#define int long long

const int MAX_N = 5005;

using namespace std;


signed main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                int res = 1;
                for(int i = 1; i <= n; i++){
                        int x;
                        cin >> x;
                        int j = i + 1;
                        while(x % j == 0 && j > 1){
                                j -= 1;
                        }
                        if(j == 1){
                                res = 0;
                        }
                }
                cout << (res ? "YES" : "NO") << "\n";
        }
}