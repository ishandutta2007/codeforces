#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 1e5 + 100;
int n, m;

int f[maxn], b[maxn];
vector<int> from[maxn];

int main () {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", f + i);
        from[f[i]].pb(i + 1);
    }
    vector<int> ans;
    bool exist = true;
    bool un = true;
    for (int i = 0; i < m; i++) {
        int b;
        scanf("%d", &b);
        if (sz(from[b]) == 0) {
            exist = false;
            break;
        } else if (sz(from[b]) > 1) {
            un = false;
        } else {
            ans.pb(from[b][0]);
        }
    }
    if (!exist) {
        cout << "Impossible" << endl;
    } else if (!un) {
        cout << "Ambiguity" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
    }
    return 0;
}