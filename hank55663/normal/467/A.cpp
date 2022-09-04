#include<cstdio>
#include<cstring>
using namespace std;
main()
{
    int n,a,b,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if(a<b-1)
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}