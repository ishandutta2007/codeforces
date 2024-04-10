#include <bits/stdc++.h>

using namespace std;

const int N = 200'007;
const int T = 1 << 18;
const int MOD = 998'244'353;

int n, v;
int tree[T + T];

int order[N];
tuple <long long, long long, int> P[N];

void update(int p, int v)
{
    p += T;
    while (p) {
        tree[p] = max(tree[p], v);
        p >>= 1;
    }
}

int ask(int from, int to)
{
    int ret = 0;
    from += T, to += T;

    while (from <= to) {
        if (from & 1) {
            ret = max(ret, tree[from]);
        }

        if (!(to & 1)) {
            ret = max(ret, tree[to]);
        }

        from = (from + 1) >> 1;
        to = (to - 1) >> 1;
    }

    return ret;
}

int main()
{
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        P[i] = {1LL * t * v, 1LL * t * v, i};
    }
    
    for (int i = 1; i <= n; ++i) {
        int s;
        scanf("%d", &s);

        auto &[x, y, id] = P[i];
        x -= s, y += s;
    }

    sort(P + 1, P + n + 1, [&](const tuple <long long, long long, int> &a, const tuple <long long, long long, int> &b){
        const auto &[ax, ay, aid] = a;
        const auto &[bx, by, bid] = b;

        if (ay == by) {
            return ax < bx;
        }

        return ay < by;
    });

    for (int i = 1; i <= n; ++i) {
        const auto &[_x, _y, id] = P[i];
        order[id] = i;
    }

    int ans = 0;
    sort(P + 1, P + n + 1);
    for (int i = 1; i <= n; ++i) {
        auto &[x, y, id] = P[i];
        if (x < 0 || y < 0) {
            continue;
        }

        int tmp = ask(1, order[id]) + 1;

        ans = max(ans, tmp);
        update(order[id], tmp);
    }

    printf("%d\n", ans);
    return 0;
}