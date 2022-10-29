#include<cstdio>
#include<algorithm>
#include<cstring>
#define M 10000005
#define N 55
using namespace std;
const int Mo=(int)1e9+7;
const int inf=(int)1e9;
int i,j,m,n,p,k,fiv,hud,x,lx,ly,k1;
int Qx[10005],Qy[10005],Qz[10005];
int dis[55][55][2],fox[55][55][2],vis[55][55][2],ans[55][55][2],C[55][55];
struct Node{int edx,edy,edz,before;}s[M];
void add(int x,int y,int z,int x1,int y1,int z1)
{
	  s[++k1].edx=x1; s[k1].edy=y1; s[k1].edz=z1; s[k1].before=fox[x][y][z]; fox[x][y][z]=k1; 
}
int cal(int sx,int sy,int ex,int ey)
{
	  return 1ll*C[sx][sx-ex]*C[sy][sy-ey]%Mo;
}
void bfs()
{
	   int l,r;
	 Qx[r=1]=fiv; Qy[1]=hud; Qz[1]=0;
	 vis[fiv][hud][0]=1;
	 for (l=1;l<=r;++l)
	 {
	 	  int ax=Qx[l],ay=Qy[l],az=Qz[l];
	 	  for (i=fox[ax][ay][az];i;i=s[i].before)
	 	   if (!vis[s[i].edx][s[i].edy][s[i].edz])
	 	   {
	 	   	  vis[s[i].edx][s[i].edy][s[i].edz]=1;
	 	   	  dis[s[i].edx][s[i].edy][s[i].edz]=dis[ax][ay][az]+1;
	 	   	  Qx[++r]=s[i].edx; Qy[r]=s[i].edy; Qz[r]=s[i].edz;
	 	   }
	 }
	 ans[fiv][hud][0]=1;
	 for (i=1;i<=r;++i)
	 {
	 	    int ax=Qx[i],ay=Qy[i],az=Qz[i];
	 	    for (j=fox[ax][ay][az];j;j=s[j].before)
	 	      if (dis[s[j].edx][s[j].edy][s[j].edz]==dis[ax][ay][az]+1)
	 	         (ans[s[j].edx][s[j].edy][s[j].edz]+=1ll*ans[ax][ay][az]*cal(ax,ay,fiv-s[j].edx,hud-s[j].edy)%Mo)%=Mo;
	 }
}
int main()
{
	  scanf("%d%d",&n,&k);
	  for (i=0;i<N;++i)
	  {
	  	 C[i][0]=C[i][i]=1;
	  	 for (j=1;j<i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mo;
      }
	  for (;n--;)
	  {
	  	  scanf("%d",&x);
	  	  if (x==50) fiv++; else hud++;
	  }
	  memset(dis,60,sizeof(dis));
	  dis[fiv][hud][0]=0;
	  for (i=0;i<=fiv;++i)
	    for (j=0;j<=hud;++j)
	        for (lx=0;lx<=i;++lx) 
	           for (ly=0;ly<=j;++ly)
	             if ((lx||ly)&&(50*lx+100*ly<=k))
	               add(i,j,0,fiv-i+lx,hud-j+ly,1),
	               add(i,j,1,fiv-i+lx,hud-j+ly,0);
	  bfs();
	  if (dis[fiv][hud][1]>inf) printf("-1\n0\n");
	  else printf("%d\n",dis[fiv][hud][1]),printf("%d\n",ans[fiv][hud][1]);
}