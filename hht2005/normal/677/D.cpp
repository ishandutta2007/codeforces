#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> pii;
const int N=310,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int a[N][N],f[N][N],dis[N][N];
vector<pii>S[N*N];
int qx[N*N],qy[N*N];
struct node {
	int x,y,w;
	node(){}
	node(int X,int Y,int W) {
		x=X,y=Y,w=W;
	}
	int operator <(const node &a)const {
		return w<a.w;
	}
}q[N*N];
signed main() {
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			scanf("%d",a[i]+j);
			S[a[i][j]].push_back(make_pair(i,j));
		}
	memset(f,0x3f,sizeof(f));
	for(pii i:S[1])
		f[i.fi][i.se]=i.fi+i.se-2;
	for(int i=2;i<=p;i++) {
		if(S[i].size()*S[i-1].size()<=n*m) {
			for(pii j:S[i])
				for(pii k:S[i-1])
					f[j.fi][j.se]=min(f[j.fi][j.se],f[k.fi][k.se]+abs(j.fi-k.fi)+abs(j.se-k.se));
		} else {
			memset(dis,-1,sizeof(dis));
			int cnt=0,h=1,e=0;
			for(pii j:S[i-1])
				q[++cnt]=node(j.fi,j.se,f[j.fi][j.se]);
			sort(q+1,q+cnt+1);
			qx[++e]=q[1].x,qy[e]=q[1].y;
			dis[q[1].x][q[1].y]=q[1].w;
			int top=1;
			while(h<=e) {
				int x=qx[h],y=qy[h++],w=dis[x][y];
				while(top<cnt&&q[top+1].w==w) {
					top++;
					if(~dis[q[top].x][q[top].y])continue;
					qx[++e]=q[top].x,qy[e]=q[top].y;
					dis[qx[e]][qy[e]]=q[top].w;
				}
				for(int i=0;i<4;i++) {
					int xx=x+dx[i],yy=y+dy[i];
					if(xx<1||yy<1||xx>n||y>m)continue;
					if(dis[xx][yy]==-1) {
						dis[xx][yy]=w+1;
						qx[++e]=xx,qy[e]=yy;
					}
				}
			}
			for(pii j:S[i])
				f[j.fi][j.se]=dis[j.fi][j.se];
		}
	}
	int ans=1e9;
	for(pii i:S[p])
		ans=min(ans,f[i.fi][i.se]);
	printf("%d\n",ans);
	return 0;
}