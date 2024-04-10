#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
using namespace std;
char s[N];
int tt[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,p,k;
        scanf("%d%d%d",&n,&p,&k);
        scanf("%s",s+1);
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=1e18;
        for(int i=n;i>=p;i--)
        {
            if(s[i]=='0') tt[(i-p)%k]++;
            ans=min(ans,1ll*y*(i-p)+1ll*x*tt[(i-p)%k]);
        }
        printf("%lld\n",ans);
        for(int i=0;i<=n;i++) tt[i]=0;
    }
    return 0;
}