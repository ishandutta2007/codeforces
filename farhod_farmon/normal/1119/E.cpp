#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        long long res = 0, f = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                long long g = min(1ll * a[i] / 2, f);
                res += g;
                f -= g;
                a[i] -= g * 2;
                res += a[i] / 3;
                f += a[i] % 3;
        }
        cout << res << "\n";
}