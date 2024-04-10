#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
void exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) return x = 1, y = 0, void();
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
ll mult(ll a, ll b, ll mod) {
    ll ans = a * b - (long long)((long double) a * b / mod) * mod;
    if(ans < 0) ans += mod;
    if(ans >= mod) ans -= mod;
    return ans;
}
int main() {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll g = gcd(w, d);
    if(p % g) return puts("-1"), 0;
    p /= g, w /= g, d /= g;
    ll x, y;
    exgcd(w, d, x, y);
    x = mult((x % d + d) % d, p, d);
    y = mult((y % w + w) % w, p, w);
    ll now = x * w + y * d;
    if(now > p) return puts("-1"), 0;
    if(w > d) x += (p - now) / w;
    else y += (p - now) / d;
    if(x + y > n) return puts("-1"), 0;
    return cout << x << ' ' << y << ' ' << n - x - y, 0;
}