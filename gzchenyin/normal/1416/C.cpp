#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[300005],tmp1[300005],tmp2[300005],top1,top2;
bool b[300005];
long long ans1,ans2,tmpans1,tmpans2;
void work(int l,int r,int k) 
{
    top1=top2=0;
    for(int i=l;i<=r;i++)
    {
        if(a[i]&(1<<k)) 
        {
            tmp2[++top2]=a[i];
            tmpans2+=top1;
        }
        else
        {
            tmp1[++top1]=a[i];
            tmpans1+=top2;
        }
    }
    for(int i=1;i<=top1;i++)
    {
        a[l+i-1]=tmp1[i];
    }
    for(int i=1;i<=top2;i++)
    {
        a[l+top1+i-1]=tmp2[i];
    }
    b[l+top1-1]=true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    b[0]=b[n]=true;
    for(int i=30;i>=0;i--)
    {
        int lst=0;
        tmpans1=tmpans2=0;
        for(int j=1;j<=n;j++)
        {
            if(b[j]) 
            {
                work(lst+1,j,i);
                lst=j;
            }
        }
//        printf("k=%d\n,tmp1=%d\n,tmp2=%d\n",i,tmpans1,tmpans2);
        if(tmpans1>tmpans2) ans2+=(1<<i);
        ans1+=min(tmpans1,tmpans2);
    }
    printf("%lld %lld\n",ans1,ans2);
}