#include<bits/stdc++.h>
#include<ext/rope>
#define fi first
#define se second

using namespace std;
using namespace __gnu_cxx;

typedef long long LL;
typedef pair<int,int> P;

const int maxn = 4e5 + 5;
const int mod = 998244353;

int p[maxn], inv[maxn];
int x[maxn], y[maxn];
int f[maxn];

int C(int n, int m)
{
    return 1LL * p[n] * inv[m] % mod * inv[n - m] % mod;
}

void add(int x, int v)
{
    for (int i = x; i < 200005; i += i & (-i)) {
        f[i] += v;
    }
}

int getK(int x)
{
    int k = 0;
    for (int i = 1 << 18; i > 0; i >>= 1) {
        if (k + i < 200005 && f[k + i] < x) {
            k += i;
            x -= f[k];
        }
    }

    return k + 1;
}

void solve()
{
    int n, m;

    cin >> n >> m;
    int k = n - 1;
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> s;
    for (int i = m - 1; i >= 0; i--) {
        int l = getK(y[i]), r = getK(y[i] + 1);
        if (l + 1 == r) k--;
        add(l, -1);
        s.push_back(l);
    }

    for (auto e:s) add(e, 1);

    cout << C(n + k, k) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    p[0] = inv[0] = inv[1] = 1;
    for (int i = 1; i < maxn; i++) p[i] = 1LL * p[i - 1] * i % mod;
    for (int i = 2; i < maxn; i++) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    for (int i = 1; i < maxn; i++) inv[i] = 1LL * inv[i - 1] * inv[i] % mod;
    for (int i = 1; i < 200005; i++) add(i, 1);

    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}