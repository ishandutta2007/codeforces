#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLL;

int n, k, b, c;
int a[200000];
const int INF = 2e9;
priority_queue<LL> q;

int getMod(int x) {
    int res = x % 5;
    if (res < 0) res += 5;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &k, &b, &c);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    LL ans = 9e18;
    b = min(b, 5 * c);
    REP(i, 5) {
        int x = INF + i;
        LL tot = 0;
        while (!q.empty()) q.pop();
        REP(j, n) {
            int y = a[j];
            LL cost = 0;
            while (getMod(y) != i) ++y, cost += c;
            cost += (LL)b * (((LL)x - y) / 5);
            q.push(cost);
            tot += cost;
            if ((int)q.size() > k) {
                tot -= q.top();
                q.pop();
            }
            int num = a[j];
            while (getMod(num) != i) ++num;
            if (j >= k - 1) {
                ans = min(ans, tot - ((LL)x - num) / 5 * (LL)b * k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}