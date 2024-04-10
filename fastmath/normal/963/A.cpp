#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;
#define int long long

const int MOD = 1000 * 1000 * 1000 + 9;
const int INF = 1e9 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int fp(int a, int b) {
    if (b == 0) return 1;

    int t = fp(a, b / 2);
    if (b % 2 == 0) return mod(t * t);
    else return mod(mod(t * t) * a);
}

int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}

const int WANT = 50007;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    ++n;
    string s;
    cin >> s;

    while ((int)s.size() < WANT) s += s;

    int st = 0;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] == '+') st += mod(fp(a, n - i - 1) * fp(b, i));
        else st -= mod(fp(a, n - i - 1) * fp(b, i));
        st = mod(st); 
    }

    int ans = 0;
    int fact = 1;
    int step = mdiv(fp(b,len), fp(a, len));
    for (int i = 0; i < n / len; ++i) {
        ans += mod(st * fact);
        ans = mod(ans);
        fact = mod(fact * step);
    }
    
    for (int i = 0; i < n % len; ++i) {
        int p = (n / len) * len + i;
        if (s[i] == '+') ans += mod(fp(a, n - p - 1) * fp(b, p));
        else ans -= mod(fp(a, n - p - 1) * fp(b, p));
        ans = mod(ans);
    }

    ans = mod(ans);
    cout << ans << '\n';
    return 0;
}