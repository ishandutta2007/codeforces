#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 1 << 21;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < long long > a(n), b(n);
        for(int i = 0; i < n; i++){
                cin >> a[i];
                a[i] = a[i] * (i + 1) * (n - i);
        }
        for(int i = 0; i < n; i++){
                cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long res = 0;
        for(int i = 0; i < n; i++){
                res = (res + a[i] % mod * b[n - i - 1]) % mod;
        }
        cout << res << "\n";
}