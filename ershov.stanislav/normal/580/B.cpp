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

int n, d;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &d);
    vector<pair<int, ll> > v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d" LLD, &v[i].fs, &v[i].sc);
    }
    sort(all(v));
    ll sum = 0;
    ll ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        sum += v[i].sc;
        while (j <= i && v[j].fs + d <= v[i].fs) {
            sum -= v[j].sc;
            j++;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;

    return 0;
}