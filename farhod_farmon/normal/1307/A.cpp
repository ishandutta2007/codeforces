#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, d, res;
                cin >> n >> d >> res;
                for(int i = 1; i < n; i++){
                        int x;
                        cin >> x;
                        while(x > 0 && d >= i){
                                d -= i;
                                res += 1;
                                x -= 1;
                        }
                }
                cout << res << "\n";
        }
}