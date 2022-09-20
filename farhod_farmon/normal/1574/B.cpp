#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3003;

using namespace std;


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
                int a, b, c, m;
                cin >> a >> b >> c >> m;
                int sum = a + b + c - max({a, b, c}) + 1;
                if(max({a, b, c}) - sum <= m && m <= a + b + c - 3){
                        cout << "YES\n";
                } else{
                        cout << "NO\n";
                }
        }
}