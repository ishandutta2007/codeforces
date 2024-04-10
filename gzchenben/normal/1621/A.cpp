#include<cstdio>
using namespace std;
int n,k,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(k>(n+1)/2) 
        {
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j && i%2==1 && i<2*k) printf("R");
                else printf(".");
            }
            printf("\n");
        }
    }
}