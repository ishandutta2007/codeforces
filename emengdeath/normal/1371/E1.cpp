#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<int>g[N];
int a[N];
int n, p;
int sum[N];
int main() {
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    bool sig = 1;
    for (int i = 1; i <= n; i ++) {
        int tmp = a[n] - a[i] + 1;
        if (tmp >= n) {
            sig &= ((i % p) != 0);
        } else {
            int v =  (tmp + p - (n - i) % p) % p;
            sum[v] ++;
            g[n - tmp].push_back(v);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n && sig; i ++)  {
        for (auto u:g[i])
            sum[u] --, sig &= ((u + i) % p != 0);
        if (!sig) break;
        if (!sum[(p - i % p) % p])
            ans.push_back(i + a[n] - (n - 1));
    }
    printf("%d\n", ans.size());
    for (auto u:ans)
        printf("%d ", u);
    return 0;
}