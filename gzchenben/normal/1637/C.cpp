#include<cstdio>
#include<algorithm>
using namespace std;
int n,t;
long long a[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        int cnt1=0,cntO=0,cntE=0;
        for(int i=2;i<=n-1;i++)
        {
            if(a[i]==1) cnt1++;
            else if(a[i]%2==0 && a[i]!=0) cntE++;
            else if(a[i]%2==1) cntO++;
        }
        bool flag=(cntE) || ((cntO) && (cntO+cnt1>=2));
        if(!flag) 
        {
            printf("-1\n");
            continue;
        }
        long long ans=0;
        for(int i=2;i<=n-1;i++) ans+=(a[i]+1)/2;
        printf("%lld\n",ans);
    }
}