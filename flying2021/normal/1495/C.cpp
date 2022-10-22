#include<iostream>
#include<cstdio>
#include<cstring>
#define N 510
using namespace std;
char s[N][N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=m;i++) s[1][i]='X';
        for(int i=4;i<=n;i+=3)
        {
            for(int j=1;j<=m;j++) s[i][j]='X';
            int p=1;
            for(int j=1;j<=m;j++)
            if(s[i-1][j]=='X' || s[i-2][j]=='X'){p=j;break;}
            s[i-1][p]=s[i-2][p]='X';
        }
        if(n%3==0)
        {
            for(int j=1;j<=m;j++)
            if(s[n][j]=='X' || s[n-1][j]=='X') s[n][j]=s[n-1][j]='X';
        }
        for(int i=1;i<=n;i++) printf("%s\n",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) s[i][j]='\0';
    }
    return 0;
}