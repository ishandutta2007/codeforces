#include <algorithm>
#include <cstdio>
#include <vector>

void add(std::vector<int>& cnt, int n, int k, int v)
{
    for (; k < n; k += ~k & k + 1) {
        cnt[k] += v;
    }
}

int update(int &x, int a, int threshold)
{
    int t = std::min(threshold - x, a);
    x += t;
    return t;
}

int main()
{
    int n, k, a, b, q;
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    std::vector<int> cnt(n), a_sum(n), b_sum(n);
    while (q --) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int d, a_;
            scanf("%d%d", &d, &a_);
            d --;
            add(cnt, n, d + 1, update(b_sum[d], a_, b));
            int t = update(a_sum[d], a_, a);
            if (d >= k) {
                add(cnt, n, 0, t);
                add(cnt, n, d - k + 1, -t);
            }
        } else {
            int p;
            scanf("%d", &p);
            p --;
            int result = 0;
            for (; p >= 0; p -= ~p & p + 1) {
                result += cnt[p];
            }
            printf("%d\n", result);
        }
    }
    return 0;
}