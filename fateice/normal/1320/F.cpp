#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,t,a[200010][6],dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};
bool p[200010];
inline int get(int i,int j,int k)
{
    return (i-1)*m*t+(j-1)*t+k;
}
inline void chk(int i);
inline void orz(int i,int j,int k)
{
    int x,y,z;
    x=(i-1)/(m*t)+1;
    y=(i-1)%(m*t)/t+1;
    z=(i-1)%t+1;
    while(x>0 && x<=n && y>0 && y<=m && z>0 && z<=t && p[get(x,y,z)])
      x+=dx[j],y+=dy[j],z+=dz[j];
    if(!(x>0 && x<=n && y>0 && y<=m && z>0 && z<=t))
      if(k==0)
        return;
      else
        {
         printf("-1\n");
         exit(0);
        }
    a[get(x,y,z)][j]=k;
    chk(get(x,y,z));
}
inline void chk(int i)
{
    int j,k=0;
    for(j=0;j<6;j++)
      if(a[i][j]==0 || a[i][j]>0 && k>0 && a[i][j]!=k)
        break;
      else if(a[i][j]>0)
        k=a[i][j];
    if(j==6)
      return;
    p[i]=1;
    for(j=0;j<6;j++)
      if(a[i][j]>=0)
        orz(i,j,a[i][j]);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n*m*t;i++)
	  for(j=0;j<6;j++)
	    a[i][j]=-1;
	for(i=1;i<=m;i++)
	  for(j=1;j<=t;j++)
	    {
         scanf("%d",&k);
	     a[get(1,i,j)][0]=k;
        }
	for(i=1;i<=m;i++)
	  for(j=1;j<=t;j++)
	    {
         scanf("%d",&k);
	     a[get(n,i,j)][1]=k;
        }
	for(i=1;i<=n;i++)
	  for(j=1;j<=t;j++)
	    {
         scanf("%d",&k);
	     a[get(i,1,j)][2]=k;
        }
	for(i=1;i<=n;i++)
	  for(j=1;j<=t;j++)
	    {
         scanf("%d",&k);
	     a[get(i,m,j)][3]=k;
        }
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    {
         scanf("%d",&k);
	     a[get(i,j,1)][4]=k;
        }
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    {
         scanf("%d",&k);
	     a[get(i,j,t)][5]=k;
        }
    for(i=1;i<=n*m*t;i++)
      if(!p[i])
        chk(i);
    for(i=1;i<=n*m*t;i++)
      {
       for(j=0,k=0;j<6;j++)
         if(a[i][j]>0)
           k=a[i][j];
       if(p[i])
         k=0;
       printf("%d ",k);
      }
	return 0;
}