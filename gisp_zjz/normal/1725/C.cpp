#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
ll pos[MAXN];
int fact[MAXN],invf[MAXN];
set<ll> s;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=300000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[300000]=pow_mod(fact[300000],MOD-2);
    for(int i=299999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) pos[i+1]=pos[i]+a[i];
    if(pos[n+1]&1) {printf("%d\n",pow_mod(m,n)); return 0;}
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(pos[i]<pos[n+1]/2)
            if(*lower_bound(pos+1,pos+n+1,pos[i]+pos[n+1]/2)==pos[i]+pos[n+1]/2) cnt++;
    int ans=0;
    for(int i=0;i<=min(m,cnt);i++)//number of diameters with same color
    {
        int rem=m-i;
        add(ans,1LL*comb(cnt,i)*comb(m,i)%MOD*fact[i]%MOD*pow_mod(1LL*rem*(rem-1)%MOD,cnt-i)%MOD*pow_mod(rem,n-2*cnt)%MOD);
    }
    printf("%d\n",ans);
    return 0;
}