#include<bits/stdc++.h>
using namespace std;
int n,m,t,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},w[4],p;
char s[60][60],a[110];
bool u[4];
inline void dfs(int i)
{
	if(i==4)
	  {
	   int j,k,x,y;
	   for(j=0;j<n;j++)
	     for(k=0;k<m;k++)
	       if(s[j][k]=='S')
	         x=j,y=k;
	   for(j=0;j<t;j++)
	     {
		  x+=dx[w[a[j]-'0']];
		  y+=dy[w[a[j]-'0']];
		  if(x<0 || x>=n || y<0 || y>=m || s[x][y]=='#')
		    return;
		  if(s[x][y]=='E')
		    {
			 p++;
			 return;
			}
		 }
	   return;
	  }
	int j;
	for(j=0;j<4;j++)
	  if(!u[j])
	    {
		 u[j]=1;
		 w[i]=j;
		 dfs(i+1);
		 u[j]=0;
		}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	  scanf("%s",&s[i]);
	scanf("%s",&a);
	t=strlen(a);
	dfs(0);
	printf("%d\n",p);
	return 0;
}