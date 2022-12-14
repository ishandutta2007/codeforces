#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define MN 400000
#define mod 1000000007
using namespace std;
// my fast read template
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int n, ans, p[MN + 5], inv[MN + 5];

inline int C(int n, int m) { return n < m ? 0 : 1LL * p[n] * inv[m] % mod * inv[n - m] % mod; }

int main() {
    n = read();
    p[0] = p[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= MN; ++i) {
        p[i] = 1LL * p[i - 1] * i % mod;
        inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    }
    for (int i = 2; i <= MN; ++i) {
        inv[i] = 1LL * inv[i - 1] * inv[i] % mod;
    }
    for (int i = 0; i <= n; ++i) {
        int x = read();
        ans = (ans + C(x + i, i + 1)) % mod;
    }
    cout << ans;
    return 0;
}