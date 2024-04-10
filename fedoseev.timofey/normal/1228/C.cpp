#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> primes(int x) {
    vector <int> p;
    for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) {
            p.push_back(d);
            while (x % d == 0) x /= d;
        }
    }
    if (x != 1) p.push_back(x);
    sort(p.begin(), p.end());
    return p;
}

const int md = 1e9 + 7;

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int power(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int x; ll n;
    cin >> x >> n;
    auto p = primes(x);
    int ans = 1;
    for (int pr : p) {
        ll cr = 1;
        while (cr <= n / pr && cr * pr <= n) {
            cr *= pr;
            ans = mul(ans, power(pr % md, n / cr));
        }
    }
    cout << ans << '\n';
}