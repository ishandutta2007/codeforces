#include<cstdio>
#include<algorithm>
using namespace std;
int n,t;
long long a[200005],s[200005],s2[200005];
int work(int x,int flag,long long val)
{
//    printf("check(%d,%d,%d)=",x,flag,val);
    int L=x,R=n;
    if(n%2!=flag) R--;
    while(L<R)
    {
        int mid=(L+R)/2;
        if(mid%2!=flag) mid++;
        if(s2[mid]-s2[x]>=val) R=mid-2;
        else L=mid;
    }
//    printf("%d\n",L);
    return L;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            s[i]=s[i-1]+a[i];
            if(i>=2) s2[i]=s2[i-2]+a[i];
        }
        long long ans=0,tmp=(s[n]+1)/2;
        for(int i=2;i<n-1;i++)
        {
            if(s[i]>s[n]/2) ans++;
        }
        for(int i=0;i<=n;i++)
        {
            long long Now=s[i];
            if(Now>=tmp) break;
            Now=tmp-Now;
            ans+=(work(i,i%2,Now)-i)/2+1;
//            printf("1-ans=%d\n",ans);
            if(Now>a[n] && i<=n-3) ans+=max((min(work(i,i%2,Now-a[n]),n-3)-i)/2+1,0);
//            printf("2-ans=%d\n",ans);
        }
        for(int i=3;i<=n;i++)
        {
            long long Now=s[i]-a[1];
            if(Now>=tmp) break;
            Now=tmp-Now;
            ans+=(work(i,i%2,Now)-i)/2+1;
//            printf("3-ans=%d\n",ans);
            if(Now>a[n] && i<=n-3) ans+=max((min(work(i,i%2,Now-a[n]),n-3)-i)/2+1,0);
//            printf("4-ans=%d\n",ans);
        }
        printf("%lld\n",ans%(998244353));
    }
}