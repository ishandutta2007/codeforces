#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll MOD = 1000000007;
ll deg2[1001005];
string s;

int main()
{
    ios_base::sync_with_stdio(false);

    for (int i = 1; i < 1001005; ++i)
        deg2[i] = (deg2[i - 1] * 2 + 1) % MOD;
    cin >> s;
    int as = 0;
    ll ans = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == 'a')
            ++as;
        else
            (ans += deg2[as]) %= MOD;
    }
    cout << ans;

    return 0;
}