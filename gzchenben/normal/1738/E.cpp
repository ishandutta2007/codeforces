#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int t,n;
long long fac[100005],inv[100005];
long long mod = 998244353;

long long qpow(long long x,long long y)
{
    long long res = 1;
    while(y)
    {
        if(y&1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
long long C(int x,int y)
{
    return fac[x] * inv[y] % mod * inv[x-y] % mod;
}
long long F(int x,int y)
{
    long long res = 0;
    for(int j=0;j<=min(x,y);j++)
    {
        res += C(x,j) * C(y,j) % mod;
        res %= mod;
    }
    // printf("F(%d %d) = %lld\n",x,y,res);
    return res;
}
int main()
{
    fac[0] = 1;
    inv[0] = 1;
    for(int i=1;i<=100000;i++)
    {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = qpow(fac[i],mod-2);
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        vector<long long> a(n+1),sum(n+1);
        long long ans = 1;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        int cur1 = 1,cur2 = n-1;
        while(1)
        {
            if(sum[cur1] != sum[n] - sum[cur2])
            {
                if(sum[cur1] < sum[n] - sum[cur2])
                    cur1++;
                else
                    cur2--;
                continue;
            }
            // printf("? %d %d\n",cur1,cur2);
            if(sum[cur1] == sum[cur2])
            {
                for(int i=cur1;i<=cur2;i++) ans = ans * 2 % mod;
                break;
            }
            if(sum[cur1] > sum[cur2]) break;
            int cnt1 = 1,cnt2 = 1;
            while(a[cur1 + 1] == 0 && cur1 != cur2)
            {
                cur1++;cnt1++;
            }
            while(a[cur2] == 0 && cur1 != cur2)
            {
                cur2--;cnt2++;
            }
            cur1++;
            ans = ans * F(cnt1,cnt2) % mod;
        }
        printf("%lld\n",ans);
    }  
}