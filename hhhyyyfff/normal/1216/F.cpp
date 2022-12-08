#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

struct Node {
    long long cost;
    int last;
};
queue<Node> q;
char s[200010];
int n, k;
long long f[200010];

int main() {
    scanf("%d%d%s", &n, &k, s + 1);
    for (int i = 1; i <= k + 1; ++i) if (s[i] == '1') q.push({i, i + k});
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && q.front().last < i) q.pop();
        f[i] = min(f[i - 1] + i, q.empty() ? (long long)n * n : q.front().cost);
        if (i + k + 1 <= n && s[i + k + 1] == '1') q.push({f[i] + i + k + 1, i + k + k + 1});
    }
    printf("%I64d\n", f[n]);
    return 0;
}