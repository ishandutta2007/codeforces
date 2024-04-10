#include <cstdio>
#include <cstdlib>
#include <algorithm>
const int N=1005,M=1005;
typedef std::pair<int,int> vec;
#define x first
#define y second
const vec Dir[4]={vec(-1,0),vec(1,0),vec(0,-1),vec(0,1)};
int n,m,d,lim,tot;
char a[N][M];
vec ans1,ans2,rat[150*2];
int tim,vis1[N][M],vis2[N][M],flag[N][M];
void printans(){
	printf("%d %d %d %d\n",ans1.x,ans1.y,ans2.x,ans2.y);
	exit(0);
}
void bfs(vec s,int f){
	static vec q[150*4];
	static int dis[150*4];
	int head=0,tail=0;
	q[tail]=s;
	dis[tail]=d;
	tail++;
	for(;head<tail;head++){
		vec u=q[head];
		if(a[u.x][u.y]=='X'||(f>0?flag[u.x][u.y]&f:!(flag[u.x][u.y]&-f))) continue;
		flag[u.x][u.y]+=f;
		if(!dis[head]) continue;
		for(int dir=0;dir<4;dir++){
			vec v(u.x+Dir[dir].x,u.y+Dir[dir].y);
			q[tail]=v;
			dis[tail++]=dis[head]-1;
		}
	}
}

void find2(vec s){
	static vec q[150*4];
	static int dis[150*4];
	int head=0,tail=0;
	q[tail]=s;
	dis[tail]=d;
	tail++;
	for(;head<tail;head++){
		vec u=q[head];
		if(a[u.x][u.y]=='X'||vis2[u.x][u.y]==tim) continue;
		vis2[u.x][u.y]=tim;
		
		if(u!=ans1){
			ans2=u;
			bfs(u,2);
			bool ok=true;
			for(int i=0;i<tot;i++) if(!flag[rat[i].x][rat[i].y]){
				ok=false;
				break;
			}
			bfs(u,-2);
			if(ok)
				printans();
		}
		
		if(!dis[head]) continue;
		for(int dir=0;dir<4;dir++){
			q[tail]=vec(u.x+Dir[dir].x,u.y+Dir[dir].y);
			dis[tail++]=dis[head]-1;
		}
	}
}

void find1(vec s){
	static vec q[150*4];
	static int dis[150*4];
	int head=0,tail=0;
	q[tail]=s;
	dis[tail]=d;
	tail++;
	for(;head<tail;head++){
		vec u=q[head];
		if(a[u.x][u.y]=='X'||vis1[u.x][u.y]) continue;
		vis1[u.x][u.y]=1;
		
		ans1=u;
		bfs(u,1);
		bool ok=true;
		for(int i=0;i<tot;i++) if(!flag[rat[i].x][rat[i].y]){
			tim++;
			find2(rat[i]);
			ok=false;
			break;
		}
		bfs(u,-1);
		if(ok){
			for(ans2.x=1;ans2.x<=n;ans2.x++)
				for(ans2.y=1;ans2.y<=m;ans2.y++)
					if(a[ans2.x][ans2.y]!='X'&&ans2!=ans1)
						printans();
		}
		
		if(!dis[head]) continue;
		for(int dir=0;dir<4;dir++){
			q[tail]=vec(u.x+Dir[dir].x,u.y+Dir[dir].y);
			dis[tail++]=dis[head]-1;
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&d);
	lim=2*((d+1)*d*2+1);
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) if(a[i][j]=='R'){
			if(tot==lim) return puts("-1"),0;
			rat[tot++]=vec(i,j);
		}
	find1(rat[0]);
	puts("-1");
}