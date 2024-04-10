#include<cstdio>
using namespace std;
int n,k,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(n==4 && k==3)
        {
            printf("-1\n");
            continue;
        }
        if(k!=n-1)
        {
            for(int i=1;i<n/2;i++)
            {
                if(i==k) 
                {
                    printf("%d %d\n",i,n-1);
                    printf("%d %d\n",n-1-i,0);
                }
                else if(i==(n-k-1))
                {
                    printf("%d %d\n",n-i-1,n-1);
                    printf("%d %d\n",i,0);
                }
                else
                {
                    printf("%d %d\n",i,n-i-1);
                }
            }
            if(k==0) printf("%d %d\n",0,n-1);
            continue;
        }
        for(int i=4;i<n/2;i++)
        {
            printf("%d %d\n",i,n-i-1);
        }
        printf("%d %d\n",n-1,n-2);
        printf("%d %d\n",0,n-4);
        printf("%d %d\n",2,n-3);
        printf("%d %d\n",1,3);
    }
}