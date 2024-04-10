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
const int MAXN = 6e5+10;
const int Mod = 1e9+7;
int n,q,a[MAXN],p[MAXN],x[MAXN];
ll Pow[MAXN],inv[MAXN];
vector<int> Set;
inl ll mul(ll a,ll b){return a*b%Mod;}
inl ll add(ll a,ll b){return a+b>=Mod?a+b-Mod:a+b;}
namespace SGT{
	struct Seg{
		ll cnt,sum,lsum,rsum;
	}tree[MAXN<<2];
	#define cnt(x) tree[x].cnt
	#define sum(x) tree[x].sum
	#define lsum(x) tree[x].lsum
	#define rsum(x) tree[x].rsum
	#define mid (l+r>>1)
	inl void pushup(int root){
		sum(root)=add(sum(lson),add(sum(rson),mul(mul(lsum(lson),rsum(rson)),inv[cnt(lson)])));
		lsum(root)=add(lsum(lson),mul(Pow[cnt(lson)],lsum(rson)));
		rsum(root)=add(rsum(lson),mul(inv[cnt(lson)],rsum(rson)));
		cnt(root)=add(cnt(lson),cnt(rson));
	}
	inl void build(int root,int l,int r){
		if(l==r && l>n) return ;
		if(l==r) return lsum(root)=a[l],rsum(root)=mul(a[l],inv[1]),cnt(root)=1,void();
		build(lson,l,mid),build(rson,mid+1,r);
		pushup(root);
	}
	inl void update(int root,int l,int r,int pos,int k){
		if(l==r) {
			if(k) {
				sum(root)=add(sum(root),mul(mul(lsum(root),mul(inv[1],Set[pos-1])),inv[cnt(root)]));
				lsum(root)=add(lsum(root),mul(Pow[cnt(root)],Set[pos-1]));
				rsum(root)=add(rsum(root),mul(inv[cnt(root)],mul(Set[pos-1],inv[1])));
				cnt(root)++;
			}
			else {
				cnt(root)--;
				lsum(root)=add(lsum(root),Mod-mul(Pow[cnt(root)],Set[pos-1]));
				rsum(root)=add(rsum(root),Mod-mul(inv[cnt(root)],mul(Set[pos-1],inv[1])));
				sum(root)=add(sum(root),Mod-mul(mul(lsum(root),mul(inv[1],Set[pos-1])),inv[cnt(root)]));	
			}
			return ;
		}
		pos<=mid?update(lson,l,mid,pos,k):update(rson,mid+1,r,pos,k);
		pushup(root);
	}
	#undef cnt(x)
	#undef sum(x)
	#undef lsum(x)
	#undef rsum(x)
	#undef mid 
}
inl void init(){
	Pow[0]=inv[0]=1;
	rep(i,1,n+q) Pow[i]=mul(Pow[i-1],2);
	rep(i,1,n+q) inv[i]=mul(inv[i-1],(Mod+1)/2); 
}
int main(){
	read(n);rep(i,1,n) read(a[i]),Set.pb(a[i]);
	read(q);rep(i,1,q) read(p[i]),read(x[i]),Set.pb(x[i]);
	sort(all(Set));Set.erase(unique(all(Set)),Set.end());
	rep(i,1,n) a[i]=lower_bound(all(Set),a[i])-Set.begin()+1;
	rep(i,1,q) x[i]=lower_bound(all(Set),x[i])-Set.begin()+1;
	init();rep(i,1,n) SGT::update(1,1,n+q,a[i],1);
	printf("%d\n",SGT::tree[1].sum);
	rep(i,1,q){
		SGT::update(1,1,n+q,a[p[i]],0);
		SGT::update(1,1,n+q,a[p[i]]=x[i],1);
		printf("%d\n",SGT::tree[1].sum);
	}
	return 0;
}