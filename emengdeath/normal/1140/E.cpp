#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int N = 3e5+ 1;
const int mod = 998244353;
long long b[N], f[N][2];
vector<int>x;
int n, k;
int a[N];
long long ans;
long long calc(long long x, long long y) {
    long long z = 1;
    while (y)
    {
        if (y & 1) (z *= x) %= mod;
        (x *= x) %= mod, y/= 2;
    }
    return z;
}
long long ni(long long x) {
    return calc(x, mod -2);
}
void work(vector<int> & x)
{
    int l = -1;
    for (int i = 0; i < x.size(); i ++)
        if (x[i]!= -1)
        {
            int len = i - l - 1;
            if (len) {
                if (l == -1)
                    ans = ans * b[len] % mod;
                else {
                    if (x[l] == x[i])
                        ans = ans * f[len + 2][x[l] == x[i]] % mod;
                     else     ans = ans * f[len + 2][x[l] == x[i]]%mod * ni(k - 1)% mod;

                }
            }
            l = i;
        }
    int len = x.size() - l - 1;
    if (len)
    {
        if (l == -1)
        {
            ans = ans * b[len - 1]% mod * k %mod;
        }
        else{
            ans = ans * b[len] % mod;
        }
    }
}
int main(){
    scanf("%d %d", &n, &k);
    b[0] = 1;
    f[2][0] = (k - 1) % mod;
    f[2][1] = 0;
    for (int i = 2; i <= n ; i ++)
    {
        f[i + 1][0] = (f[i][0] * max(k - 2, 0) + f[i][1] * (k - 1)) % mod;
        f[i + 1][1] = f[i][0];
    }
    for (int i = 1; i <= n ; i ++)
        b[i] = b[i - 1] * (k - 1) % mod;
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]);
    for (int i = 1; i + 2<= n ;  i++)
        if (a[i] > 0 && a[i] == a[i + 2])
        {
            printf("0");
            return 0;
        }
    ans = 1;
    x.clear();
    for (int i = 1; i <= n ;  i+= 2)
        x.push_back(a[i]);
    work(x);
    x.clear();
    for (int i = 2; i <= n ;  i+= 2)
        x.push_back(a[i]);
    work(x);
    printf("%d\n", ans);
    return 0;
}