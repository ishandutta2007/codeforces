#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int w[100000], used[100000], from[100000], to[100000];
vector<int> a, b;
const int INF = 1e9 + 7;

inline bool cmp(const int &lhs, const int &rhs) {
    return w[lhs] < w[rhs];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, m) scanf("%d%d", w + i, used + i);
    REP(i, m) if (used[i]) {
        a.pb(i);
    } else {
        b.pb(i);
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    REP(i, n - 1) {
        from[a[i]] = i;
        to[a[i]] = i + 1;
    }
    int p = 2, q = 0;
    for (int x : b) {
        if (w[x] < w[a[p - 1]]) {
            printf("-1\n");
            return 0;
        }
        from[x] = p;
        to[x] = q;
        if (++q == p - 1) {
            ++p;
            q = 0;
        }
    }
    REP(i, m) printf("%d %d\n", from[i] + 1, to[i] + 1);
    return 0;
}