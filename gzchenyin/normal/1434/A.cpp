#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
    int val,color;
}f[600015];
bool cmp(node x,node y)
{
    return x.val<y.val;
}
int a[7],n,b[100005],cnt[100005];
int main()
{
    for(int i=1;i<=6;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        for(int j=1;j<=6;j++)
        {
            f[6*(i-1)+j]=(node){b[i]-a[j],i};
        }
    }
    int now=0,num=0,ans=2e9;
    bool flag=true;
    sort(f+1,f+6*n+1,cmp);
    // for(int i=0;i<=6*n;i++)
    // {
    //     printf("f[%d]=(%d,%d)\n",i,f[i].color,f[i].val);
    // }
    for(int i=0;i<6*n;i++)
    {
        cnt[f[i].color]--;
        if(cnt[f[i].color]==0) num--;
        while(num!=n)
        {
            if(now>=6*n) 
            {
                flag=false;
                break;
            }
            now++;
            cnt[f[now].color]++;
            if(cnt[f[now].color]==1) num++;
        }
        if(!flag) break;
        ans=min(ans,f[now].val-f[i+1].val);
//        printf("i=%d,now=%d\n",i,now);
    }
    printf("%d\n",ans);
}