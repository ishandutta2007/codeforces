#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[505],pos[505];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(pos[i]!=i) 
            {
                reverse(a+i,a+pos[i]+1);
                break;
            }
        }
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        printf("\n");
    }
}