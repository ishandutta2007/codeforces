#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[2500][2500];
int v[3200000];
vector<PII> pos[3200000];
unsigned rem[2500][80];
const unsigned ONE = 1;

int main() {
    scanf("%d", &n);
    REP(i, n) REP(j, n) {
        scanf("%d", a[i] + j);
    }
    REP(i, n) if (a[i][i] != 0) {
        cout << "NOT MAGIC" << endl;
        return 0;
    }
    REP(i, n) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) {
        cout << "NOT MAGIC" << endl;
        return 0;
    }
    int cnt = 0;
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        v[cnt++] = a[i][j];
    }
    sort(v, v + cnt);
    cnt = unique(v, v + cnt) - v;
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        a[i][j] = a[j][i] = lower_bound(v, v + cnt, a[i][j]) - v;
        pos[a[i][j]].pb(mp(i, j));
    }
    REP(i, n) REP(j, n) rem[i][j >> 5] |= ONE << (j & 31);
    int blocks = (n + 31) >> 5;
    for (int z = 3199999; z > 0; --z) {
        for (const PII &p : pos[z]) {
            int i = p.first;
            int j = p.second;
            rem[i][j >> 5] &= ~(ONE << (j & 31));
            rem[j][i >> 5] &= ~(ONE << (i & 31));
        }
        for (const PII &p : pos[z]) {
            int i = p.first;
            int j = p.second;
            REP(k, blocks) if (rem[i][k] & rem[j][k]) {
                cout << "NOT MAGIC" << endl;
                return 0;
            }
        }
    }
    cout << "MAGIC" << endl;
    return 0;
}