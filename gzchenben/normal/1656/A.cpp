#include<cstdio>
using namespace std;
int n,t,a[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int Minn=0,Maxn=n+1;
        a[0]=1e9+1;
        a[n+1]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>a[Maxn]) Maxn=i;
            if(a[i]<a[Minn]) Minn=i;
        }
        printf("%d %d\n",Minn,Maxn);
    }
}