#include<bits/stdc++.h>

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
#define rank _rank

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

const int N = 5e5 + 100;

char s[N];
int n, m;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif

    scanf("%d %d %s", &n, &m, s);
    ll ans = (m - 1) * 1ll * n;
    ll diff = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            diff++;
        }
    }
    ans += diff * n * 1ll * (m - 1);
    for (int i = n - 2, lst = n; i >= 0; i--) {
        if (i + 2 < n && s[i] != s[i + 2]) {
            lst = i + 2;
        }
        if (s[i] != s[i + 1]) {
            ans -= (lst - i - 1);
        }
    }

    cout << ans << endl;

    return 0;
}