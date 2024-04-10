#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
const int N=2e4,M=2e6;
const ll inf=1e16;
int dx[5]={1,0,-1,0,1},dy[5]={0,1,0,-1,0};
int Dx[4]={-1,1,1,-1},Dy[4]={-1,-1,1,1};
int hea[N],cur[N],nxt[M],to[M],d[N],q[N],S,T,tot=1;
ll w[M];
void ins(int a,int b,ll c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
void add(int a,int b,ll c) {
	ins(a,b,c);
	ins(b,a,0);
}
int bfs() {
	memset(d,0,sizeof(d));
	int h=1,e=1;
	d[q[1]=S]=1;
	while(h<=e) {
		int x=q[h++];
		for(int i=hea[x];i;i=nxt[i])
			if(w[i]&&!d[to[i]])
				d[q[++e]=to[i]]=d[x]+1;
	}
	return d[T];
}
ll dfs(int x,ll f) {
	if(x==T)return f;
	ll sum=0;
	for(int &i=cur[x];i&&f;i=nxt[i])
		if(w[i]&&d[x]+1==d[to[i]]) {
			ll t=dfs(to[i],min(f,w[i]));
			w[i]-=t,w[i^1]+=t;
			sum+=t,f-=t;
		}
	return sum;
}
map<int,map<int,int> >in;
int x[N],y[N],W[N];
signed main() {
	int n;
	ll ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld%lld",x+i,y+i,W+i);
		ans+=W[i];
		if(in[x[i]][y[i]])return -1;
		in[x[i]][y[i]]=i;
	}
	S=n<<1|1;
	T=S+1;
	for(int i=1;i<=n;i++) {
		add(i,i+n,W[i]);
		if((x[i]&1)&&(y[i]&1))add(i+n,T,inf);
		if((x[i]&1)&&!(y[i]&1))add(S,i,inf);
		if((x[i]&1)||(y[i]&1))continue;
		int V[4]={i,0,0,0};
		for(int j=0;j<4;j++) {
			int x1=x[i]+dx[j],y1=y[i]+dy[j];
			int x2=x[i]+dx[j+1],y2=y[i]+dy[j+1];
			if(!in[x1][y1]||!in[x2][y2])continue;
			V[1]=in[x1][y1],V[2]=in[x2][y2];
			if(x1&1)swap(V[1],V[2]);
			for(int k=0;k<4;k++) {
				int x3=x[i]+Dx[k],y3=y[i]+Dy[k];
				if(y1!=y3&&y2!=y3)continue;
				if(!in[x3][y3])continue;
				V[3]=in[x3][y3];
				add(V[2]+n,V[0],inf);
				add(V[0]+n,V[1],inf);
				add(V[1]+n,V[3],inf);
			}
		}
	}
	while(bfs()) {
		memcpy(cur,hea,sizeof(cur));
		ans-=dfs(S,inf*100);
	}
	printf("%lld\n",ans);
}