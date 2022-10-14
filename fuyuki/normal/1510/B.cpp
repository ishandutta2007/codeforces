#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOF(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(int d=10){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*d+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+1,mod=998244353,INF=0x3f3f3f3f;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
struct edge{int t,n,w,v;}e[N];
int n,k,m,tot=1,S,T,ans=-1,h[N],cnt[N];
int a[N],dis[N],vis[N],pre[N],last[N],ins[N];
V add_edge(int x,int y,int w,int v){
	e[++tot]=(edge){y,h[x],w, v},h[x]=tot;
	e[++tot]=(edge){x,h[y],0,-v},h[y]=tot;
}
V input(){
	k=getint(),n=getint(),m=(1<<k)-1;
	FOR(i,1,n)a[i]=getint(2);
}
V init(){
	sort(a+1,a+1+n),n=unique(a+1,a+1+n)-a-1,S=n+n+1,T=S+1;
	FOR(i,0,m)cnt[i]=cnt[i>>1]+(i&1);
	FOR(i,1,n)add_edge(S,i+n,1,cnt[a[i]]+1),add_edge(S,i,1,0),add_edge(i+n,T,1,0);
	FOR(i,1,n)FOR(j,i+1,n)if((a[i]&a[j])==a[i])
		add_edge(i,j+n,1,cnt[a[j]]-cnt[a[i]]);
}
I spfa(){
	queue<int>q;
	FOR(i,1,T)dis[i]=INF,ins[i]=0;
	q.push(S),ins[S]=1,dis[S]=0;
	for(int u;!q.empty();ins[u]=0,q.pop())REP(u=q.front())
		if(e[i].w&&dis[u]+e[i].v<dis[v]){
			dis[v]=dis[u]+e[i].v,pre[v]=u,last[v]=i;
			if(!ins[v])q.push(v),ins[v]=0;
		}
	return dis[T]!=INF;
}
V output(int u){
	static int flag,now;
	if(flag)cout<<"R ";
	now=0,flag=1;
	while(u){
		FOR(i,0,k-1)if((now^a[u])>>i&1)now|=1<<i,cout<<k-i-1<<' ';
		REP(u)if(v>n&&v!=S&&e[i].w==0){
			u=v-n;goto end;
		}
		break;
		end:;
	}
}
V work(){
	for(ans=-1;spfa();ans+=dis[T])
		for(int u=T;u^S;u=pre[u])
			e[last[u]].w--,e[last[u]^1].w++;
	cout<<ans<<'\n';
	REP(S)if(v>n&&e[i].w==0)output(v-n);
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
		input();
		init();
		work();
	return 0;
}