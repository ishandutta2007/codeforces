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

const int N = 1e5 + 100;
const int MOD = 1e9 + 7;

int n, m, k;

struct rat {
    ll a, b;
    rat(ll a = 0, ll b = 1) : a(a), b(b) {}
};

bool operator<(rat x, rat y) {
    return x.a * y.b - y.a * x.b < 0;
}

vector<int> graph[N];
bool used[N];
rat cur_ratio[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        int a;
        scanf("%d", &a);
        used[a] = true;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    set<pair<rat, int> > s;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            int cnt = 0;
            for (auto j : graph[i]) {
                if (!used[j]) {
                    cnt++;
                }
            }
            s.insert(mp(rat(cnt, (int) graph[i].size()), i));
            cur_ratio[i] = rat(cnt, (int) graph[i].size());
        }
    }

    rat cur = s.begin()->fs;
    int mx = 0;
    vector<int> v;
    while (s.size() > 1) {
        int i = s.begin()->sc;
        v.pb(i);
        s.erase(s.begin());
        for (auto j : graph[i]) {
            if (!used[j]) {
                s.erase(mp(cur_ratio[j], j));
                cur_ratio[j] = rat(cur_ratio[j].a - 1, cur_ratio[j].b);
                s.insert(mp(cur_ratio[j], j));
            }
        }
        if (!(s.begin()->fs < cur)) {
            cur = s.begin()->fs;
            mx = (int) v.size();
        }
        used[i] = true;
    }

    for (int i = (int) v.size() - 1; i >= mx; i--) {
        used[v[i]] = false;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}