#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 330;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                long long x, y, a, b;
                cin >> x >> y >> a >> b;
                long long res = 0;
                if(x <= 0 && y >= 0 || x >= 0 && y <= 0){
                        res += (abs(x) + abs(y)) * a;
                } else{
                        x = abs(x);
                        y = abs(y);
                        res += abs(x - y) * a;
                        res += min(min(x, y) * b, min(x, y) * 2 * a);
                }
                cout << res << "\n";
        }
}