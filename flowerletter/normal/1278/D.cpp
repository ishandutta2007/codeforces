/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 1e6+10;
int n,tot,rev[MAXN],fa[MAXN];
pii a[MAXN];
set<int> S;
template<class T>inl void ylmin(T &a,T b){a=min(a,b);}
template<class T>inl void ylmax(T &a,T b){a=max(a,b);}
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
inl int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
inl void Merge(int u,int v){
	int x=find(u),y=find(v);
	if(x==y) puts("NO"),exit(0);
	else fa[x]=y;
}
int main(){
	//freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(a[i].fir),read(a[i].sec);
	rep(i,1,n) fa[i]=i;
	sort(a+1,a+n+1);
	rep(i,1,n) rev[a[i].sec]=i;
	rep(i,1,n){ 
		for(auto x=S.begin();x!=S.end();){
			if((*x)<a[i].fir) x=S.erase(x);
			else if((*x)<a[i].sec) Merge(rev[(*x)],i),tot++,x++;
			else break;
			if(tot>=n) puts("NO"),exit(0);
		}
		S.insert(a[i].sec);
	}
	puts(tot==n-1?"YES":"NO");
	return 0;
}