#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int N = 1010;
const int mod = 1e9 + 7;
int na, nb;
vector<int>ga[N], gb[N];
namespace _prime{
    int d[N], a[N];
    void init() {
        for (int i = 2; i < N ; i ++) {
            if (!a[i])
                d[a[i] = ++d[0]] = i;
            for (int j = 1; j <= a[i] && 1ll * d[j] * i < N; j ++)
                a[d[j] * i] = j;
        }
    }
}
int randseed;
int rk_p(int rk){
    return _prime::d[rk + 1] * randseed;
}
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
int tot_status = 0;
pair<long long, int> status_list_all[4000];
int s_s_update[4000][4000];
map<pair<long long, int>, int> m_all;
int update(long long v, int sz) {
    if (m_all.find(make_pair(v, sz)) == m_all.end()) {
        status_list_all[++tot_status] = make_pair(v, sz);
        m_all[make_pair(v, sz)] = tot_status;
    }
    return m_all[make_pair(v,sz)];
}
int f[1001][4000];
int tmp[4000];
vector<pair<int, int> > can_merge;
int ans = 0;
vector<int> match_status;
void dfs(int x, int fa) {
    f[x][1] = 1;
    for (auto v:ga[x])
        if (v != fa) {
            dfs(v, x);
            for (auto u:can_merge)
                tmp[s_s_update[u.first][u.second]] = add(tmp[s_s_update[u.first][u.second]], mul(f[x][u.first], f[v][u.second]));
            for (int i = 1; i <= tot_status; i ++)
                f[x][i] = add(tmp[i], f[x][i]), tmp[i] = 0;
        }
    int last = 0;
    for (auto u:match_status)
        if (last != u)
            ans = add(ans, f[x][u]), last =u;
}
pair<long long,int> dfs1(int x, int fa) {
    long long v = 1;
    int sz = 1;
    for (auto u:gb[x])
        if (u != fa) {
            auto w = dfs1(u, x);
            v = v + w.first * rk_p(w.second);
            sz += w.second;
        }
    return make_pair(v, sz);
}
map<long long, int> can;

#include <ctime>
int main() {
    _prime::init();
    srand(time(0));
    randseed = rand() % 10000 + 1;
    update(1, 1);
    scanf("%d", &na);
    for (int i = 1; i < na; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        ga[x].push_back(y);
        ga[y].push_back(x);
    }

    scanf("%d", &nb);
    for (int i = 1; i < nb; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        gb[x].push_back(y);
        gb[y].push_back(x);
    }
    for (int i = 1; i <= nb; i ++) {
        auto v = dfs1(i, 0);
        can[v.first] = 1;
    }
    for (int v = 2; v <= 12; v ++)
        for (int i = 1; i <= tot_status; i ++)
            for (int j = 1;j <= tot_status; j ++)
                if (status_list_all[i].second + status_list_all[j].second == v && !(v == 12 && !can[status_list_all[i].first + status_list_all[j].first * rk_p(status_list_all[j].second)])) {
                    int u = update(status_list_all[i].first + status_list_all[j].first * rk_p(status_list_all[j].second) , status_list_all[i].second + status_list_all[j].second );
                    s_s_update[i][j] = u;
                    can_merge.push_back(make_pair(i, j));
                }
    for (auto u:can)
        if (u.second)
            match_status.push_back(update(u.first, nb));
    sort(match_status.begin(), match_status.end());
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}