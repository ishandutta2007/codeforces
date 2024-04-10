#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll xgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll g = xgcd(b, a%b, x, y), x1 = y;
    y = x - (a / b) * y;
    x = x1;
    return g;
}

ll invmod(ll a, ll mod) {
    ll x, y;
    ll d = xgcd(a, mod, x, y);
    if(d > 1) return -1;
    return ((x % mod) + mod) % mod;
}

bool linear_diophantine(ll a, ll b, ll c, ll &x, ll &y) {
    ll d = xgcd(a, b, x, y);
    if(c % d) return false;
    x = x * (c / d);
    y = y * (c / d);
    return true;
}

/// xi and yi are initial solutions of Diophantine
/// only works when both increases or both decreases
bool find_first_non_negative_solution(ll a, ll b, ll &xi, ll &yi) {
    ll g = abs(__gcd(a, b)), m;
    ll augx = b / g, augy = - a / g;

    ll m1 = -xi/augx;
    ll m2 = -yi/augy;
    if(augx > 0) { //ceiling
        if(xi % augx && (xi ^ augx) < 0) m1++;
        if(yi % augy && (yi ^ augx) < 0) m2++;

        m = max(m1, m2);
    } else { //floor
        if(xi % augx && (xi ^ augx) >= 0) m1++;
        if(yi % augy && (yi ^ augx) >= 0) m2++;

        m = min(m1, m2);
    }
    xi = xi + m * augx;
    yi = yi + m * augy;
    return true;
}

int main() {
    ll n, m, x, y, vx, vy;
    scanf("%lld %lld %lld %lld %lld %lld", &n, &m, &x, &y, &vx, &vy);

    if(vx == 0 && vy == 0) {
        printf("-1\n");
    }
    else if(vx == 0) {
        if(x != 0 && x != n) printf("-1\n");
        else printf("%lld %lld\n", x, (vy == 1) ? m : 0);
    }
    else if(vy == 0) {
        if(y != 0 && y != m) printf("-1\n");
        else printf("%lld %lld\n", (vx == 1) ? n : 0, y);
    }
    else {
        ll X, Y, dx, dy;
        dx = (vx == -1) ? x : (n - x);
        dy = (vy == -1) ? y : (m - y);

        if(!linear_diophantine(n, -m, dy - dx, X, Y)) {
            printf("-1\n");
        }

        else {
            find_first_non_negative_solution(n, -m, X, Y);
            printf("%lld %lld\n", ((X + (vx == 1)) % 2) ? n : 0, ((Y + (vy == 1)) % 2) ? m : 0);
        }
    }
    return 0;
}