#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 1010;
const long long m1 = 1e9 + 3;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int n, x, y, d;
                cin >> n >> x >> y >> d;
                if(abs(x - y) % d == 0){
                        cout << abs(x - y) / d << "\n";
                }
                else{
                        int ans = 1e9;
                        if((y - 1) % d == 0){
                                ans = min(ans, (x - 2) / d + 1 + (y - 1) / d);
                        }
                        if((n - y) % d == 0){
                                ans = min(ans, (n - x - 1) / d + 1 + (n - y) / d);
                        }
                        if(ans == 1e9){
                                cout << -1 << "\n";
                        }
                        else{
                                cout << ans << "\n";
                        }
                }
        }
}