#include <cstdio>
#include <vector>

const int N = 100000;

int p[N], size[N];
std::vector<int> children[N];
double result[N];

void dfs(int u, double sum)
{
    sum ++;
    result[u] = sum;
    for (auto&& v : children[u]) {
        dfs(v, sum + .5 * (size[u] - 1 - size[v]));
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++ i) {
        scanf("%d", p + i);
        p[i] --;
    }
    for (int i = n - 1; i >= 1; -- i) {
        size[i] ++;
        size[p[i]] += size[i];
        children[p[i]].push_back(i);
    }
    size[0] ++;
    dfs(0, 0.);
    for (int i = 0; i < n; ++ i) {
        printf("%f%c", result[i], " \n"[i == n - 1]);
    }
}