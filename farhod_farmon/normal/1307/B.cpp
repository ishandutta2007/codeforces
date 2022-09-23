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
                int n, need;
                cin >> n >> need;
                int res = 1e9;
                for(int i = 1; i <= n; i++){
                        int x;
                        cin >> x;
                        if(need == x){
                                res = 1;
                        } else {
                                res = min(res, max(2, (need - 1) / x + 1));
                        }
                }
                cout << res << "\n";
        }
}