#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <utility>
#include <vector>

const int N = 200000;

int n, a[N], parent[N], order[N];
std::vector<int> tree[N];

void prepare(int u, int p, int&& t)
{
    parent[u] = p;
    order[t ++] = u;
    for (int v : tree[u]) {
        if (v != p) {
            prepare(v, u, std::move(t));
        }
    }
}

struct Sum
{
    Sum(int all = 0, int max = 0) : all(all), max(max) {}

    int all, max;
};

int all[N], zeros[N];
Sum down[N], up[N];
std::vector<int> maxs[N];

void append(std::vector<int>& v, int a)
{
    v.push_back(a);
    std::sort(v.begin(), v.end(), std::greater<int>());
    v.resize(2);
}

void update(int u, Sum sum)
{
    all[u] += sum.all;
    append(maxs[u], sum.max - sum.all);
    zeros[u] += !sum.all;
}

Sum summary(int all, int max, int zeros)
{
    return Sum(zeros ? 0 : all, max + all);
}

int check(int threshold)
{
    memset(down, 0, sizeof(down));
    memset(up, 0, sizeof(up));
    for (int i = n - 1; i >= 0; -- i) {
        int u = order[i];
        if (a[u] >= threshold) {
            all[u] = 1;
            zeros[u] = 0;
            maxs[u] = {0, 0};
            for (int v : tree[u]) {
                if (v != parent[u]) {
                    update(u, down[v]);
                }
            }
            down[u] = summary(all[u], maxs[u][0], zeros[u]);
        }
    }
    int best = down[0].max;
    for (int i = 0; i < n; ++ i) {
        int u = order[i];
        if (a[u] >= threshold) {
            if (i) {
                update(u, up[u]);
            }
            best = std::max(best, maxs[u][0] + all[u]);
            for (int v : tree[u]) {
                if (v != parent[u]) {
                    int all_u = all[u] - down[v].all;
                    int max_u = maxs[u][maxs[u][0] == down[v].max - down[v].all];
                    int zeros_u = zeros[u] - !down[v].all;
                    up[v] = summary(all_u, max_u, zeros_u);
                }
            }
        }
    }
    return best;
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    prepare(0, -1, 0);
    int low = 0;
    int high = *std::max_element(a, a + n);
    while (low < high) {
        int middle = low + high + 1 >> 1;
        if (check(middle) >= m) {
            low = middle;
        } else {
            high = middle - 1;
        }
    }
    printf("%d\n", low);
    return 0;
}