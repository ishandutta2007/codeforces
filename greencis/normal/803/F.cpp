#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1000000007;
int n, x, cnt[100105], ans[100105];
int deg2[100105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        for (int j = 1; j * j <= x; ++j) {
            if (x % j == 0) {
                ++cnt[j];
                if (j * j < x)
                    ++cnt[x / j];
            }
        }
    }

    deg2[0] = 1;
    for (int i = 1; i < 100105; ++i)
        deg2[i] = (deg2[i - 1] * 2) % MOD;

    for (int i = 100000; i >= 1; --i) {
        ans[i] = (deg2[cnt[i]] - 1 + MOD) % MOD;
        for (int j = i + i; j <= 100000; j += i)
            ans[i] = ((ans[i] - ans[j]) % MOD + MOD) % MOD;
    }

    cout << ans[1] << endl;

    return 0;
}