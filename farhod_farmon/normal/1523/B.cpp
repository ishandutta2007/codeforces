#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;
const int mod = 998244353;

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
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                }
                cout << 6 * (n / 2) << "\n";
                for(int i = 1; i <= n; i += 2){
                        cout << 2 << " " << i << " " << i + 1 << "\n";
                        cout << 1 << " " << i << " " << i + 1 << "\n";
                        cout << 2 << " " << i << " " << i + 1 << "\n";
                        cout << 2 << " " << i << " " << i + 1 << "\n";
                        cout << 1 << " " << i << " " << i + 1 << "\n";
                        cout << 2 << " " << i << " " << i + 1 << "\n";
                }
        }
}