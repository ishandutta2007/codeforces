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

int mn[100000];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    ll c, h1, h2, w1, w2;
    cin >> c >> h1 >> h2 >> w1 >> w2;
    ll ans = 0;
    if (w1 > 50000) {
        for (int i = 0; i <= c; i += w1) {
            ans = max(ans, h1 * i / w1 + ((c - i) / w2) * h2 );
        }
    }
    if (w2 > 50000) {
        for (int i = 0; i <= c; i += w2) {
            ans = max(ans, h2 * i / w2 + ((c - i) / w1) * h1 );
        }
    }
    if (h1 * w2 > h2 * w1) {
        swap(h1, h2);
        swap(w1, w2);
    }
    if (w1 <= 50000 && w2 <= 50000) {
        for (int i = 0; i < w2; i++) {
            mn[i] = INF + 100;
        }
        for (int i = 0; i < w2; i++) {
            mn[(w1 * i) % w2] = min(i, mn[(w1 * i) % w2]);
        }
        for (int i = c; i >= c - w2; i--) {
            if (mn[i % w2] * w1 > i) {
                continue;
            }
            ans = max(ans, h1 * mn[i % w2] + h2 * ( ((i - mn[i % w2] * w1) / w2)) );
        }
    }
    cout << ans << endl;
    return 0;
}