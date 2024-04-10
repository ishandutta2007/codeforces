#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
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
int mx[maxn];

vector<pair<int, int> > tree, other;

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b == 1) {
            tree.eb(a, i);
        } else {
            other.eb(a, i);
        }
    }
    sort(all(tree));
    sort(all(other));
    mx[0] = INF;
    for (int i = 0; i < n - 1; i++) {
        mx[i + 1] = tree[i].fs;
    }
    bool ok = true;
    vector<pair<int, int> > ans(m);
    for (int cur = 2, i = 0; i < sz(other); ) {
        for (int j = 0; j < cur - 1 && i + j < sz(other); j++) {
            if (other[i + j].fs < mx[cur]) {
                ok = false;
            }
            ans[other[i + j].sc] = mp(j + 1, cur + 1);
        }
        i = i + cur - 1;
        cur++;
    }
    if (!ok) {
        printf("-1\n");
    } else {
        for (int i = 0; i < n - 1; i++) {
            ans[tree[i].sc] = mp(i + 1, i + 2);
        }
        for (int i = 0; i < m; i++) {
            printf("%d %d\n", ans[i].fs, ans[i].sc);
        }
    }
    return 0;
}