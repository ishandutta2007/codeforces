#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, q;
int from[500000], to[500000], w[500000], ord[500000], tmp[500000];
int c[1000], col[1000];
vector<int> cm[1000];

inline bool cmp(const int &lhs, const int &rhs) {
    return w[lhs] > w[rhs];
}

void reord(int *a) {
    REP(i, m) tmp[i] = a[ord[i]];
    REP(i, m) a[i] = tmp[i];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    REP(i, m) scanf("%d%d%d", from + i, to + i, w + i), --from[i], --to[i];
    REP(i, m) ord[i] = i;
    sort(ord, ord + m, cmp);
    reord(from);
    reord(to);
    reord(w);
    REP(times, q) {
        int l, r;
        scanf("%d%d", &l, &r), --l, --r;
        REP(i, n) {
            c[i] = i;
            cm[i].clear();
            cm[i].pb(i);
            col[i] = 0;
        }
        int ans = -1;
        REP(i, m) {
            if (ord[i] < l || ord[i] > r) continue;
            int s = from[i];
            int t = to[i];
            if (c[s] == c[t]) {
                if (col[s] == col[t]) {
                    ans = w[i];
                    break;
                }
            } else {
                bool eq = col[s] == col[t];
                s = c[s];
                t = c[t];
                if (cm[s].size() < cm[t].size()) {
                    swap(s, t);
                }
                if (eq) {
                    for (int x : cm[t]) {
                        col[x] ^= 1;
                    }
                }
                for (int x : cm[t]) {
                    cm[s].pb(x);
                    c[x] = s;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}