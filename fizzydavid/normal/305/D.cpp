//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int mod=1e9+7;
int n,m,k;
ll pw2[1000111],pre[1000111];
int main()
{
    pw2[0]=1;
    for(int i=1;i<=1000000;i++)pw2[i]=pw2[i-1]*2%mod,pre[i]=1;
    scanf("%d%d%d",&n,&m,&k);
    int x,y,l=n+1,r=-1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(y-x!=1&&y-x!=k+1)
        {
            puts("0");
            return 0;
        }
        if(y-x==k+1)
        {
            l=min(l,x),r=max(r,x);
            pre[x]=0;
        }
    }
    for(int i=1;i<=n;i++)pre[i]+=pre[i-1];
    if(l+k+1<=r)
    {
        puts("0");
        return 0;
    }
    ll ans=1;
    if(r==-1)
    {
        for(int i=1;i<=n-k-1;i++)ans=(ans+pw2[pre[i-1]-pre[max(0,i-k-1)]])%mod;
    }
    else
    {
        for(int i=max(1,r-k);i<=l+k&&i+k+1<=n;i++)
        {
            if(pre[i]-pre[i-1]==0)continue;
            ans=(ans+pw2[pre[i-1]-pre[max(0,max(r-k-1,i-k-1))]])%mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}