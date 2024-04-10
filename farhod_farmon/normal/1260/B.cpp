#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                long long a, b;
                cin >> a >> b;
                long long y = (2 * a - b) / 3;
                long long x = a - 2 * y;
                if(x >= 0 && y >= 0 && x + 2 * y == a && y + 2 * x == b){
                        cout << "Yes" << "\n";
                } else{
                        cout << "No" << "\n";
                }
        }
}