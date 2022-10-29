#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
int f[N * 8];
int tag[N * 8];
int n, k, m;
set<pair<int, int> > g;
void update(int s) {
    f[s] = min(f[s + s], f[s+s + 1]);
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s] = n + n - r + 1;
        return;
    }
    build(l, (l + r) /2, s + s);
    build((l+r) / 2 + 1, r, s + s + 1);
    update(s);
}
void down(int l, int r, int s) {
    if (tag[s]) {
        f[s] += tag[s];
        if (l != r)
            tag[s+s] += tag[s], tag[s+ s+1] += tag[s];
        tag[s] = 0;
    }
}
void add(int l, int r, int s ,int ll, int v) {
    down(l, r, s);
    if (l > ll) return ;
    if (r <= ll) {
        tag[s] += v;
        down(l , r, s);
        return;
    }
    add(l, (l + r) / 2, s + s, ll, v);
    add((l + r) / 2 + 1, r, s+ s + 1, ll, v);
    update(s);
}
int get(int l, int r ,int s, int ll) {
    down(l, r, s);
    if (r <= ll) return f[s];
    if (l > ll) return n + n;
    return min(get(l, (l + r) / 2, s + s, ll), get((l + r) / 2 + 1, r, s + s + 1, ll));
}
int main() {
    scanf("%d %d %d", &n, &k, &m);
    build(1, n + n, 1);
    priority_queue<pair<int, pair<int, int> > > q;
    while (m --) {
        int x ,y;
        scanf("%d %d", &x, &y);
        if (g.find({x, y}) == g.end()) {
            g.insert({x, y}), q.push({y + abs(x - k), {x, y}}), add(1, n + n, 1, y + abs(x - k), -1);
        } else {
            g.erase({x, y});
            while (q.size() && g.find(q.top().second) == g.end()) q.pop();
            add(1, n + n, 1, y + abs(x - k), 1);
        }

        if (q.empty()){
            printf("0\n");
        } else {
            int tmp = n + n - max(q.top().first, n);
            printf("%d\n", max(q.top().first, n) + max(-(get(1, n + n, 1, max(n, q.top().first)) - tmp), 0) - n);
        }
    }
    return 0;
}