#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

void solve()
{
        int n;
        cin >> n;
        int res = 0;
        while(n % 2 == 0){
                int x = sqrt(n / 2);
                if(x * x == n / 2){
                        res = 1;
                }
                n /= 2;
        }
        cout << (res ? "YES" : "NO") << "\n";
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