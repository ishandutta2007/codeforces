#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getch(){
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define Getc getch
inline ll read(){
	ll s=0,f=1;char ch=Getc();
	while(ch<'0'||ch>'9')f=(ch=='-'?-1:1),ch=Getc();
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=Getc();
	return s*f;
}
const int MaxN=100000+5;
struct Edge{
	int to,nxt,flow;
	double cost;
}e[MaxN*3];
int h[MaxN],cnt=1;
void Add_Edge(int x,int y,int f,double c){
	e[++cnt]=(Edge){y,h[x],f, c};h[x]=cnt;
	e[++cnt]=(Edge){x,h[y],0,-c};h[y]=cnt;
}
double dis[MaxN],minc;
int pre[MaxN],maxf,vis[MaxN];
queue<int>q;
const double eps=1e-9;
int sign(double x){
	if(fabs(x)<eps)return 0;
	if(x>0)return 1;
	return -1;
}
bool Spfa(int s,int t){
	fill(dis,dis+MaxN,1e10);dis[s]=0;
	memset(vis,0,sizeof(vis));vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();vis[x]=0;
		for(int i=h[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(!e[i].flow)continue;
			if(sign(dis[y]-(dis[x]+e[i].cost))<=0)continue;
			dis[y]=dis[x]+e[i].cost;pre[y]=i;
			if(!vis[y])vis[y]=1,q.push(y);
		}
	}return dis[t]<1e10;
}
void Augment(int s,int t){
	int k=1e9;
	for(int p=pre[t];p;p=pre[e[p^1].to])
		k=min(k,e[p].flow);
	for(int p=pre[t];p;p=pre[e[p^1].to]){
		e[p].flow-=k;
		e[p^1].flow+=k;
	}maxf+=k;minc+=k*dis[t];
}
void Mcmf(int s,int t){
	maxf=minc=0;
	while(Spfa(s,t))Augment(s,t);
}
#define pii pair<ll,ll>
#define sqr(x) ((x)*(x))
int n;
pii p[400+5];
double Dis(int x,int y){
	return sqrt(sqr(p[x].first-p[y].first)+sqr(p[x].second-p[y].second));
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int x,y;
		x=read(),y=read();
		p[i]=pii(x,y);
	}
	int S=0,T=n*3+1;
	for(int i=1;i<=n;i++){
		Add_Edge(i,i+n,1,0);
		Add_Edge(S,i+2*n,2,0);
		Add_Edge(i+n,T,1,0);
		for(int j=1;j<=n;j++)
		if(p[j].second<p[i].second)Add_Edge(i+2*n,j,1,Dis(i,j));
	}
	Mcmf(S,T);
	if(maxf!=n-1)puts("-1");
	else printf("%.8lf\n",minc);
	return 0;
}