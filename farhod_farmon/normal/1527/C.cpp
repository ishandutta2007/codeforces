#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 50000;
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
                map < int, long long > c;
                long long res = 0;
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        res += c[x] * (n - i);
                        c[x] += i + 1;
                }
                cout << res << "\n";
        }
}