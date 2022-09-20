#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1505;

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
                int a, b, c;
                cin >> a >> b >> c;
                if(c == 0){
                        cout << (a == b ? "YES" : "NO") << "\n";
                } else{
                        cout << ((abs(a - b) - 1) / c + 1 <= min(a, b) ? "YES" : "NO") << "\n";
                }
        }
}