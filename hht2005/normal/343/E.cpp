#include<bits/stdc++.h>
using namespace std;
const int N=3010,M=40010,inf=0x3f3f3f3f;
int hea[N],nxt[M],to[M],w[M],W[M],cur[N],d[N],q[N],h,e,S,T,tot;
void ins(int a,int b,int c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
	W[tot]=c;
}
void add(int a,int b,int c) {
	ins(a,b,c);
	ins(b,a,c);
}
int bfs() {
	memset(d,0,sizeof(d));
	d[S]=1;
	q[h=e=1]=S;
	while(h<=e) {
		int x=q[h++];
		for(int i=hea[x]; i; i=nxt[i])
			if(w[i]&&!d[to[i]]) {
				d[to[i]]=d[x]+1;
				q[++e]=to[i];
			}
	}
	return d[T];
}
int dfs(int x,int f) {
	if(x==T)return f;
	int sum=0;
	for(int &i=cur[x]; i&&f; i=nxt[i])
		if(w[i]&&d[x]+1==d[to[i]]) {
			int t=dfs(to[i],min(w[i],f));
			w[i]-=t,w[i^1]+=t;
			f-=t,sum+=t;
		}
	return sum;
}
using pii=pair<int,int>;
using VI=vector<int>;
int f[N];
vector<pii>Sid[N];
void Add(int a,int b,int c) {
	Sid[a].push_back(make_pair(b,c));
	Sid[b].push_back(make_pair(a,c));
}
void dfs(int x) {
	if(f[x])return;
	f[x]=1;
	for(int i=hea[x];i;i=nxt[i])
		if(w[i])dfs(to[i]);
}
void solve(int a,int b,VI pos) {
	for(int i=1;i<=tot;i++)
		w[i]=W[i];
	S=a,T=b;
	int ans=0;
	while(bfs()) {
		memcpy(cur,hea,sizeof(cur));
		ans+=dfs(S,inf);
	}
	Add(S,T,ans);
	memset(f,0,sizeof(f));
	dfs(S);
	VI V1,V2;
	for(int i:pos) {
		if(f[i])V1.push_back(i);
		else V2.push_back(i);
	}
	if(V1.size()>=2)solve(V1[0],V1[1],V1);
	if(V2.size()>=2)solve(V2[0],V2[1],V2);
}
int fl[N][N],a,b,Min,pos[N],m,ans;
void calc(int x,int fa) {
	for(pii t:Sid[x]) {
		int y=t.first,w=t.second;
		if(fl[x][y]||y==fa)continue;
		if(w<Min) {
			Min=w;
			a=x,b=y;
		}
		calc(y,x);
	}
}
void solve(int x,int las) {
	Min=1e9;
	calc(x,0);
	if(Min>1e8) {
		pos[++m]=x;
		return;
	}
	fl[b][a]=fl[a][b]=1;
	ans+=Min;
	int Ta=a,Tb=b;
	solve(Ta,x);
	solve(Tb,x);
}
int main() {
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	memset(hea,0,sizeof(hea));
	tot=1;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	VI p;
	for(int i=1;i<=n;i++)
		p.push_back(i);
	solve(1,2,p);
	solve(1,0);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",pos[i]);
	puts("");
	return 0;
}