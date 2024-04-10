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
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.pb(a);
    }
    ll sum = 0;
    sort(all(v));
    int ans = 0;
    for (int i = 0, cur = 0; i < n; i++) {
        while (cur < v.size() && v[cur] < sum) {
            cur++;
        }
        if (cur == v.size()) {
            break;
        }
        ans++;
        sum += v[cur];
        cur++;
    }
    cout << ans << endl;
    return 0;
}