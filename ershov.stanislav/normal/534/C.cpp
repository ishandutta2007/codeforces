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

const int N = 200200;

ll n, d[N], s, A;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n >> A;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        s += d[i];
    }
    for (int i = 0; i < n; i++) {
        ll mn = max(1ll, A - s + d[i]);
        ll mx = min(d[i], A - (n - 1));
        cout << d[i] - mx + mn - 1 << ' ';
    }
    return 0;
}