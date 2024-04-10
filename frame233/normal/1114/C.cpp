#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=1000005;
ll pr[N],pos;
bool B[N];
inline ll min(ll a,ll b){return a<b?a:b;}
int main()
{
    ll n,b;
    scanf("%lld %lld",&n,&b);
    B[1]=1;
    for(int i=2;i<=N-5;++i)
    {
        if(!B[i])
        {
            pr[++pos]=i;
            for(int j=(i<<1);j<=N-5;j+=i)
            {
                B[j]=1;
            }
        }
    }
    ll ans=1e18,tmp=b;
    for(int i=1;1LL*pr[i]*pr[i]<=tmp&&i<=pos;++i)
    {
        ll cnt=0,cur=0;
        while(!(b%pr[i]))
        {
            ++cnt;
            b/=pr[i];
        }
        if(cnt)
        {
            for(ll mul=pr[i],tmp=n;tmp;tmp/=mul)
            {
                cur+=tmp/mul;
            }
            ans=min(ans,cur/cnt);
        }
    }
    if(b!=1)
    {
        ll cur=0;
        for(ll mul=b,tmp=n;tmp;tmp/=mul)
        {
            cur+=tmp/mul;
        }
        ans=min(ans,cur);
    }
    printf("%lld\n",ans);
    return 0;
}