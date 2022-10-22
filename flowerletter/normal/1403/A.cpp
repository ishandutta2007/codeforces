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
#define lson rt<<1
#define rson rt<<1|1
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
const int MAXN = 5e5+10;
int n,m,Q,p[MAXN],rev[MAXN],is[MAXN];
int Nodecnt,ls[MAXN],rs[MAXN];
int top[MAXN];
struct Edge{
	int u,v;
}e[MAXN];
struct que{
	int opt,x;
}q[MAXN];
namespace ufs{
	int fa[MAXN];
	inl void clear(){
		rep(i,1,n<<1) fa[i]=i;
	}
	inl int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
}
int dfs_time,L[MAXN],R[MAXN];
inl void dfs(int u){
	if(u<=n) L[u]=R[u]=++dfs_time,rev[dfs_time]=p[u];
	else {
		//cout<<u<<":"<<ls[u]<<' '<<rs[u]<<'\n';
		L[u]=dfs_time+1;
		dfs(ls[u]),dfs(rs[u]);
		R[u]=dfs_time;
	}
}
namespace seg{
	int Max[MAXN<<1],pos[MAXN<<1];
	inl void pushup(int rt){
		if(Max[lson]<Max[rson]) Max[rt]=Max[rson],pos[rt]=pos[rson];
		else Max[rt]=Max[lson],pos[rt]=pos[lson];
	}
	inl void update(int rt,int l,int r,int k){
		if(l==r){
			Max[rt]=0;
			return ;
		}
		int mid=l+r>>1;
		if(k<=mid) update(lson,l,mid,k);
		else update(rson,mid+1,r,k);
		pushup(rt);
	}
	inl pii query(int rt,int l,int r,int L,int R){
		if(l>=L && r<=R) return {Max[rt],pos[rt]};
		int mid=l+r>>1;
		if(R<=mid) return query(lson,l,mid,L,R);
		else if(L>mid) return query(rson,mid+1,r,L,R);
		else return max(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
	}
	inl void build(int rt,int l,int r){
		if(l==r){
			pos[rt]=l;
			Max[rt]=rev[l];
			return ;
		}
		int mid=l+r>>1;
		build(lson,l,mid),build(rson,mid+1,r);
		pushup(rt);
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m),read(Q);Nodecnt=n;
	rep(i,1,n) read(p[i]);
	rep(i,1,m) read(e[i].u),read(e[i].v);
	rep(i,1,Q) read(q[i].opt),read(q[i].x);
	rep(i,1,Q) if(q[i].opt==2) is[q[i].x]=1;
	ufs::clear();
	rep(i,1,m){
		if(!is[i]) {
			int x=ufs::find(e[i].u),y=ufs::find(e[i].v);
			//cout<<e[i].u<<' '<<e[i].v<<'\n';
			if(x==y) continue;
			ufs::fa[x]=ufs::fa[y]=++Nodecnt;
			ls[Nodecnt]=x,rs[Nodecnt]=y;
		}
	}
	per(i,Q,1){
		if(q[i].opt==1){
			int x=ufs::find(q[i].x);
			top[i]=x;
		}
		if(q[i].opt==2){
			int x=ufs::find(e[q[i].x].u),y=ufs::find(e[q[i].x].v);
			//cout<<e[q[i].x].u<<' '<<e[q[i].x].v<<'\n';
			if(x==y) continue;
			ufs::fa[x]=ufs::fa[y]=++Nodecnt;
			ls[Nodecnt]=x,rs[Nodecnt]=y;
		}
	}
	int last=0;
	rep(i,1,Nodecnt) {
		if(ufs::find(i)==i) {
			if(last){
				ufs::fa[i]=ufs::fa[last]=++Nodecnt;
				ls[Nodecnt]=i,rs[Nodecnt]=last;
				last=0;
			}
			else last=i;
		}
	}
	dfs(Nodecnt);
	seg::build(1,1,n);
	rep(i,1,Q){
		if(q[i].opt==1){
			//cout<<top[i]<<":";
			pii Max=seg::query(1,1,n,L[top[i]],R[top[i]]);
			printf("%d\n",Max.fir);
			seg::update(1,1,n,Max.sec);
		}
	}
	return 0;
}