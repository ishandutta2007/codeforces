#include <algorithm>
#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
int n;
vector<pair<int, int> >g[N];
int add(int x, int y) {
    x += y;
    return x >= mod ? x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0? x + mod : x;
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
int h0, h1, h2, h3;
void dfs(int x, int fa, int t) {
    for (int i = 0; i < g[x].size(); i ++)
        if (g[x][i].first == fa) {
            for (int j = i + 1; j < g[x].size(); j ++)
                g[x][j - 1] = g[x][j];
            g[x].pop_back();
            break;
        }
    int y = upper_bound(g[x].begin(), g[x].end(),make_pair(0, t), [](pair<int, int > a, pair<int, int>b) {
        return a.second < b.second;
    }) - g[x].begin();
    int f0 = 1, f1 = 0, f2 = 0, f3 = 0;
    int cnt = 0;
    for (auto u:g[x]) {
        dfs(u.first, x, u.second);
        int w0 = mul(f0, add(h1, h3));
        int w1 = mul(f1, add(h2, h0));
        int w2 = add(mul(f2, add(h2, h0)), mul(f0, add(sub(h2, h1), h0)));
        int w3 = mul(f3, add(h2, h0));
        if (cnt < y) {
            w1 = add(w1, mul(f0, add(sub(h2, h1), h0)));
        } else
            if (cnt == y)
                w3 = add(w3, mul(f0, add(h2, h0)));
        f0 = w0, f1 = w1, f2 = w2, f3 = w3;
        cnt ++;
    }
    if (g[x].size() == y) f3 = add(f3, f0);
    h1 = f1;
    h0 = f0;
    h2 = f2;
    h3 = f3;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(make_pair(y, i));
        g[y].push_back(make_pair(x, i));
    }
    dfs(1, 0, 0);
    printf("%d\n", add(h2, h0));
    return 0;
}