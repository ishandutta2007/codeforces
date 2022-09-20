#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 21;
const int mod = 31607;

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
                int n;
                cin >> n;
                if(n < 9){
                        cout << 0 << "\n";
                } else{
                        cout << (n - 9) / 10 + 1 << "\n";
                }
        }
}