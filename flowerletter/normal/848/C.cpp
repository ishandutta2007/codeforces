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
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 1e5+10;
int n,m,cnt,tot,a[MAXN];
ll ans[MAXN],bit[MAXN];
set<int> S[MAXN];
struct Ask{
	int opt,x,y,id;
}q[MAXN*7];
template<class T>inl void ylmin(T &a,T b){a=a<b?a:b;}
template<class T>inl void ylmax(T &a,T b){a=a>b?a:b;}
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
inl int pre(int x){
	auto s=S[a[x]].find(x);
	return s==S[a[x]].begin()?0:*(--s);
}
inl int sub(int x){
	auto s=S[a[x]].find(x);
	return ++s==S[a[x]].end()?0:*s;
}
inl bool cmp(Ask a,Ask b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
inl void add(int x,int k){
    for(;x<=n;x+=lb(x)) bit[x]+=k;
}
inl ll query(int x,ll ans=0){
    for(;x;x-=lb(x)) ans+=bit[x];
    return ans;
}
inl void Solve(int l,int r){
	if(l>=r) return ;
	int mid=l+r>>1,i=l,j=mid+1;
	Solve(l,mid),Solve(mid+1,r);
    for(;j<=r;j++)if(!q[j].opt){
		for(;i<=mid && q[i].x<=q[j].x;i++) if(q[i].opt) add(q[i].y,(q[i].x-q[i].y)*q[i].opt);
		ans[q[j].id]+=query(n)-query(q[j].y-1);
	}
	rep(k,l,i-1) if(q[k].opt) add(q[k].y,-(q[k].x-q[k].y)*q[k].opt);
	sort(q+l,q+r+1,cmp);
}
int main(){
	read(n),read(m);
	rep(i,1,n) {
		read(a[i]),S[a[i]].insert(i);
		if(size(S[a[i]])>1) q[++cnt]=(Ask){1,i,*(--S[a[i]].rbegin()),0};
	}
	rep(i,1,m){
		int opt,l,r;
		read(opt),read(l),read(r);
		if(opt==1){
			int i=l;
			if(pre(i)) q[++cnt]=(Ask){-1,i,pre(i),0};
			if(sub(i)) q[++cnt]=(Ask){-1,sub(i),i,0};
			if(pre(i) && sub(i)) q[++cnt]=(Ask){1,sub(i),pre(i),0};
			S[a[i]].erase(i);a[i]=r;S[a[i]].insert(i);
			if(pre(i)) q[++cnt]=(Ask){1,i,pre(i),0};
			if(sub(i)) q[++cnt]=(Ask){1,sub(i),i,0};
			if(pre(i) && sub(i)) q[++cnt]=(Ask){-1,sub(i),pre(i),0};
		}else {
			q[++cnt]=(Ask){0,r,l,++tot};
		}
	}
	Solve(1,cnt);
	rep(i,1,tot) printf("%lld\n",ans[i]);
	return 0;
}