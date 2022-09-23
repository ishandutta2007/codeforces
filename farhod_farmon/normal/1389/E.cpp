#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                long long m, d, w;
                cin >> m >> d >> w;
                if(d > 1){
                        w /= __gcd(w, d - 1);
                }
                long long res = 0;
                long long n = min(m, d) - 1;
                long long k = n / w;
                res += k * (k - 1) / 2 * w;
                res += k * (n % w + 1);
                cout << res << "\n";
        }
}