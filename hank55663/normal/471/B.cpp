#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct thing{
    int x;
    int dif;
};
thing event[20000];
bool operator<(const thing & a, const thing & b)
{
    return a.dif<b.dif;
}
main()
{
    int n,i,ans=0,print=0,use=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&event[i].dif);
        event[i].x=i+1;
    }
    sort(event,event+n);
    for(i=0;i<n-1;i++)
    {
        if(event[i].dif==event[i+1].dif)
        ans++;
        if(ans>=2)break;
    }
    if(ans<2)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for(i=0;i<n;i++)
            {
                if(print)
                    printf(" ");
                printf("%d",event[i].x);
                print=1;
            }
            printf("\n");
            print=0;
        for(i=0;i<n;i++)
        {
            if(print)
                printf(" ");
            if(event[i].dif==event[i+1].dif)
               {
                   printf("%d %d",event[i+1].x,event[i].x);
                   i++;
               }
            else
                printf("%d",event[i].x);
            print=1;
        }
        printf("\n");
        print=0;
        for(i=0;i<n;i++)
        {
            if(print)
                printf(" ");
            if(event[i].dif==event[i+1].dif)
               {
                   if(use)
                   {
                       printf("%d %d",event[i+1].x,event[i].x);
                        i++;
                   }
                   else
                printf("%d",event[i].x);
                   use=1;
               }
            else
                printf("%d",event[i].x);
            print=1;
        }
    }
    return 0;
}