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
const int MAXN = 3e5 + 10;
const int MAXM = 1e6 + 10; 
int n,m,opt,x,y,a[MAXN];
int tot,prim[MAXM],d[MAXM],t[MAXM],vis[MAXM];
inl void init(){
	d[1]=1;
	rep(i,2,1e6){
		if(!vis[i]) prim[++tot]=i,d[i]=2,t[i]=1;
		for(int j=1;j<=tot && i*prim[j]<=1e6;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0) {
				d[i*prim[j]]=d[i]/(t[i]+1)*(t[i]+2);
				t[i*prim[j]]=t[i]+1;
				break;
			}
			d[i*prim[j]]=d[i]*2;
			t[i*prim[j]]=1;
		}
	}
}
struct Seg{
	int Max[MAXN<<2];ll sum[MAXN<<2];
	inl void pushup(int rt){
		Max[rt]=max(Max[ls],Max[rs]);
		sum[rt]=sum[ls]+sum[rs];
	}
	inl void build(int rt,int l,int r){
		if(l==r) {
			Max[rt]=sum[rt]=a[l];
			return ;
		} 
		int mid=l+r>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(rt);
	}
	inl void update(int rt,int l,int r,int L,int R){
		if(Max[rt]<=2) return ;
		if(l==r) {
			Max[rt]=sum[rt]=d[Max[rt]];
			return ;
		}
		int mid=l+r>>1;
		if(R<=mid) update(ls,l,mid,L,R);
		else if(L>mid) update(rs,mid+1,r,L,R);
		else update(ls,l,mid,L,R),update(rs,mid+1,r,L,R);
		pushup(rt);
	}
	inl ll query(int rt,int l,int r,int L,int R){
		if(l>=L && r<=R) return sum[rt];
		int mid=l+r>>1;
		if(R<=mid) return query(ls,l,mid,L,R);
		else if(L>mid) return query(rs,mid+1,r,L,R);
		else return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
	}
}mjy;
int main(){
//	freopen("in.txt","r",stdin);
	init();
	read(n),read(m);
	rep(i,1,n) read(a[i]); 
	mjy.build(1,1,n);
	rep(i,1,m){
		read(opt),read(x),read(y);
		if(opt==1) mjy.update(1,1,n,x,y);
		else printf("%lld\n",mjy.query(1,1,n,x,y));
	}	
	return 0;
}