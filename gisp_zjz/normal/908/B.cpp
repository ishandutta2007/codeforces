#include<bits/stdc++.h>
#define maxn 203490

using namespace std;
char s[105][105],t[100044];
int ans,n,m,k,p,x,y,xx,yy;
int w[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int a[24][4]={
    {0,1,2,3},
    {0,1,3,2},
    {0,2,1,3},
    {0,2,3,1},
    {0,3,1,2},
    {0,3,2,1},
    {1,0,2,3},
    {1,0,3,2},
    {1,2,0,3},
    {1,2,3,0},
    {1,3,0,2},
    {1,3,2,0},
    {2,0,1,3},
    {2,0,3,1},
    {2,1,0,3},
    {2,1,3,0},
    {2,3,0,1},
    {2,3,1,0},
    {3,0,1,2},
    {3,0,2,1},
    {3,1,0,2},
    {3,1,2,0},
    {3,2,0,1},
    {3,2,1,0}
};

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%s",s[i]);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            if (s[i][j]=='S') xx=i,yy=j;
        }
    scanf("%s",t);p=strlen(t);
    int ans=0;
    for (k=0;k<24;k++)
    {
        bool f=false; x=xx;y=yy;
        for (int i=0;i<p;i++)
        {
            x+=w[a[k][t[i]-'0']][0];
            y+=w[a[k][t[i]-'0']][1];
            if (x<0||y<0||x>=n||y>=m||s[x][y]=='#') break;
            if (s[x][y]=='E') {f=true;break;}
        }
        if (f) ans++;
    }
    printf("%d\n",ans);
    return 0;
}