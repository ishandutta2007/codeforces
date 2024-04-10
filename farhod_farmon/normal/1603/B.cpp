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
                int x, y;
                cin >> x >> y;
                if(x == y){
                        cout << x << "\n";
                } else if(x > y){
                        cout << x + y << "\n";
                } else{
                        cout << y - (y % x) / 2 << "\n";
                }
        }
}