#include<stdio.h>
#include<math.h>
#include<map>
#include<algorithm>
#include<string.h>
using namespace std;
main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[1000];
    int i,Min=1e9,Max=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        Min=min(a[i],Min);
        Max=max(a[i],Max);
    }
    if(Max-Min>k)
        printf("NO\n");
    else
    {
    printf("YES\n");
    int l=1;
    for(int i=0;i<n;i++)
    {
        l=1;
        for(int j=0;j<a[i];j++)
        {
            if(j<Min)
                printf("1 ");
            else
            {
            printf("%d ",l);
            l++;
            }
        }
        printf("\n");
    }
    }
    return 0;
}