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

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

ll v1, v2, t, d;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> v1 >> v2 >> t >> d;
    ll cur = v1, len = 0;
    for (ll i = 1; i <= t; i++) {
//        cout << cur << endl;
        len += cur;
        if (i < t) {
            cur = min(cur + d, v2 + d * (t - i - 1));
        }
    }
    cout << len << endl;
    return 0;
}