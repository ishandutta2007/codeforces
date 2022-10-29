#include <cstdio>
#include <cstring>
int main()
{
        int i,n;
        scanf("%d",&n);
        if (n%2==1)
        {
                printf("-1\n");
        }
        else
        {
                for (i=1;i<=n;i++)
                {
                        if (i%2) printf("%d",i+1); else printf("%d",i-1);
                        if (i<n) printf(" "); else printf("\n");
                }
        }
        return 0;
}