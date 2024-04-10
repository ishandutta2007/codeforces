#include<cstdio>
#include<cstring>
using namespace std;
main()
{
    int n,m,k,army[10000],differ[10000]={0},num,ans=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<=m;i++)
    {
        scanf("%d",&army[i]);
    }
    for(int j=0;j<=n;j++)
    {
        num=army[m]%2;
        for(int i=0;i<m;i++)
        {
            if(num!=army[i]%2)
            differ[i]++;
            army[i]/=2;
        }
        army[m]/=2;
    }
    for(int i=0;i<m;i++)
    if(differ[i]<=k)
    ans++;
    printf("%d",ans);
    return 0;
}