#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int x[4]={0,0,-1,1};
const int y[4]={1,-1,0,0};
int i,j,m,n,p,k,vis[55][55],qx[5555],qy[5555];
char c[55][55];
bool check(int x,int y)
{ 
  if (x<0||y<0||x>=n||y>=m||vis[x][y]||c[x][y]=='.') return 0;
  return 1;
}
void bfs(int xx,int yy)
{
	 	int r=1; qx[r]=xx,qy[r]=yy; vis[xx][yy]=1;
	 	int i,l;
	 	for (l=1;l<=r;++l)
	  {
	  	   int ax=qx[l],ay=qy[l];
	  	   for (i=0;i<4;++i)
	  	    if (check(ax+x[i],ay+y[i]))
		{
		 qx[++r]=ax+x[i]; qy[r]=ay+y[i];
		 vis[ax+x[i]][ay+y[i]]=1;
	    }
     }
}
int main()
{
   scanf("%d%d",&n,&m); 
   for (i=0;i<n;++i) scanf("%s",c[i]);
   for (i=0;i<n;++i) for (j=0;j<m;++j)
     if (c[i][j]=='#') ++k;
    if (k<3) { printf("-1\n"); return 0; }
    for (i=0;i<n;++i)
      for (j=0;j<m;++j)
        if (c[i][j]=='#')
        {
        	 c[i][j]='.';
        	 memset(vis,0,sizeof(vis)); int sum=0;
        	 for (p=0;p<n;++p)
        	   for (k=0;k<m;++k)
        	       if (c[p][k]=='#'&&!vis[p][k]) bfs(p,k),++sum;
        	 if (sum>1) { printf("1\n"); return 0; }
        	 c[i][j]='#';
        }
        printf("2\n");
}