#include<stdio.h>
#include<algorithm>
using namespace std;
struct point{
int l;
int a;};
point day[1000];
bool operator <(const point &c,const point& b)
{
    return c.a<b.a;
}
main(){
    int a,n;
    scanf("%d %d",&n,&a);
    for(int i=0;i<n;i++)
    {
        day[i].l=i+1;
        scanf("%d",&day[i].a);
    }
    sort(day,day+n);
    int i;
    for(i=0;i<n;i++)
    {
        a-=day[i].a;
        if(a<0)
            break;
        if(a==0)
        {
            i++;
            break;}
    }
    printf("%d\n",i);
    int ans[1000];
    for(int j=0;j<i;j++)
        ans[j]=day[j].l;
        sort(ans,ans+i);
        for(int j=0;j<i;j++)
            printf("%d ",ans[j]);
    printf("\n");
    return 0;
}