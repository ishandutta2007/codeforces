#include <algorithm>
#include <cstdio>
#include <unordered_map>
using namespace std;
pair<pair<int, long long>, pair<int, int>> f[1011][7000];
int n, tot;
long long k, a[10000];
int sum[10000], w[10000], sum1[10000];
void update(pair<pair<int, long long>, pair<int, int> > &a, const pair<pair<int, long long>, pair<int, int> > & b) {
    if (!a.first.first || (a.first.first > b.first.first|| (a.first.first == b.first.first && a.first.second > b.first.second))) a = b;
}
void dfs(int x, int y,int toy, int i, long long v) {

    if (x > tot) {
        if (f[i][y].first.first)
            update(f[i + 1][toy], make_pair(make_pair(f[i][y].first.first + 1, f[i][y].first.second + v), make_pair(i, y)));
        return;
    }
    for (int j = 0; j <= sum[x] ; j ++)
        dfs(x + 1, y + w[x] * j, toy + w[x] * min(j+sum1[x], sum[x]),i, v);
}
int main() {
    scanf("%d %lld", &n, &k);
    long long x = k;
    for (int i = 2; 1ll *i *i <= x; i ++)
        if (x % i == 0){
            a[++tot] = i;
            while (x % i == 0) sum[tot] ++, x /= i;
        }
    if (x!=1) a[++tot] = x, sum[tot] = 1;
    w[1] = 1;
    for (int i = 2; i <= tot+1; i ++)
        w[i] = w[i - 1] * (sum[i - 1] + 1);
    f[0][0] = make_pair(make_pair(1, 0), make_pair(0, 0));
    long long mn = 1e18;
    int id = 0;
    for (int i = 0; i < n; i ++) {
        long long x;
        long long tmp;
        scanf("%lld", &x);
        if (x < mn) mn = x, id = i + 1;
        tmp = x;
        for (int i = 1; i <= tot; i ++) {
            sum1[i] = 0;
            while (x % a[i] == 0) sum1[i] ++, x /= a[i];
            sum1[i] = min(sum1[i], sum[i]);
        }
        dfs(1, 0, 0, i, tmp);
        for (int j = 0; j < w[tot + 1]; j ++)
            if (f[i][j].first.first) {
                update(f[i + 1][j], f[i][j]);
            }
    }
    x = n;
    int y = w[tot + 1] - 1;
    if (!f[n][y].first.first) {
        puts("-1");
        return 0;
    }
    if (f[x][y].first.first == 1) {
        printf("1\n%d\n", id);
        return 0;
    }
    printf("%d\n", f[x][y].first.first - 1);
    while (x) {
        auto u = f[x][y];
        x = u.second.first;
        y = u.second.second;
        if (u.first != f[x][y].first)
        printf("%d " , u.second.first  +1);
    }
    return 0;
}