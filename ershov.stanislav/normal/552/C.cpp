#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

ll w, m;

bool get(ll r) {
    ll cur = 1;
    if (r == 0 || r == 1) {
        return true;
    }
    while (cur < r) {
        cur *= w;
    }
    if (cur - r > (cur - 1) / (w - 1) && r - cur / w > (cur / w - 1) / (w - 1)) {
        return false;
    } else {
        return get(min(cur - r, r - cur / w));
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    cin >> w >> m;

    if (w == 2 || w == 3) {
        cout << "YES" << endl;
    } else {
        cout << (get(m) ? "YES" : "NO") << endl;
    }

    return 0;
}