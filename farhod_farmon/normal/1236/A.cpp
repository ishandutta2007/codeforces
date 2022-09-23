#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int a, b, c;
                cin >> a >> b >> c;
                int res = 0;
                for(int i = 0; i <= a; i++){
                        for(int j = 0; j <= b; j++){
                                int y = b - 2 * i - j;
                                int z = c - 2 * j;
                                if(y >= 0 && z >= 0){
                                        res = max(res, i + i * 2 + j + j * 2);
                                }
                        }
                }
                cout << res << "\n";
        }
}