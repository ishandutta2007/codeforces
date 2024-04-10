#include<stdio.h>
#include<algorithm>
char a[2010][2010];
int n,m;
int ok=1;
int judge(int i,int j){
    int u=0,d=0,r=0,l=0;
    if(i==0||a[i-1][j]!='.')
        u=1;
    if(i==n-1||a[i+1][j]!='.')
        d=1;
    if(j==0||a[i][j-1]!='.')
        l=1;
    if(j==m-1||a[i][j+1]!='.')
        r=1;
    if(u==1&&d==1&&l==1&&r==1)
        return -1;
    if(u==0&&d==1&&l==1&&r==1)
        return 1;
    if(u==1&&d==0&&l==1&&r==1)
        return 2;
    if(u==1&&d==1&&l==0&&r==1)
        return 3;
    if(u==1&&d==1&&l==1&&r==0)
        return 4;
    return 0;
}
void dfs(int i,int j){
    if(i>=0&&i<n&&j>=0&&j<m)
    if(a[i][j]=='.')
        {
            int jud=judge(i,j);
            if(jud==-1)
                ok=0;
            if(jud==1)
            {
                a[i][j]='v';
                a[i-1][j]='^';
                dfs(i+1,j);
                dfs(i,j+1);
                dfs(i,j-1);
                dfs(i-2,j);
                dfs(i-1,j+1);
                dfs(i-1,j-1);
            }
            if(jud==2)
            {
                a[i][j]='^';
                a[i+1][j]='v';
                dfs(i-1,j);
                dfs(i,j+1);
                dfs(i,j-1);
                dfs(i+2,j);
                dfs(i+1,j+1);
                dfs(i+1,j-1);
            }
            if(jud==3)
            {
                a[i][j]='>';
                a[i][j-1]='<';
                dfs(i-1,j);
                dfs(i+1,j);
                dfs(i,j+1);
                dfs(i,j-2);
                dfs(i+1,j-1);
                dfs(i-1,j-1);
            }
            if(jud==4)
            {
                a[i][j]='<';
                a[i][j+1]='>';
                dfs(i-1,j);
                dfs(i+1,j);
                dfs(i-1,j);
                dfs(i,j+2);
                dfs(i+1,j+1);
                dfs(i-1,j+1);
            }
        }
}
main(){

    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dfs(i,j);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]=='.')
                ok=0;
   if(ok)
        for(int i=0;i<n;i++)
        printf("%s\n",a[i]);
    else
        printf("Not unique");
}