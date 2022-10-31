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

const int N = 1e6 + 100;

int n;
int l[N], r[N], cnt[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    for (int i = 0; i < N; i++) {
        l[i] = INF;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        l[a] = min(l[a], i);
        r[a] = max(r[a], i);
        cnt[a]++;
    }
    pair<int, int> mx = mp(-1, 0);
    int mxi = 0;
    for (int i = 0; i < N; i++) {
        pair<int, int> cur = mp(cnt[i], l[i] - r[i]);
        if (cur > mx) {
            mx = cur;
            mxi = i;
        }
    }
    cout << l[mxi] << ' ' << r[mxi] << endl;
    return 0;
}