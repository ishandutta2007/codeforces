#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int k,n,m,s,i,j,i2,j2,i1,j1,ap[1009][1009],D[1009][1009];
char a[1009][1009];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int cor(int x,int y)
{
    return (x>=1&&x<=n&&y>=1&&y<=m);
}
queue < pair < int  , int > > cc;
pair < int  , int > xx;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d\n",&m);
for(i=1;i<=n;i++)
    gets(a[i]+1);
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(a[i][j]=='S')
        {
            i1=i;
            j1=j;
        }
        if(a[i][j]=='E')
        {
            i2=i;
            j2=j;
        }
        ap[i][j]=-1;
    }
cc.push(make_pair(i2,j2));
ap[i2][j2]=0;
while(!cc.empty())
{
    xx=cc.front();
    cc.pop();
    for(k=0;k<4;k++)
    {
        i=xx.first+dx[k];
        j=xx.second+dy[k];
        if(a[i][j]!='T'&&cor(i,j)&&ap[i][j]==-1&&(i!=i2||j!=j2))
        {
            ap[i][j]=ap[xx.first][xx.second]+1;
            cc.push(make_pair(i,j));
        }
    }
}
cc.push(make_pair(i1,j1));
D[i2][j2]=0;
while(!cc.empty())
{
    xx=cc.front();
    cc.pop();
    for(k=0;k<4;k++)
    {
        i=xx.first+dx[k];
        j=xx.second+dy[k];
        if(a[i][j]!='T'&&cor(i,j)&&D[i][j]==0&&(i!=i1||j!=j1))
        {
            D[i][j]=D[xx.first][xx.second]+1;
            cc.push(make_pair(i,j));
        }
    }
}
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(a[i][j]>='0'&&a[i][j]<='9'&&ap[i][j]<=D[i2][j2]&&ap[i][j]!=-1) s+=a[i][j]-48;
printf("%d\n",s);
return 0;
}