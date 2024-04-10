#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;
ll x, y, n;
ll a[6];

int main()
{
    cin >> x >> y >> n;
    a[1] = (x % MOD + MOD) % MOD;
    a[2] = (y % MOD + MOD) % MOD;
    a[3] = ((y-x) % MOD + MOD) % MOD;
    a[4] = ((-x) % MOD + MOD) % MOD;
    a[5] = ((-y) % MOD + MOD) % MOD;
    a[0] = ((x-y) % MOD + MOD) % MOD;
    cout << a[n % 6];
}