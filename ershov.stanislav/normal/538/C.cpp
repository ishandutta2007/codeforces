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

int n, m, d[100100], h[100100];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);

    int mx = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &d[i], &h[i]);
    }
    mx = max(mx, h[0] + d[0] - 1);
    mx = max(mx, h[m - 1] + n - d[m - 1]);
    for (int i = 0; i < m - 1; i++) {
        if (abs(h[i + 1] - h[i]) > d[i + 1] - d[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        mx = max(mx, max(h[i], h[i + 1]) + (d[i + 1] - d[i] - abs(h[i + 1] - h[i])) / 2);
    }
    cout << mx << endl;
    return 0;
}