#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                long long a, b;
                cin >> a >> b;
                long long res = (a + b) / 3;
                res = min(res, a);
                res = min(res, b);
                cout << res << "\n";
        }
}