#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int p[1000000], q[1000000];
bool used[1000000] = {};
vector<int> cyc[1000001];
vector<int> cur, dur;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%d", p + i), --p[i];
    REP(i, n) if (!used[i]) {
        int cnt = 0;
        for (int j = i; !used[j]; j = p[j]) {
            used[j] = true;
            ++cnt;
        }
        cyc[cnt].pb(i);
    }
    for (int i = 2; i <= n; i += 2) if ((int)cyc[i].size() % 2 != 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i += 2) for (int x : cyc[i]) {
        cur.clear();
        for (int j = 0, y = x; j < i; ++j, y = p[y]) {
            cur.pb(y);
        }
        int half = i / 2;
        REP(j, half) {
            q[cur[j]] = cur[j + half + 1];
            q[cur[j + half + 1]] = cur[j + 1];
        }
        q[cur[half]] = cur[0];
    }
    for (int i = 2; i <= n; i += 2) for (int z = 0; z < (int)cyc[i].size(); z += 2) {
        cur.clear();
        dur.clear();
        for (int j = 0, y = cyc[i][z]; j < i; ++j, y = p[y]) {
            cur.pb(y);
        }
        for (int j = 0, y = cyc[i][z + 1]; j < i; ++j, y = p[y]) {
            dur.pb(y);
        }
        REP(j, i - 1) {
            q[cur[j]] = dur[j];
            q[dur[j]] = cur[j + 1];
        }
        q[cur[i - 1]] = dur[i - 1];
        q[dur[i - 1]] = cur[0];
    }
    REP(i, n) printf("%d ", q[i] + 1);
    printf("\n");
    return 0;
}