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
#define ls rt<<1
#define rs rt<<1|1
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
const int MAXN = 5e5 + 10;
int n,a[MAXN],last;
ll ans;
vector<int> pos[MAXN];
struct Segment{
	pii Max[MAXN<<2];
	int tag[MAXN<<2];
	inl void pushup(int rt){
		if(Max[ls].fir==Max[rs].fir) Max[rt]={Max[ls].fir,Max[ls].sec+Max[rs].sec};
		else Max[rt]=max(Max[ls],Max[rs]);
	} 
	inl void pushdown(int rt){
		tag[ls]+=tag[rt],tag[rs]+=tag[rt];
		Max[ls].fir+=tag[rt],Max[rs].fir+=tag[rt]; 
		tag[rt]=0;
	}
	inl void update(int rt,int l,int r,int L,int R,int k){
		if(l>=L && r<=R) {
			tag[rt]+=k;
			Max[rt].fir+=k;
			return ;
		}
		if(tag[rt]) pushdown(rt);
		int mid=l+r>>1;
		if(R<=mid) update(ls,l,mid,L,R,k);
		else if(L>mid) update(rs,mid+1,r,L,R,k);
		else update(ls,l,mid,L,R,k),update(rs,mid+1,r,L,R,k);
		pushup(rt); 
	}
	inl pii query(int rt,int l,int r,int L,int R){
		if(l>=L && r<=R) return Max[rt];
		if(tag[rt]) pushdown(rt);
		int mid=l+r>>1;
		if(R<=mid) return query(ls,l,mid,L,R);
		else if(L>mid) return query(rs,mid+1,r,L,R);
		else {
			pii u=query(ls,l,mid,L,R),v=query(rs,mid+1,r,L,R);
			if(u.fir==v.fir) return {u.fir,u.sec+v.sec};
			else return max(u,v);
		}
	}
	inl void build(int rt,int l,int r){
		if(l==r){
			Max[rt]={l-1,1};
			return ;
		}
		int mid=l+r>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(rt);
	}
}mjy;
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(a[i]),pos[i].push_back(0);
	mjy.build(1,1,n);
	rep(i,1,n) {
		if(size(pos[a[i]])>=3){
			int l=pos[a[i]][size(pos[a[i]])-3]+1,r=pos[a[i]][size(pos[a[i]])-2];
			mjy.update(1,1,n,l,r,3);
			last=max(last,l);
		}
		pii tmp=mjy.query(1,1,n,last,i);
		if(tmp.fir==i) ans+=tmp.sec; 
		pos[a[i]].push_back(i);
	}
	printf("%lld\n",ans);
	return 0;
}