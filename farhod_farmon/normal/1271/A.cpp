#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3030;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;

        int res = 0;
        for(int i = 0; i <= 100000; i++){
                if(min(a, d) < i){
                        continue;
                }
                int j = min(d - i, min(b, c));

                res = max(res, i * e + j * f);
        }

        cout << res << "\n";
}