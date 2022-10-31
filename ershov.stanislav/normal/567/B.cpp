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

const int N = 1e5 + 100;

int n;
vector<pair<char, int> > v;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        int a;
        scanf(" %c %d", &c, &a);
        v.eb(c, a);
    }
    reverse(all(v));
    set<int> s;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i].fs == '+') {
            s.insert(v[i].sc);
        } else {
            if (s.count(v[i].sc) == 0) {
                v.eb('+', v[i].sc);
            }
        }
    }
    reverse(all(v));
    s.clear();
    int ans = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        if (v[i].fs == '+') {
            s.insert(v[i].sc);
        } else {
            s.erase(v[i].sc);
        }
        ans = max(ans, (int) s.size());
    }
    cout << ans << endl;
    return 0;
}