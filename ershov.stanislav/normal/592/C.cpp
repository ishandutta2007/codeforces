#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    ll t, w, b;
    cin >> t >> w >> b;
    if (w > b) {
        swap(w, b);
    }
    ll g = gcd(w, b);
    ll ans = 0;
    if (w / g > t / b) {
        ans = min(w - 1, t);
    } else {
        ll l = w / g * b;
        ans = w * (t / l);
        ans += min(t % l + 1, w);
        ans--;
    }
    ll r = gcd(ans, t);
    ans /= r;
    t /= r;
    cout << ans << "/" << t << endl;
    return 0;
}