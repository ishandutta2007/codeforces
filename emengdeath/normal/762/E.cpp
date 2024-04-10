#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, int> > g[N];
int n, m;
int b[N];
int f[N];
int get(int x) {
    x = lower_bound(b + 1, b + b[0] + 1, x) - b;
    int v = 0;
    while (x > 0) {
        v += f[x];
        x -= x & -x;
    }
    return v;
}
void ins(int x, int v) {
    x = lower_bound(b+1, b+b[0] + 1, x) - b;
    while (x <= b[0]) {
        f[x] += v;
        x += x & -x;
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[z].push_back(make_pair(x, y));
    }
    long long ans = 0;
    for (int i = 1; i <= 10000; i ++) {
        b[0] = 0;

        vector<pair<pair<int, int> , int> > w;
        for (int j = 0; i - j >= 1 && j <= m; j ++)
            for (auto u:g[i - j])
                w.push_back(make_pair(make_pair(u.second, u.first), j == 0)), b[++b[0]] = u.first;
        sort(b+1,b+b[0]+1);
        int tmp = b[0]; b[0] = 1;
        for (int i = 1; i <= tmp; i ++)
            if (b[i] != b[b[0]])
                b[++b[0]] = b[i];
        for (int i = 1; i <= b[0]; i ++)
            f[i] = 0;
        sort(w.begin(), w.end());
        if (i == 10) {
            int yy;
            yy = 0;
        }
        for (auto u:w) {
            if (u.second)
                ans += get(u.first.second);
            ins(u.first.second - u.first.first, 1);
            ins(u.first.second + u.first.first + 1, -1);
        }
        for (int i= 1; i <= b[0]; i ++) f[i] = 0;
        for (auto u:w) {
            if (u.second){
                ins(u.first.second - u.first.first, 1);
                ins(u.first.second + u.first.first + 1, -1);
            } else
                ans += get(u.first.second);
        }
    }
    printf("%lld\n", ans);
    return 0;
}