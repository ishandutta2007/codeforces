#include<cstdio>
using namespace std;
int n,k,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(k==1)
        {
            printf("YES\n");
            for(int i=1;i<=n;i++)
            {
                printf("%d\n",i);
            }
            continue;
        }
        if(n%2==1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i%2==1) 
                {
                    printf("%d ",(i-1)*k+2*j-1);
                }
                else
                {
                    printf("%d ",(i-2)*k+2*j);
                }
            }
            printf("\n");
        }
    }
}
/*
k=1 
k>=2 2|n
1 3 5 7 9 ... 2k-1
2 4 6 8 10 ... 2k
2k+1 2k+3 ...
2k+2 2k+4 ...
*/