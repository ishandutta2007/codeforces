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

int d[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif

    int n;
    int ans = 0;
    scanf("%d", &n);
    int lst = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        if (i > lst && d[i] < d[i - 1]) {
            ans = max(ans, i - lst);
            lst = i;
        }
    }
    ans = max(ans, n - lst);
    cout << ans << endl;

    return 0;
}