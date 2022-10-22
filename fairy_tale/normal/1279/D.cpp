#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int maxn = 1e6 + 5;
const int mod = 998244353;

int mul(int x, int y) {
    LL z = 1LL * x * y;
    return z - z / mod * mod;
}

int add(int x,int y) {
    x += y;
    if(x >= mod)
        x -= mod;
    return x;
}

int powt(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1)
            res = mul(res, a);
        b >>= 1;
        a = mul(a, a);
    }
    return res;
}

vector<int> f[maxn];
int d[maxn];

int main() {
#ifdef FEIFEI
    freopen("E:\\ACM\\test.txt", "r", stdin);
#endif
    int n, m, x, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &m);
        for(int j = 0; j < m; ++j) {
            scanf("%d", &x);
            d[x]++;
            f[i].push_back(x);
        }
    }
    for(int i = 1; i <= n; ++i) {
        x = 0;
        for(auto e:f[i]) x += d[e];
        ans = add(ans, mul(x, powt(f[i].size(), mod - 2)));
    }
    cout << mul(ans, powt(mul(n, n), mod - 2)) << endl;
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}