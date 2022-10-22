#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = 5005;
const int mod = 998244353;

int add(int x, int y) {
    if((x += y) >= mod) x -= mod;
    return x;
}

int mul(int x, int y) {
    LL z = (LL)x * y;
    return z - z / mod * mod;
}

int powt(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = mul(ans, a);
        b >>= 1;
        a = mul(a, a);
    }
    return ans;
}


int a[maxn];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    a[0] = 1;
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < k; ++j) a[j] = (a[j] + 1LL * (j + 1) * a[j + 1]) % mod;
        for(int j = k; j > 0; --j) a[j] = a[j - 1];
        a[0] = 0;
    }
    int ans = 0;
    for(int i = 0, u = 1, v = powt(m, mod - 2); i <= k; ++i) {
        ans = add(ans, mul(a[i], u));
        u = mul(u, mul(n - i, v));
    }
    cout << ans << endl;
    return 0;
}