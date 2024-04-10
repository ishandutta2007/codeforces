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

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 2e5 + 100;

map<int, vector<int> > m;
int n, mx[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        m[a].pb(i);
    }
    multiset<int> ms;
    ms.insert(n);
    set<int> s;
    s.insert(0);
    s.insert(n + 1);
    for (auto i : m) {
        mx[*(ms.rbegin())] = i.fs;
        for (auto j : i.sc) {
            int nxt = *s.lower_bound(j);
            int prv = *(--(s.lower_bound(j)));
            ms.erase(ms.lower_bound(nxt - prv - 1));
            ms.insert(nxt - j - 1);
            ms.insert(j - prv - 1);
            s.insert(j);
        }
    }
    for (int i = n; i >= 0; i--) {
        mx[i] = max(mx[i], mx[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", mx[i]);
    }
    return 0;
}