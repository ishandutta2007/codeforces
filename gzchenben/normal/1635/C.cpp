#include<cstdio>
#include<vector>
using namespace std;
int t,n,a[200005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        if(a[n-1]>a[n]) 
        {
            printf("-1\n");
            continue;
        }
        int Minx=n-1,Miny=n,Maxn=(a[n-1] > a[n] ? n-1 : n);
        for(int i=n-2;i>=1;i--)
        {
            if(a[Minx]-a[Miny]<=a[i+1])
            {
                printf("%d\n",i);
                for(int tmp=1;tmp<=i;tmp++)
                {
                    printf("%d %d %d\n",tmp,Minx,Miny);
                }
                break;
            }
            if(a[i]>a[i+1]) 
            {
                printf("-1\n");
                break;
            }
            if(a[i]-a[Maxn] < a[Minx]-a[Miny])
            {
                Minx=i;
                Miny=Maxn;
            }
            if(a[i]>a[Maxn]) Maxn=i;
            if(i==1) printf("0\n");
        }
    }
}