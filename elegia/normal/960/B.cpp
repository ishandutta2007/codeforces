#include <cstdio>

#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

typedef long long ll;

const int N = 1010;

int n, k1, k2;
int a[N];

int main() {
    ll ans = 0;
    scanf("%d%d%d", &n, &k1, &k2);
    k1 += k2;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    priority_queue<int> q;
    for (int i = 1; i <= n; ++i) {
        int b;
        scanf("%d", &b);
        a[i] -= b;
        if (a[i] < 0)
            a[i] = -a[i];
        q.push(a[i]);
    }
    sort(a + 1, a + n + 1, greater<int>());
    while (k1) {
        if (q.top() == 0)
            break;
        q.push(q.top() - 1);
        q.pop();
        --k1;
    }
    if (k1 != 0)
        printf("%d\n", k1 % 2);
    else {
        for (int i = 1; i <= n; ++i) {
            ans += q.top() * (ll) q.top();
            q.pop();
        }
        printf("%lld\n", ans);
    }
    return 0;
}