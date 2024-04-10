#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n;
vector<int>g[N];
vector<int> ans;
void dfs(int x) {
    while (g[x % (n / 2)].size()) {
        auto u = g[x % (n / 2)][0];
        swap(g[x % (n / 2)][0], g[x % (n / 2)][g[x % (n / 2)].size() - 1]);
        g[x % (n / 2)].pop_back();
        if (!(x * 2 % n == u || (x * 2 + 1) % n == u) || u == x)
            u += n / 2;
        dfs(u);
        ans.push_back(u);
    }
}
int main() {
    scanf("%d", &n);
    if (n & 1) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n / 2; i ++) {
        g[i % (n / 2)].push_back((i * 2 + 1) % n % (n / 2));
        g[i % (n / 2)].push_back(i * 2 % n % (n / 2));
    }
    dfs(0);
    reverse(ans.begin(), ans.end());
    printf("0");
    for (auto u:ans)
        printf(" %d", u);
    return 0;
}