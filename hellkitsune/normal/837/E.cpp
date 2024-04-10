#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL a, b;

LL gcd(LL a, LL b) {
    while (b) a %= b, swap(a, b);
    return a;
}

vector<LL> p;

int main() {
    cin >> a >> b;
    LL rem = a;
    for (LL i = 2; i * i <= rem; ++i) {
        if (rem % i == 0) {
            p.pb(i);
            rem /= i;
            while (rem % i == 0) {
                rem /= i;
            }
        }
    }
    if (rem > 1) {
        p.pb(rem);
    }
    LL ans = 0;
    while (b) {
        LL g = gcd(a, b);
        a /= g;
        b /= g;
        LL steps = b;
        for (LL x : p) if (a % x == 0) {
            steps = min(steps, b % x);
        }
        ans += steps;
        b -= steps;
    }
    cout << ans << endl;
    return 0;
}