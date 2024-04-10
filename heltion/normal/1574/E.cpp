#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
constexpr LL mod = 998244353;
LL pw[maxn];
struct {
    int c[3];
    int s[maxn][2];
    void erase(int x, int y, int z) {
        c[not s[x][0] + not s[x][1]] -= 1;
        s[x][(y ^ z) & 1] -= 1;
        c[not s[x][0] + not s[x][1]] += 1;
    }
    void insert(int x, int y, int z) {
        c[not s[x][0] + not s[x][1]] -= 1;
        s[x][(y ^ z) & 1] += 1;
        c[not s[x][0] + not s[x][1]] += 1;
    }
    LL ans() {
        return c[0] ? 0 : pw[c[2]];
    }
    void init(int n) {
        c[2] = n;
    }
}R, C;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < maxn; i += 1) pw[i] = i ? pw[i - 1] * 2 % mod : 1;
    int n, m, k;
    cin >> n >> m >> k;
    R.init(n);
    C.init(m);
    int c[2] = {};
    for (int i = 0; i < k; i += 1) {
        int x, y, z;
        cin >> x >> y >> z;
        if (mp.count({x, y})) {
            c[(x ^ y ^ mp[{x, y}]) & 1] -= 1;
            R.erase(x, y, mp[{x, y}]);
            C.erase(y, x, mp[{x, y}]);
            mp.erase({x, y});
        }
        if (z != -1) {
            c[(x ^ y ^ z) & 1] += 1;
            R.insert(x, y, z);
            C.insert(y, x, z);
            mp[{x, y}] = z;
        }
        cout << (R.ans() + C.ans() + mod - not c[0] - not c[1]) % mod << "\n";
    }
    return 0;
}