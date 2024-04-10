#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const int maxn=2005;
int vis[maxn][maxn];//0 :cover
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
int n;
struct lx{LL x,y1,y2;}xp[maxn];int tx;
struct ly{LL y,x1,x2;}yp[maxn];int ty;
LL x,y;
LL llx[maxn],px[maxn],tmpx[maxn];int sx;
LL lly[maxn],py[maxn],tmpy[maxn];int sy;
inline int gx(LL x){
	return lower_bound(px+1,px+1+sx,x)-px;
}
inline int gy(LL x){
	return lower_bound(py+1,py+1+sy,x)-py;
}
void dfs(int x,int y){
	if(x<0||x>sx+1||y<0||y>sy+1)return;
	if(vis[x][y])return;
	vis[x][y]=2;
	rep(k,1,4)dfs(x+dx[k],y+dy[k]);
}
inline void go(int x1,int y1,int x2,int y2){
	while((x1^x2)||(y1^y2)){
		vis[x1][y1]=1;
		if(x1<x2)x1++;
		if(y1<y2)y1++;
	}
	vis[x1][y1]=1;
}
int main(){
	x=5000000001;y=5000000001;
	scanf("%d",&n);
	tmpx[n+1]=x;tmpy[n+1]=y;
	rep(i,1,n){
		char s[3];scanf("%s",s+1);int d;scanf("%d",&d);
		if(s[1]=='L'){xp[++tx]=(lx){x,y-d,y};y-=d;}
		if(s[1]=='R'){xp[++tx]=(lx){x,y,y+d};y+=d;}
		if(s[1]=='U'){yp[++ty]=(ly){y,x-d,x};x-=d;}
		if(s[1]=='D'){yp[++ty]=(ly){y,x,x+d};x+=d;}
		tmpx[i]=x;tmpy[i]=y;
		//printf("%I64d\n",y);
	}
	sort(tmpx+1,tmpx+2+n);
	sx=0;int m=unique(tmpx+1,tmpx+2+n)-tmpx-1;
	//printf("%d\n",m);
	rep(i,1,m)if(!sx||tmpx[i]>px[sx]){
		px[++sx]=tmpx[i];llx[sx]=1;
		if(i<m&&tmpx[i]+1<tmpx[i+1]){
			px[++sx]=tmpx[i]+1;
			llx[sx]=tmpx[i+1]-tmpx[i]-1;
		}
	}
	//rep(i,1,sx)printf("%I64d %I64d\n",px[i],llx[i]);
	sort(tmpy+1,tmpy+2+n);
	sy=0;
	m=unique(tmpy+1,tmpy+2+n)-tmpy-1;
	//printf("%d\n",m);
	rep(i,1,m)if(!sy||tmpy[i]>py[sy]){
		py[++sy]=tmpy[i];lly[sy]=1;
		if(i<m&&tmpy[i]+1<tmpy[i+1]){
			py[++sy]=tmpy[i]+1;
			lly[sy]=tmpy[i+1]-tmpy[i]-1;
		}
	}
	//rep(i,1,sx)printf("%I64d %I64d\n",px[i],llx[i]);
	rep(i,1,tx)go(gx(xp[i].x),gy(xp[i].y1),gx(xp[i].x),gy(xp[i].y2));
	rep(i,1,ty)go(gx(yp[i].x1),gy(yp[i].y),gx(yp[i].x2),gy(yp[i].y));
	dfs(0,0);
	LL res=0;
	rep(i,1,sx)rep(j,1,sy)if(vis[i][j]<2)res+=llx[i]*1ll*lly[j];
	printf("%I64d\n",res);
	return 0;
}