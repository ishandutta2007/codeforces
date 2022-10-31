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
#define all(s) (s).begin(), (s).end()

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 2e5 + 200;

int n, T;
vector<int> v[111];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &T);

    for (int i = 0; i < n; i++) {
        int t, q;
        scanf("%d%d", &t, &q);
        v[T - t].pb(q);
    }

    for (int i = T; i >= 1; i--) {
        if ((int) v[i].size() % 2 == 1) {
            v[i].pb(0);
        }
        sort(all(v[i]));
        for (int j = 0; j < (int) v[i].size(); j += 2) {
            v[i - 1].pb(v[i][j] + v[i][j + 1]);
        }
    }

    sort(all(v[0]));

    cout << v[0].back();

    return 0;
}