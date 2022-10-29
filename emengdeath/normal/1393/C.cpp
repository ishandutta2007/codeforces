#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int cnt[N];
int n, T;
bool check(int x) {
    priority_queue<int> q;
    for (int i = 1; i <= n; i ++) {
        g[i].clear();
        if (cnt[i])
            q.push(cnt[i]);
    }
    for (int i = 1; i <= n ; i ++) {
        for (auto u:g[i])
            q.push(u);
        if (q.empty()) return 0;
        auto u = q.top();
        q.pop();
        if (u > 1) {
            if (i + x + 1 > n) return 0;
            g[i + x + 1].push_back(u - 1);
        }
    }
    return 1;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) cnt[i] = 0;
        for (int i = 1; i <= n; i ++) {
            int x;
            scanf("%d", &x);
            cnt[x] ++;
        }
        int l = 0, r = n - 2, mid, s = 0;
        while (l <= r)
        {
            if (check(mid = (l + r) / 2)) s = max(s, mid), l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%d\n", s);
    }
    return 0;
}