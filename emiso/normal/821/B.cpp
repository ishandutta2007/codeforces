#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, m, b;

inline ll pa(ll ini, ll fim) {
    return (ini + fim) * (fim - ini + 1) / 2;
}

ll f(ll x, ll y) {
    ll ret = 0;
    while(y >= 0) {
        ret += pa(y, y + x);
        y--;
    }
    return ret;
}

int main() {
    scanf("%lld %lld", &m, &b);

    ll y = b, x = 0, best = 0;
    while(y >= 0) {
        best = max(best, f(x, y));
        y--;
        x += m;
    }


    printf("%lld\n", best);
    return 0;
}