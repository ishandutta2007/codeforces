#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> q;
        while(q--){
                int x;
                cin >> x;
                int y = 1;
                while(y <= x){
                        y += y;
                }
                if(y - 1 == x){
                        int res = 1;
                        for(int i = 2; i * i <= x; i++){
                                if(x % i == 0){
                                        res = max(res, i);
                                        res = max(res, x / i);
                                }
                        }
                        cout << res << "\n";
                }
                else{
                        cout << y - 1 << "\n";
                }
        }
}