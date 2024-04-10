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

const int N = 2200;

int n, m, s, t;
ll p[N], dist[N];
int short_dist_i[N], short_dist_j[N];
ll cnt[N][N], sum[N][N], mni[N][N], mnj[N][N], mxi[N][N], mxj[N][N];
vector<pair<int, ll> > graph[N];

void dijk(int b, int * short_dist) {
    for (int i = 0; i < n; i++) {
        dist[i] = lINF;
    }
    set<pair<ll, int> > magic;
    dist[b] = 0;
    magic.insert(mp(0, b));
    while (magic.size()) {
        int cur = magic.begin()->sc;
        magic.erase(magic.begin());
        for (auto & i : graph[cur]) {
            ll ndist = dist[cur] + i.sc;
            if (ndist < dist[i.fs]) {
                magic.erase(mp(dist[i.fs], i.fs));
                dist[i.fs] = ndist;
                magic.insert(mp(dist[i.fs], i.fs));
            }
        }
    }
    vector<ll> sorted(n);
    for (int i = 0; i < n; i++) {
        sorted[i] = dist[i];
    }
    sort(all(sorted));
    sorted.resize(distance(sorted.begin(), unique(all(sorted))));
    for (int i = 0; i < n; i++) {
        short_dist[i] = (int) (lower_bound(all(sorted), dist[i]) - sorted.begin());
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d%d%d", &n, &m, &s, &t);
    s--, t--;
    for (int i = 0; i < n; i++) {
        scanf(LLD, &p[i]);
    }
    for (int i = 0; i < m; i++) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        v--, u--;
        graph[v].eb(u, w);
        graph[u].eb(v, w);
    }
    dijk(s, short_dist_i);
    dijk(t, short_dist_j);

    for (int i = 0; i < n; i++) {
        cnt[short_dist_i[i]][short_dist_j[i]]++;
        sum[short_dist_i[i]][short_dist_j[i]] += p[i];
    }
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            cnt[i][j] += cnt[i + 1][j];
            sum[i][j] += sum[i + 1][j];
        }
    }
    for (int j = n; j >= 0; j--) {
        for (int i = 0; i <= n; i++) {
            cnt[i][j] += cnt[i][j + 1];
            sum[i][j] += sum[i][j + 1];
        }
    }
    for (int i = 0; i <= n; i++) {
        cnt[n + 1][i] = cnt[i][n + 1] = INF;
    }
    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            mni[i][j] = mni[i + 1][j];
            mnj[i][j] = mnj[i][j + 1];
            if (cnt[i][j] != cnt[i + 1][j]) {
                mni[i][j] = i + 1;
            }
            if (cnt[i][j] != cnt[i][j + 1]) {
                mnj[i][j] = j + 1;
            }
        }
    }
    ll dpi = 0, dpj = 0;
    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            dpi = sum[i][j] - mxi[mni[i][j]][j];
            dpj = sum[i][j] - mxj[i][mnj[i][j]];
            mxi[i][j] = min(mxi[i + 1][j], sum[i][j] + dpj);
            mxj[i][j] = min(mxj[i][j + 1], sum[i][j] + dpi);
        }
    }
    if (dpi > 0) {
        printf("Break a heart");
    } else if (dpi == 0) {
        printf("Flowers");
    } else if (dpi < 0) {
        printf("Cry");
    }
    return 0;
}