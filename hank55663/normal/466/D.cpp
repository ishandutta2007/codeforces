#include<cstdio>
#include<cstring>
const int MOD=1e9+7 ;
typedef long long ll;
using namespace std;
ll n,h,start=0,a[20000],ans;
ll solve()
{
    ans=1;
    for(int i=0;i<=n;i++)
    {
        int t=a[i+1]-a[i];
        if(t>1||t<-1)
        return 0;
        else if(t==1)
            start++;
        else if(t==-1)
        {
            ans=ans*start%MOD;
            start--;
        }
        else if(t==0)
        {
            ans=ans*(start+1)%MOD;
        }
    }
    return ans;
}
main()
{
    int i;
    scanf("%I64d %I64d",&n,&h);
    a[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        a[i]=h-a[i];
    }
    a[i]=0;
    printf("%I64d",solve());
    
    return 0;
}