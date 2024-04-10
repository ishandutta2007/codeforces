#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
const int maxn = 2010;
int n, pos[maxn]; ll S;
pair<ll, ll> p[maxn];

struct node {
    int i, j; ll x, y;
    bool operator < (const node &o) const { return x * o.y - o.x * y < 0; }
};
vector<node> V;

int main() {
    scanf("%d %lld", &n, &S), S <<= 1;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            V.emplace_back((node){i, j, p[j].x - p[i].x, p[j].y - p[i].y});
        }
    }
    sort(V.begin(), V.end());
    iota(pos + 1, pos + n + 1, 1);
    auto area = [&](int i, int j, int k) {
        return abs(1LL * (p[i].x - p[j].x) * (p[i].y - p[k].y) - 1LL * (p[i].x -
            p[k].x) * (p[i].y - p[j].y));
    };
    for (auto q : V) {
        int u = pos[q.i], v = pos[q.j];
        auto chk = [&](int l, int r, int op) {
            while (l <= r) {
                int mid = (l + r) >> 1;
                ll x = area(mid, u, v);
                if (x == S) {
                    puts("Yes");
                    printf("%lld %lld\n", p[u].x, p[u].y);
                    printf("%lld %lld\n", p[v].x, p[v].y);
                    printf("%lld %lld\n", p[mid].x, p[mid].y), exit(0);
                }
                (x > S) == op ? l = mid + 1 : r = mid - 1;
            }
        };
        chk(1, u - 1, 1), chk(v + 1, n, 0);
        swap(p[u], p[v]), swap(pos[q.i], pos[q.j]);
    }
    puts("No");
    return 0;
}