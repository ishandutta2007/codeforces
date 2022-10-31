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

const int INF = 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int n, a[1111];
char s[1111], t[1111];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d", &n);

    int ans = 0;

    scanf(" %s %s", s, t);

    for (int i = 0; i < n; i++) {
        int a = s[i] - '0', b = t[i] - '0';
        ans += min(abs(b - a), abs(min(b, a) + 10 - max(b, a)));
    }

    cout << ans << endl;

    return 0;
}