#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int r[100000], h[100000];
LL vol[100000];
int ind[100000];
vector<LL> v;

LL fen[100005] = {};

void fenAdd(int pos, LL val) {
    for (; pos <= n; pos |= pos + 1) {
        fen[pos] = max(fen[pos], val);
    }
}

LL fenGet(int pos) {
    LL res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res = max(res, fen[pos]);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", r + i, h + i);
    REP(i, n) vol[i] = (LL)r[i] * r[i] * h[i];
    REP(i, n) v.pb(vol[i]);
    sort(v.begin(), v.end());
    REP(i, n) ind[i] = lower_bound(v.begin(), v.end(), vol[i]) - v.begin();
    LL ans = 0;
    REP(i, n) {
        LL cur = fenGet(ind[i] - 1) + vol[i];
        fenAdd(ind[i], cur);
        ans = max(ans, cur);
    }
    double actualAns = atan2((double)0, -1) * ans;
    printf("%.12f\n", actualAns);
    return 0;
}