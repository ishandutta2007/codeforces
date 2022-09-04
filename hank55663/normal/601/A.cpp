#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int road[500][500];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    road[i][j]=1e9;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        road[a][b]=1;
        road[b][a]=1;
    }
    int road2[500][500];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(road[i][j]==1)
        road2[i][j]=1e9;
        else
        road2[i][j]=1;
    }
    for(int j=1;j<=n;j++)
    for(int i=1;i<=n;i++)
    for(int k=1;k<=n;k++)
    {
        road[i][k]=min(road[i][k],road[i][j]+road[j][k]);
        road2[i][k]=min(road2[i][k],road2[i][j]+road2[j][k]);
    }
    if(road[1][n]==1e9||road2[1][n]==1e9)
    printf("-1");
    else
    printf("%d",max(road[1][n],road2[1][n]));
    return 0;
}