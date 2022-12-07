#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = 1e18;
int n, b;
LL ans[200000];
queue<PII> q;
LL e = INF;

int main() {
    scanf("%d%d", &n, &b);
    REP(i, n) ans[i] = -1;
    REP(i, n) {
        int t, d;
        scanf("%d%d", &t, &d);
        while (e <= t) {
            if (q.empty()) {
                e = INF;
            } else {
                e += q.front().first;
                ans[q.front().second] = e;
                q.pop();
            }
        }
        if (e == INF) {
            ans[i] = t + d;
            e = t + d;
        } else if ((int)q.size() < b) {
            q.push(mp(d, i));
        }
    }
    while (!q.empty()) {
        e += q.front().first;
        ans[q.front().second] = e;
        q.pop();
    }
    REP(i, n) printf("%I64d ", ans[i]);
    printf("\n");
    return 0;
}