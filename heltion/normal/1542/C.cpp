#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, ans = 0;
        cin >> n;
        for (LL i = 2, lcm = 1; n; i += 1) {
            LL d = gcd(lcm, i);
            LL k = i / d;
            (ans += ((n / k * (k - 1)) + n % k) % mod * i) %= mod;
            lcm *= k;
            n /= k;
        }
        cout << ans << "\n";
    }
    return 0;
}