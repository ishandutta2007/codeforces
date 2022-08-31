#include <cstdio>

#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int N = 200010;

int n, m, ans = 1;
map<int, int> dp[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        dp[i].insert(make_pair(-1, 0));
    while (m--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        int cur = prev(dp[u].lower_bound(w))->second + 1;
        ans = max(cur, ans);
        map<int, int>::iterator it = prev(dp[v].upper_bound(w));
        if (cur <= it->second)
            continue;
        if (it->first == w) {
            it->second = cur;
            continue;
        }
        it = dp[v].insert(make_pair(w, cur)).first;
        ++it;
        while (it != dp[v].end()) {
            if (it->second <= cur)
                dp[v].erase(it++);
            else
                break;
        }
    }
    printf("%d\n", ans);
    return 0;
}