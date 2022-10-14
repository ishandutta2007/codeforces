#include <cstdio>
#include <queue>

const int N = 300000;

int main()
{
#ifdef LOCAL_JUDGE
    freopen("D.in", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) == 1) {
        static int a[N];
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
        }
        std::priority_queue<int> queue;
        long long result = 0;
        for (int i = 0; i < n; ++ i) {
            if (!queue.empty() && queue.top() + a[i] > 0) {
                result += a[i] + queue.top();
                queue.pop();
                queue.push(-a[i]);
            }
            queue.push(-a[i]);
        }
        printf("%lld\n", result);
    }
}