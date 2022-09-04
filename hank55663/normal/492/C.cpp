#include<stdio.h>
#include<algorithm>
using namespace std; 
struct essay{
    long long int point;
    long long int need;
};
essay a[100000];
bool operator<(const essay &a,const essay &b)
{
    return a.need<b.need;
}
main()
{

    
    long long int n,r,avg,i,sum=0,ans=0;
    scanf("%I64d %I64d %I64d",&n,&r,&avg);
    for(i=0;i<n;sum+=a[i].point,i++)
    scanf("%I64d %I64d",&a[i].point,&a[i].need);
    avg*=n;
    sort(a,a+n);
    for(i=0;sum<avg;i++)
    {
        if(r-a[i].point>avg-sum)
        {
            ans+=(avg-sum)*a[i].need;
            break;
                }
        ans+=(r-a[i].point)*a[i].need;
        sum+=r-a[i].point;
    }
    printf("%I64d",ans);
    return 0;
}