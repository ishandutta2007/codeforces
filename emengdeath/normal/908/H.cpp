#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
using namespace std;
const int N = 100000;
namespace FWT
{
    int MOD,inv2;
    void FWT_or(int *a,int N,int opt)
    {
        for(int i=1;i<N;i<<=1)
            for(int p=i<<1,j=0;j<N;j+=p)
                for(int k=0;k<i;++k)
                    if(opt==1)a[i+j+k]=(a[j+k]+a[i+j+k])%MOD;
                    else a[i+j+k]=(a[i+j+k]+MOD-a[j+k])%MOD;
    }
    int S_NFWT_or(int *a,int x,int N)
    {
        if (N == 1) return a[x];
        return (x & (N >> 1)) ? (S_NFWT_or(a, x, N >> 1) - S_NFWT_or(a, x - (N >> 1), N >> 1)+MOD) % MOD :S_NFWT_or(a, x, N >> 1);
    }
    void FWT_and(int *a,int N,int opt)
    {
        for(int i=1;i<N;i<<=1)
            for(int p=i<<1,j=0;j<N;j+=p)
                for(int k=0;k<i;++k)
                    if(opt==1)a[j+k]=(a[j+k]+a[i+j+k])%MOD;
                    else a[j+k]=(a[j+k]+MOD-a[i+j+k])%MOD;
    }

    int S_NFWT_and(int *a,int x,int N)
    {
        if (N == 1) return a[x];
        return (x & (N >> 1)) ? (S_NFWT_and(a, x, N >> 1)) %MOD:(S_NFWT_and(a, x, N >> 1) - S_NFWT_and(a, x + (N >> 1), N >> 1)+MOD) % MOD ;
    }
    void FWT_xor(int *a,int N,int opt)
    {
        for(int i=1;i<N;i<<=1)
            for(int p=i<<1,j=0;j<N;j+=p)
                for(int k=0;k<i;++k)
                {
                    int X=a[j+k],Y=a[i+j+k];
                    a[j+k]=(X+Y)%MOD;a[i+j+k]=(X+MOD-Y)%MOD;
                    if(opt==-1)a[j+k]=1ll*a[j+k]*inv2%MOD,a[i+j+k]=1ll*a[i+j+k]*inv2%MOD;
                }
    }

    int S_NFWT_xor(int *a,int x,int N)
    {
        if (N == 1) return a[x];
        return (x & (N >> 1))?(-S_NFWT_xor(a, x, N >> 1) + S_NFWT_xor(a, x ^ (N >> 1), N >> 1) +MOD)* 1ll * inv2 % MOD:(S_NFWT_xor(a, x, N >> 1) + S_NFWT_xor(a, x ^ (N >> 1), N >> 1))* 1ll * inv2 % MOD;
    }
}
namespace can_k_colored{
    int f[1 << 23], g[1 << 23];
    int n;
    int work()
    {
        if (!n) return 0;
        FWT::MOD=123456789;
        FWT::FWT_or(f, (1 << n), 1);
        for (int i = 0; i < (1 << n); i ++)
            g[i] = f[i];
        int k = 1;
        while (!FWT::S_NFWT_or(f,  (1 << n) - 1, (1 << n))) {
            k ++;
            for (int i = 0; i < (1 << n); i ++)
                f[i] = (long long) f[i] * g[i] % FWT::MOD;
        }
        return k;
    }
}
int n, tot;
int fa[N], sum[N], id[N];
int g[N];
int d[N][2];
int getfa(int x) {return fa[x] == x? x: fa[x] =getfa(fa[x]);}
int main()
{
  //  freopen("input", "r",stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        fa[i] = i, sum[i] = 1;
    for (int i = 1;i  <= n ; i ++)
    {
        for (int j = 1;  j<= n ; j ++)
        {
            char c;
            scanf(" %c", &c);
            if (c == 'A')
            {
                if (getfa(i) != getfa(j)) {
                    sum[getfa(j)] += sum[getfa(i)];
                    fa[getfa(i)] = getfa(j);
                }
            } else
                if (c == 'X') {
                    d[++ tot][0] = i;
                    d[tot][1] = j;
                }
        }
    }
    int ans = n - 1;
    for (int i = 1; i <= n ; i ++)
        if (getfa(i) == i && sum[i] > 1)
            id[i] = id[0] ++;
    for (int i = 1; i <= tot; i ++)
        if (sum[getfa(d[i][0])] > 1 && sum[getfa(d[i][1])] > 1) {
            if (getfa(d[i][0]) == getfa(d[i][1])) {
                printf("-1");
                return 0;
            } else {
                int x = id[getfa(d[i][0])], y = id[getfa(d[i][1])];
                g[x] |= (1 << y);
                g[y] |= (1 << x);
            }
        }
    for (int i = 0 ;i < (1 << id[0]); i ++){
        bool sig = 1;
        for (int j = 0;j < id[0]; j ++)
            if ((i & (1 << j )) && (i & g[j]))
            {
                sig =  0;
                break;
            }
        can_k_colored::f[i] = sig;
    }
    can_k_colored::n = id[0];
    printf("%d\n", ans + can_k_colored::work());
    return 0;
}