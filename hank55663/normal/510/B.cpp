#include<stdio.h>
#include<math.h>
#include<map>
#include<algorithm>
#include<string.h>
char puzzle[70][70];
int ipuzzle[70][70];
int circle=0;
int n,m;
void dfs(int x,int y,int last){
    if(ipuzzle[x][y]){
        if(last!=-1)
            circle=1;
        return;
    }
    ipuzzle[x][y]=1;
    for(int a=0;a<4&&!circle;a++)
    {
        if(a==0&&a!=last&&puzzle[x][y]==puzzle[x+1][y])
            dfs(x+1,y,3);
        if(a==1&&a!=last&&puzzle[x][y]==puzzle[x][y+1])
            dfs(x,y+1,2);
        if(a==2&&a!=last&&puzzle[x][y]==puzzle[x][y-1])
            dfs(x,y-1,1);
        if(a==3&&a!=last&&puzzle[x][y]==puzzle[x-1][y])
            dfs(x-1,y,0);
    }
}
using namespace std;
main(){

    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",puzzle[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                ipuzzle[i][j]=0;
            }
    for(int i=0;i<n&&!circle;i++)
        for(int j=0;j<m&&!circle;j++)
            dfs(i,j,-1);

    if(!circle)
        printf("No\n");
    else
        printf("Yes\n");

    return 0;
}