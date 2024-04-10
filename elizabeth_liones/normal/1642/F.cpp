#include <algorithm>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <array>
#include <iomanip>
#include <queue>
#include <random>
typedef long long ll;
using namespace std;

const int maxn = 1e5 + 5, maxm = 5, inf = ((int)2e9) + 5;
struct ar
{
    array<int, maxm> a;
    int w;
};
bool cmp(const ar& a, const ar& b)
{
    return a.w < b.w;
}
int n, m, cnt = 1;
int my[maxn][1 << maxm];
struct node
{
    unordered_map<int, int> m;
    int cnt;
    node() { cnt = 0, m.clear(); }
};
vector<node> nd;
int son(int v, int c)
{
    if (!nd[v].m.count(c)) nd[v].m[c] = cnt++;
    return nd[v].m[c];
}
void change(const array<int, maxm>& a, int c, int i = 0, int v = 0)
{
    if (i == m)
    {
        nd[v].cnt += c;
        return;
    }
    change(a, c, i + 1, v);
    change(a, c, i + 1, son(v, a[i]));
}
int sum(const array<int, maxm>& a, int i = 0, int v = 0)
{
    if (i == m) return nd[v].cnt;
    return sum(a, i + 1, v) - sum(a, i + 1, son(v, a[i]));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    nd.resize(n * (1 << m) + 5);
    vector<ar> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> v[i].a[j];
        sort(v[i].a.begin(), v[i].a.begin() + m);
        cin >> v[i].w;
    }
    sort(v.begin(), v.end(), cmp);
    int ans = inf;
    int l = 0, r = 0;
    while (r < n && sum(v[0].a) == 0) change(v[r++].a, 1);
    r--;
    if (sum(v[0].a)) ans = min(ans, v[l].w + v[r].w);
    while (l < r)
    {
        change(v[l++].a, -1);
        if (!sum(v[l].a)) continue;
        while (sum(v[l].a)) change(v[r--].a, -1);
        change(v[++r].a, 1);
        if (l < r) ans = min(ans, v[l].w + v[r].w);
    }
    cout << (ans == inf ? -1 : ans) << "\n";
    return 0;
}