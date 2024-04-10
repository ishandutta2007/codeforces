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

const int N = 3e3 + 100;

int n, m, dist[N][N];

vector<int> graph[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (q.size()) {
            int cur = q.front();
            q.pop();
            for (auto j : graph[cur]) {
                if (dist[i][j] == INF) {
                    dist[i][j] = dist[i][cur] + 1;
                    q.push(j);
                }
            }
        }
    }
    int ans = INF;
    int s1, t1, l1, s2, t2, l2;
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n;  j++) {
            int cnt = dist[s1][i] + dist[s2][i] + dist[j][t1] + dist[j][t2] + dist[i][j];
//            cout << i << ' ' << j << ' ' << cnt << endl;
            if (l1 >= dist[s1][i] + dist[i][j] + dist[j][t1]) {
                if (l2 >= dist[s2][i] + dist[i][j] + dist[j][t2]) {
                    ans = min(cnt, ans);
                }
            }

            cnt = dist[s1][i] + dist[t2][i] + dist[j][t1] + dist[j][s2] + dist[i][j];
//            cout << i << ' ' << j << ' ' << cnt << endl;
            if (l1 >= dist[s1][i] + dist[i][j] + dist[j][t1]) {
                if (l2 >= dist[t2][i] + dist[i][j] + dist[j][s2]) {
                    ans = min(cnt, ans);
                }
            }
        }
    }
    if (dist[s1][t1] <= l1 && dist[s2][t2] <= l2) {
        ans = min(ans, dist[s1][t1] + dist[s2][t2]);
    }
    if (ans < INF) printf("%d\n", m - ans);
    else printf("-1\n");
    return 0;
}