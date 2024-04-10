#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
int n, m, q;
struct node{
    long long mn;
    long long tag;
    long long v(){
        return mn + tag;
    }
}f[N * 4];
long long v[N];
vector<pair<int, int> > g[N];
int a[N],b[N];
priority_queue<pair<long long, int> > w;
void build(int l, int r, int s) {
    if (l == r) {
        f[s].mn = b[l];
        return;
    }
    build(l,(l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    f[s].mn = min(f[s+s].mn, f[s+s+1].mn);
}
void ins(int l, int r, int s, int ll, int v) {
    if (l > ll) return;
    if (r <= ll) {
        f[s].tag += v;
        return;
    }
    ins(l, (l +r) / 2, s + s,ll, v);
    ins((l + r) / 2 + 1, r, s + s+ 1, ll, v);
    f[s].mn = min(f[s+s].v(), f[s+s+1].v());
}
long long get(int x) {
    return v[x] + a[x];
}
int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i < n; i ++)
        scanf("%d %d", &a[i], &b[i]);
    build(0, n - 1, 1);
    while (m --) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(make_pair(y, z));
    }
    for (int i = 1; i <= n; i ++){
        for (auto u:g[i])
            ins(0, n - 1, 1,u.first - 1, u.second);
        v[i] = f[1].v();
        w.push(make_pair(-get(i), i));
    }
    printf("%lld\n", -w.top().first);
    while (q --) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x] = y;
        w.push(make_pair(-get(x),x));
        while (get(w.top().second) != -w.top().first) w.pop();
        printf("%lld\n", -w.top().first);
    }
    return 0;
}