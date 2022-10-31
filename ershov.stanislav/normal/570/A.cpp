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
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int n, m, a[1000], cnt[1000];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int mxi = 1, mx = 0;
        for (int j = 1; j <= n; j++) {
            int r;
            cin >> r;
            if (r > mx) {
                mx = r;
                mxi = j;
            }
        }
        a[i] = mxi;
    }
    int mxi = 0, mx = 0;
    for (int i = 0; i < m; i++) {
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            mxi = i;
        }
    }
    cout << mxi << endl;
    return 0;
}