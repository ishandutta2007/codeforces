#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int n,k,people[2000],ans=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    scanf("%d",&people[i]);
    sort(people,people+n);
    for(int i=n-1;i>=0;i-=k)
    {
        ans+=(people[i]-1)*2;
        
    }
    printf("%d\n",ans); 
    return 0;
}