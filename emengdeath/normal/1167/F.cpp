#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
#include <unordered_map>
using namespace std;
const int N = 1e6  +1;
const int mod = 1e9 +7;
int n;
int a[N], b[N], f[N], r[N], l[N], o[N];
unordered_map<int, int>g;
long long ans;
void ins(int x, int v, bool down){
    if (down) {
        while (x) {
            (f[x] += v) %= mod;
            x -= x & -x;
        }
    } else {
        while (x<=n) {
            (f[x] += v) %= mod;
            x += x & -x;
        }
    }
}
int get(int x, bool down){
    int v = 0;
    if (down) {
        while (x) {
            (v += f[x]) %= mod;
            x -= x & -x;
        }
    } else {
        while (x<=n) {
            (v += f[x]) %= mod;
            x += x & -x;
        }
    }
    return v;
}
int main(){
    scanf("%d", &n);
    for (int i = 1;i <= n ; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    sort(b+1,b+n+1);
    for (int i = 1; i <= n ; i++)
        g[b[i]] = i;
    for (int i = 1; i <= n ; i++)
        a[i]= g[o[i] = a[i]];
    for (int i = n; i >= 1; i --)
    {
        r[i] = get(a[i], 1);
        ins(a[i], n - i + 1,0);
    }
    memset(f, 0, sizeof(f));
    for (int i =1 ;  i <= n ; i ++)
    {
        l[i] = get(a[i], 1);
        ins(a[i], i, 0);
    }
    for (int i = 1; i <= n ; i ++)
        ans = (ans + (1ll * l[i] * (n - i + 1) % mod + 1ll * r[i] * i % mod + 1ll * (n - i + 1) * i % mod) * o[i] % mod) % mod;
    cout<<ans;
    return 0;
}