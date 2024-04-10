#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std; 
struct s{
    int x,y;
    int redu;
};
s b[50000];
main()
{
    int n,location,i,j,k=0,l,ans=0,ans2=0,ans3=0;
    scanf("%d %d",&n,&location);
    char a[100001];
    scanf("%s",a);
    i=n/2;
    j=i+1+n%2;
    i--;
    j--;
    location--;
    for(;i>=0&&j<n;i--,j++)
    if(a[i]!=a[j])
    {
        if(location+2>n/2)
        {
            if(ans2==0&&location>j)
        ans2=location-j;
        else
        ans3=j-location;
        }
        else
        {
            if(ans2==0&&location<i)
            ans2=i-location;
            else
            ans3=location-i;
        }
        ans+=min(26-abs(a[i]-a[j]),abs(a[i]-a[j]));
    }
    if(ans3<0)
    ans3=0;
    printf("%d",ans+min(ans2*2+ans3,ans2+ans3*2));
    return 0;
}