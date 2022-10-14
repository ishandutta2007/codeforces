#include <algorithm>
#include <cassert>
#include <cstdio>
#include <utility>
#include <vector>

using LL = long long;
using Can = std::vector<std::pair<int, int>>;

const int N = 100000;

int n, s, a[N], b[N], c[N];

LL div(LL n)
{
    return (n + s - 1) / s;
}

LL gao(Can& can, int need)
{
    std::sort(can.begin(), can.end());
    LL result = 0;
    for (auto iterator : can) {
        auto delta = std::min(need, iterator.second);
        need -= delta;
        result += 1LL * iterator.first * delta;
    }
    return result;
}

LL solve()
{
    scanf("%d%d", &n, &s);
    LL need = 0;
    LL need_a = 0;
    LL need_b = 0;
    LL result = 0;
    Can can_a, can_b;
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d%d", c + i, a + i, b + i);
        need += c[i];
        if (a[i] > b[i]) {
            need_a += c[i];
            result += 1LL * a[i] * c[i];
            can_a.emplace_back(a[i] - b[i], c[i]);
        } else {
            need_b += c[i];
            result += 1LL * b[i] * c[i];
            can_b.emplace_back(b[i] - a[i], c[i]);
        }
    }
    if (div(need) == div(need_a) + div(need_b)) {
        return result;
    }
    fprintf(stderr, "MORE\n");
    assert(div(need) + 1 == div(need_a) + div(need_b));
    return result - std::min(gao(can_a, need_a % s), gao(can_b, need_b % s));
}

int main()
{
    printf("%lld\n", solve());
}