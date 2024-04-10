#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[200005];
int CheckDir(long long NowVal,long long SumD,long long SumU,long long NumD,long long NumU,long long Minn,long long Maxn)
{
//    printf("%lld %lld %lld %lld %lld %lld %lld\n",NowVal,SumD,SumU,NumD,NumU,Minn,Maxn);
    long long ans=0;
    ans+=(SumD+SumU);
    ans+=(NumD*Maxn+NumU*Minn);
    ans-=(Minn+Maxn);
    if(NumD==0) ans=(SumU-Minn)+Minn*(NumU-1);
    if(NumU==0) ans=(SumD-Maxn)+Maxn*(NumD-1);
//    printf("--- %lld\n",ans);
    if(ans<0) return 1;
    if(ans==0) return 0;
    if(ans>0) return -1;
}
long long CheckPoint(long long NowVal,long long SumD,long long SumU,long long NumD,long long NumU,long long Minn,long long Maxn)
{
//    printf("%lld %lld %lld %lld %lld %lld %lld\n",NowVal,SumD,SumU,NumD,NumU,Minn,Maxn);
    long long ans=0;
    ans+=(SumD+SumU)*NowVal;
    ans+=(NumD*Maxn+NumU*Minn)*NowVal;
    ans-=(Minn+Maxn)*NowVal;
    ans+=(SumD*Maxn+SumU*Minn);
    ans-=Maxn*Minn;
    if(NumD==0) ans=(SumU-Minn)*NowVal+Minn*(NumU-1)*NowVal+(SumU-Minn)*Minn;
    if(NumU==0) ans=(SumD-Maxn)*NowVal+Maxn*(NumD-1)*NowVal+(SumD-Maxn)*Maxn;
//    printf("----- %lld\n",ans);
    return ans;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        long long sum=0;
        for(int i=1;i<=n;i++) sum+=a[i];
        sort(a+1,a+n+1);
        long long SumD=0,SumU=sum,NumD=0,NumU=n,Minn=a[1],Maxn=a[n],ans=-1e18;
        bool flag=false;
        a[0]=a[1];
        for(int i=0;i<=n;i++)
        {
            if(i)
            {
                SumU-=a[i];
                SumD+=a[i];
                NumU--;
                NumD++;
            }
            int dir=CheckDir(-a[i],SumD,SumU,NumD,NumU,Minn,Maxn);
            if((i==0 && dir==-1) || (i==n && dir==1)) 
            {
                flag=true;
                break;
            }
            long long Now=((dir>=0) ? i+1 : i);
            if(Now==n+1) Now=n;
            ans=max(ans,CheckPoint(-a[Now],SumD,SumU,NumD,NumU,Minn,Maxn));
        }
        if(flag) printf("INF\n");
        else printf("%lld\n",ans);
    }
}