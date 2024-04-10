#include<cstdio>
using namespace std;
long long n,m,k,a[500005],b[500005],rev[1000005],f[500005];
bool check(long long x)
{
//    printf("check: %lld ",x);
    long long tmp=0;
    while(x%n!=0)
    {
        if(a[((x-1)%n)+1]!=b[((x-1)%m)+1]) tmp++;
        x--;
    }
    long long cnt=0,now=1,sum=0;
    bool flag=false;
    while(cnt!=x/n)
    {
        if(flag && now==1)
        {
            long long Times=(x/n)/cnt;
            sum=sum*Times;
            cnt=cnt*Times;
            if(cnt==x/n) break;
        } 
        flag=true;
        sum+=f[now];
        cnt++;
        now=(now+n-1)%m+1;
    }
//    printf("%lld+%lld %lld\n",sum,tmp,k);
    return sum+tmp>=k;
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        rev[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&b[i]);
    }
    for(int i=1;i<=m;i++)
    {
        if(!rev[b[i]]) continue;
        f[((i-rev[b[i]])%m+m)%m+1]++;
    }
    for(int i=1;i<=m;i++)
    {
        f[i]=n-f[i];
    }
    long long L=0,R=1e18;
    while(L<R-1)
    {
        long long mid=(L+R)/2;
        if(check(mid)) R=mid;
        else L=mid;
    }
    printf("%lld\n",R);
}