#include<stdio.h>
#include<algorithm>
using namespace std;
struct point{
    int d;
    int team;
};
bool operator<(const point &a,const point &b)
{
    return a.d<b.d;
}
point x[2000001];
main()
{
    int n,m,i,ans[3];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        x[i].team=0;
       scanf("%d",&x[i].d);
    }
    scanf("%d",&m);
    for(;i<n+m;i++)
    {
        x[i].team=1;
        scanf("%d",&x[i].d);
    }
    ans[0]=(n-m)*3;
    ans[1]=n*3;
    ans[2]=m*3;
    sort(x,x+(n+m));
    x[i].d=x[i-1].d+1;
    int score[2]={ans[1],ans[2]};
    for(i=0;i<n+m;i++)
    {
        score[x[i].team]--;
        if(x[i+1].d!=x[i].d&&score[0]-score[1]>ans[0])
        {
            ans[0]=score[0]-score[1];
            ans[1]=score[0];
            ans[2]=score[1];
            }
    }
    printf("%d:%d\n",ans[1],ans[2]);
    return 0;
}