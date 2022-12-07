#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b, p, q;

LL gcd(LL a, LL b) {
    while (b) a %= b, swap(a, b);
    return a;
}

LL lcm(LL a, LL b) {
    return a * b / gcd(a, b);
}

int main() {
    cin >> n >> a >> b >> p >> q;
    if (p < q) {
        swap(a, b);
        swap(p, q);
    }
    LL ans = 0;
    ans = (LL)n / a * p;
    ans += (LL)(n / b - n / lcm(a, b)) * q;
    cout << ans << endl;
    return 0;
}