#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mr make_pair
#define N 100010
#define INF 1e9
using namespace std;
struct Info{int nu,ne,qu;}a[N*10];
int m,n,num=0,d[N][2],c[N][2],s,t,ns,nt,b[N*2],di[N*2],cur[N*2],li[N*2],ans,a2,a1,ch=0;
ll R,B;
struct Onfo{int x,y,z;}p[N],q[N];
map<int,int> o;
void jb(int x,int y,int z){
	a[++num].nu=y;a[num].ne=b[x];b[x]=num;a[num].qu=z;
	a[++num].nu=x;a[num].ne=b[y];b[y]=num;a[num].qu=0;
}
void jb(int x,int y,int p,int q){if(q-p)jb(x,y,q-p);if(p){a1+=p;jb(x,nt,p);jb(ns,y,p);}}
bool bfs(int s,int t){
	for (int i=1;i<=nt;i++)di[i]=INF;
	int l=1,r=1;li[l]=s;di[s]=0;
	while (l<=r){
		for (int y=b[li[l]];y;y=a[y].ne)
			if (di[a[y].nu]==INF&&a[y].qu){di[a[y].nu]=di[li[l]]+1;li[++r]=a[y].nu;}
		l++;
	}
	return (di[t]!=INF);
}
int dinic(int x,int mu,int sh){
	if (x==mu){if (mu==t) ans+=sh;else a2+=sh;return sh;}
	int s1=0,s2;
	for (int y=cur[x];y;y=a[y].ne){
		cur[x]=y;
		if (di[a[y].nu]==di[x]+1&&a[y].qu){
			s2=dinic(a[y].nu,mu,min(a[y].qu,sh-s1));
			s1+=s2;a[y].qu-=s2;a[y^1].qu+=s2;
			if (s1==sh) return s1;
		}
	}
	return s1;
}
void get(int s,int t){while (bfs(s,t)){for (int i=1;i<=nt;i++)cur[i]=b[i];dinic(s,t,INF);}}
int main(){
//	freopen("d.in","r",stdin);
	cin>>n>>m;
	cin>>R>>B;
	for (int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
	for (int i=1;i<=m;i++)cin>>q[i].x>>q[i].y>>q[i].z;
	if (R>B){
		swap(R,B);ch=1;
		for (int i=1;i<=n;i++)swap(p[i].x,p[i].y);
		for (int i=1;i<=m;i++)q[i].x=3-q[i].x;
	}
	o.clear();num=0;
	for (int i=1;i<=n;i++){if (o[p[i].x]==0)o[p[i].x]=++num;p[i].x=o[p[i].x];}
	for (int i=1;i<=m;i++)if (q[i].x==1)q[i].y=o[q[i].y];
	o.clear();num=0;
	for (int i=1;i<=n;i++){if (o[p[i].y]==0)o[p[i].y]=++num;p[i].y=o[p[i].y];}
	for (int i=1;i<=m;i++)if (q[i].x==2)q[i].y=o[q[i].y];
	for (int i=1;i<=n;i++){d[p[i].x][0]++;d[p[i].y][1]++;}
	for (int i=1;i<=n;i++)c[i][0]=d[i][0],c[i][1]=d[i][1];
	for (int i=1;i<=m;i++)d[q[i].y][q[i].x-1]=min(d[q[i].y][q[i].x-1],q[i].z);
	s=n+n+1,t=n+n+2;ns=n+n+3,nt=n+n+4;num=1;
	for (int i=1;i<=n;i++)jb(p[i].x,p[i].y+n,0,1);
	for (int i=1;i<=n;i++){
		int ma,mi;
		if (c[i][0]){ma=(c[i][0]+d[i][0])/2,mi=c[i][0]-ma;jb(s,i,mi,ma);}
		if (mi>ma){puts("-1");return 0;}
		if (c[i][1]){ma=(c[i][1]+d[i][1])/2,mi=c[i][1]-ma;jb(i+n,t,mi,ma);}
		if (mi>ma){puts("-1");return 0;}
	}
	jb(t,s,INF);
	get(ns,nt);
	ans=a[num].qu;
	a[num].qu=a[num-1].qu=0;
	if (a1!=a2) {puts("-1");return 0;}
	get(s,t);
	cout<<ans*R+(n-ans)*B<<endl;
	for (int i=1;i<=n;i++)if (a[i*2].qu^ch)putchar('b');else putchar('r');
	return 0;
}