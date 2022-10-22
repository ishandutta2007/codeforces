/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
const int MAXN = 155;
const int inf = 2e9;
int n,m,u[MAXN],v[MAXN],d[MAXN],id[MAXN],dep[MAXN];
struct Matrix{
	bitset<MAXN> a[MAXN];
	Matrix(int type=0){rep(i,1,n) rep(j,1,n) a[i][j]=(type && i==j);}
	inl friend Matrix operator * (Matrix x,Matrix y) {
		Matrix ans;
		rep(i,1,n) rep(j,1,n) if(x.a[i][j]) ans.a[i]|=y.a[j];
		return ans;
	}
	inl void print() {
		rep(i,1,n) rep(j,1,n) cout<<a[i][j]<<" \n"[j==n];
	}
}nw,edge;
inl bool cmp(int x,int y){
	return d[x]<d[y];
}
inl Matrix Pow(Matrix a,int b){
	Matrix ans(1);
	for(;b;b>>=1,a=a*a) if(b&1) ans=ans*a;
	return ans;
}
inl ll bfs(){
	queue<int> Q;
	rep(i,1,n) if(nw.a[1][i]) dep[i]=0,Q.push(i); else dep[i]=inf;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		rep(i,1,n) if(edge.a[u][i] && dep[i]==inf){
			dep[i]=dep[u]+1;
			Q.push(i);
		}
	}
	return dep[n];
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,m) read(u[i]),read(v[i]),read(d[i]),id[i]=i;
	sort(id+1,id+m+1,cmp);
	nw.a[1][1]=1;ll ans=inf;
	rep(i,1,m) {
		int len=d[id[i]]-d[id[i-1]];
		nw=nw*Pow(edge,len);
		edge.a[u[id[i]]][v[id[i]]]=1;
		ylmin(ans,d[id[i]]+bfs());
	}
	if(ans==inf) puts("Impossible");
	else printf("%d\n",ans);
	return 0;
}