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

const int N = 200;
const int M = 155;
const int BASE = 32;

struct bits {
    unsigned int a[(M + BASE - 1) / BASE];
    bits() {
        for (int i = 0; i < (M + BASE - 1) / BASE; i++) {
            a[i] = 0;
        }
    }
    void set(int i) {
        a[i >> 5] |= 1u << (i & (BASE - 1));
    }
    bool get(int i) {
        return a[i >> 5] & (1u << (i & (BASE - 1)));
    }
};

bool check(const bits & a, const bits & b) {
    for (int i = 0; i < (M + BASE - 1) / BASE; i++) {
        if (a.a[i] & b.a[i]) {
            return true;
        }
    }
    return false;
}

int n, m;
int u[N], v[N], d[N];
int r[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", v + i, u + i, d + i);
        v[i]--;
        u[i]--;
        r[i] = d[i];
    }
    r[m] = 0;
    sort(r, r + m + 1);
    int cntr = (int) (unique(r, r + m + 1) - r);
    vector<int> can(n);
    can[0] = 1;
    bool stop = false;
    for (int ir = 0; ir < cntr; ir++) {
        vector<int> dist(n, INF);
        vector<vector<int> > graph(n);
        for (int i = 0; i < m; i++) {
            if (d[i] <= r[ir]) {
                graph[v[i]].pb(u[i]);
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (can[i]) {
                dist[i] = 0;
                q.push(i);
            }
        }
        while (q.size()) {
            int cur = q.front();
            q.pop();
            if (cur == n - 1) {
                printf("%d\n", dist[cur] + r[ir]);
                stop = true;
                break;
            }
            for (auto i : graph[cur]) {
                if (dist[i] == INF) {
                    dist[i] = dist[cur] + 1;
                    q.push(i);
                }
            }
        }
        if (stop) {
            break;
        }
        if (ir + 1 < cntr) {
            int need = r[ir + 1] - r[ir];
            vector<bits> to(n), from(n);
            for (int i = 0; i < m; i++) {
                if (d[i] <= r[ir]) {
                    to[u[i]].set(v[i]);
                    from[v[i]].set(u[i]);
                }
            }
            while (need) {
                if (need & 1) {
                    vector<int> ncan(n);
                    for (int i = 0; i < n; i++) {
                        if (can[i]) {
                            for (int j = 0; j < n; j++) {
                                if (from[i].get(j)) {
                                    ncan[j] = true;
                                }
                            }
                        }
                    }
                    can = ncan;
                }
                vector<bits> nto(n), nfrom(n);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (check(from[i], to[j])) {
                            nfrom[i].set(j);
                            nto[j].set(i);
                        }
                    }
                }
                to = nto;
                from = nfrom;
                need >>= 1;
            }
        }
    }
    if (!stop) {
        printf("Impossible\n");
    }
    return 0;
}