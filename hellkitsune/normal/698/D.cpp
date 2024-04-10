#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int k, n;
int ax[7], ay[7];
int ex[1000], ey[1000];
vector<vector<int> > all[7];
PII inv[7][1000];
int ord[7];
bool u[7];
bool inq[1000] = {};
bool ans[1000] = {};

int q[10];
void solve() {
    REP(i, n) if (!ans[i]) {
        q[0] = i;
        int qh, qt;
        for (qh = 0, qt = 1; qh < qt; ++qh) {
            int v = q[qh];
            int who = ord[qh];
            int pos = inv[who][v].first;
            int ind = inv[who][v].second;
            REP(j, ind) if (!inq[all[who][pos][j]]) {
                q[qt++] = all[who][pos][j];
                inq[all[who][pos][j]] = true;
                if (qt > k) break;
            }
            if (qt > k) break;
        }
        if (qt <= k) {
            ans[i] = true;
        }
        REP(j, qt) inq[q[j]] = false;
    }
}

void go(int pos) {
    if (pos == k) {
        solve();
        return;
    }
    REP(i, k) if (!u[i]) {
        ord[pos] = i;
        u[i] = true;
        go(pos + 1);
        u[i] = false;
    }
}

map<PII, vector<int> > ma;

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

inline bool cmp(const int &lhs, const int &rhs) {
    if (ex[lhs] != ex[rhs]) return ex[lhs] < ex[rhs];
    return ey[lhs] < ey[rhs];
}

int main() {
    scanf("%d%d", &k, &n);
    REP(i, k) scanf("%d%d", ax + i, ay + i);
    REP(i, n) scanf("%d%d", ex + i, ey + i);
    REP(i, k) {
        ma.clear();
        REP(j, n) {
            int x = ex[j] - ax[i];
            int y = ey[j] - ay[i];
            int g = gcd(abs(x), abs(y));
            x /= g;
            y /= g;
            ma[mp(x, y)].pb(j);
        }
        for (auto &p : ma) {
            sort(p.second.begin(), p.second.end(), cmp);
            if (p.first.first < 0 || (p.first.first == 0 && p.first.second < 0)) {
                reverse(p.second.begin(), p.second.end());
            }
            all[i].pb(p.second);
            REP(j, p.second.size()) {
                inv[i][p.second[j]] = mp((int)all[i].size() - 1, j);
            }
        }
    }
    go(0);
    int tot = 0;
    REP(i, n) if (ans[i]) {
        ++tot;
    }
    cout << tot << endl;
    return 0;
}