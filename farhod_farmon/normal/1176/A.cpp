#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
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
                long long x;
                cin >> x;
                int res = 0;
                while(x > 1){
                        if(x % 2 == 0){
                                res += 1;
                                x /= 2;
                        } else if(x % 3 == 0){
                                res += 2;
                                x /= 3;
                        } else if(x % 5 == 0){
                                res += 3;
                                x /= 5;
                        } else{
                                break;
                        }
                }
                if(x > 1){
                        res = -1;
                }
                cout << res << "\n";
        }
}