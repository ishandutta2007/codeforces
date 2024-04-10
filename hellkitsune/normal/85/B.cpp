#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int k[3], t[3];
int n, cur;
priority_queue<LL, vector<LL>, greater<LL> > q[3];

int main() {
    REP(i, 3) scanf("%d", k + i);
    REP(i, 3) scanf("%d", t + i);
    scanf("%d", &n);
    LL ans = 0;
    REP(query, n) {
        scanf("%d", &cur);
        LL x = cur;
        REP(i, 3) {
            if ((int)q[i].size() < k[i]) {
                x += t[i];
                q[i].push(x);
            } else {
                LL mn = q[i].top();
                q[i].pop();
                x = max(x, mn) + t[i];
                q[i].push(x);
            }
        }
        ans = max(ans, x - cur);
    }
    printf("%I64d\n", ans);
    return 0;
}