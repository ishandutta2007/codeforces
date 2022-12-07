#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,x,a[105];
int check(int u)
{
    for(int i=u+1;i<=n;i++)
    {
        if(a[i]!=a[u]) return i;
    }
    return 0;
}
void modify(int u,int v)
{
    if(v==0) return;
    int tx=a[v];
    for(int i=v;i>u;i--)
    {
        a[i]=a[i-1];
    } 
    a[u]=tx;
    return;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n-1;i++)
        {
            if(a[i]!=a[n]) 
            {
                swap(a[i],a[n-1]);
                break;
            }
        }
        int sum=0;
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
            if(sum==x)
            {
                int tmp=check(i);
                if(tmp==0) flag=false;
                modify(i,tmp);
                break;
            }
        }
        if(!flag) 
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}