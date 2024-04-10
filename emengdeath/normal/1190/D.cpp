#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 1;
int n;
long long ans;
pair<int, int> a[N];
int c[N];
int f[N * 4];
vector<int>g;
unordered_map<int, bool>F;
long long did(long long x) {
    return (x + 1) * x / 2;
}
int get(int l, int r, int s ,int ll, int rr){
    if (rr < c[l] || c[r] < ll) return 0;
    if (ll <= c[l] && c[r] <= rr) return f[s];
    return get(l, (l + r) / 2, s + s ,ll, rr ) +get((l + r) / 2 + 1, r, s + s + 1, ll, rr);
}
void ins(int l, int r,int s,int ll) {
    if (l == r) {
        f[s] = 1;
        return;
    }
    if (c[(l + r) / 2] >= ll) ins(l, (l + r)  /2 , s + s,ll);
    else
        ins((l + r) / 2 + 1, r, s + s + 1, ll);
    f[s] = f[s + s] + f[s + s + 1];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        scanf("%d %d", &a[i].second, &a[i].first), c[i] = a[i].second;
    sort(c + 1, c + n + 1);
    c[0] = 1;
    for (int i = 1; i <= n ; i++)
        if (c[i] != c[c[0]]) c[++c[0]] = c[i];
    sort(a + 1, a + n + 1);
    int all = 0;
    for (int i = n; i >= 1; i --) {
        if (i != n && a[i].first != a[i + 1].first) {
            sort(g.begin(), g.end());
            for (int i = 0; i < g.size(); i ++)
                if (i == 0)
                    ans -= did(get(1, c[0], 1, c[1], g[i] - 1));
                else
                    ans -= did(get(1, c[0], 1, g[i - 1] + 1, g[i] - 1));
            ans -= did(get(1, c[0], 1, g[g.size() - 1] + 1, c[c[0]]));
            ans += (long long) (all + 1) * all / 2;
            for (auto u:g)
                ins(1, c[0], 1, u);
            g.clear();
        }
        g.push_back(a[i].second);
        if (!F[a[i].second]) all ++, F[a[i].second] = 1;
    }
    sort(g.begin(), g.end());
    for (int i = 0; i < g.size(); i ++)
        if (i == 0)
            ans -= did(get(1, c[0], 1, c[1], g[i] - 1));
        else
            ans -= did(get(1, c[0], 1, g[i - 1] + 1, g[i] - 1));
    ans -= did(get(1, c[0], 1, g[g.size() - 1] + 1, c[c[0]]));
    ans += (long long) (all + 1) * all / 2;
    printf("%lld\n", ans);
    return 0;
}