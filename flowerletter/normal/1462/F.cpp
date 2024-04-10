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
const int MAXN = 2e5 + 10;
int T,n,l[MAXN],r[MAXN],id[MAXN],t[MAXN],ans[MAXN];
inl bool cmp1(int x,int y){
	return l[x]<l[y];
}
inl bool cmp2(int x,int y){
	return r[x]<r[y];
}
int main(){
//	freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		read(n);
		rep(i,1,n) read(l[i]),read(r[i]);
		rep(i,1,n) id[i]=i;
		sort(id+1,id+n+1,cmp1);
		rep(i,1,n) t[i]=l[id[i]];
		rep(i,1,n) ans[i]+=n-(upper_bound(t+1,t+n+1,r[i])-t)+1;
		sort(id+1,id+n+1,cmp2);
		rep(i,1,n) t[i]=r[id[i]];
		rep(i,1,n) ans[i]+=lower_bound(t+1,t+n+1,l[i])-t-1;
		int Min=n;
		rep(i,1,n) ylmin(Min,ans[i]),ans[i]=0; 
		printf("%d\n",Min);
	}
	return 0;
}