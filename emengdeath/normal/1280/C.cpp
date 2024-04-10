#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5;
int T;
int n;
long long deep[N];
long long ansmx, ansmn;
vector<pair<int, int>  >g[N];
int sz[N], mxsz[N], remain[N];
void dfs(int x, int fa) {
    ansmx += deep[x];
    ansmn += deep[x];
    sz[x] = 1;
    mxsz[x] = 1;
    remain[x] = 1;
    int tmp = 1;
    for (auto u:g[x])
        if (u.first != fa) {
            deep[u.first] = u.second + deep[x];
            dfs(u.first, x);
            sz[x] += sz[u.first];
            mxsz[x] = max(mxsz[x], sz[u.first]);
            remain[x] = max(remain[x], remain[u.first]);
            tmp += remain[u.first];
        }
    if (tmp - remain[x] <= remain[x]) {
        ansmn -= 2ll * deep[x] * (tmp - remain[x]);
        remain[x] = remain[x] - (tmp - remain[x]);
    } else {
        ansmn -= 2ll * deep[x] * (tmp / 2);
        remain[x] = (tmp & 1);
    }
}
void dfs(int x, int fa, int nowsz) {
    int tmp = sz[x] - nowsz;
    if (mxsz[x] - tmp > sz[x] - mxsz[x]) {
        int v = mxsz[x] - tmp - (sz[x] - mxsz[x]);
        ansmx -= 2ll * deep[x] * (nowsz - v) / 2;
        for (auto u:g[x])
            if (u.first != fa && sz[u.first] == mxsz[x]) {
                dfs(u.first, x, v);
                return;
            }
    } else {
        ansmx -= 2ll * deep[x] * nowsz / 2;
        return;
    }
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        n += n;
        for (int i = 1; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            g[x].push_back(make_pair(y, z));
            g[y].push_back(make_pair(x, z));
        }
        ansmx = ansmn = 0;
        dfs(1, 0);
        dfs(1, 0, sz[1]);
        printf("%lld %lld\n", ansmn, ansmx);
        for (int i =  1; i <= n; i ++)
            g[i].clear();
    }
    return 0;
}