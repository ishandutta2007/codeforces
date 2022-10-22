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
const int MAXN = 1e5 + 10;
struct Node{
	int x,y;
}a[MAXN];
int n,m;
vector<int> S,T,Set;
map<pii,bool> Map;
inl bool cmp(Node a,Node b){
	return a.x-a.y>b.x-b.y;
}
struct Segment{
	#define ls rt<<1
	#define rs rt<<1|1
	pii Min[MAXN<<2];
	int tag;
	inl void pushup(int rt){
		Min[rt]=min(Min[ls],Min[rs]);
	}
	inl pii query(int rt,int l,int r,int L,int R){
		if(L>R) return {2e9,-1};
		if(l>=L && r<=R) return Min[rt]; 
		int mid=l+r>>1;
		if(R<=mid) return query(ls,l,mid,L,R);
		else if(L>mid) return query(rs,mid+1,r,L,R);
		else return min(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
	}
	inl void update(int rt,int l,int r,int pos) {
		if(l==r) return Min[rt]={2e9,-1},void();
		int mid=l+r>>1;
		if(pos<=mid) update(ls,l,mid,pos);
		else update(rs,mid+1,r,pos);
		pushup(rt);
	}
	inl void build(int rt,int l,int r,int opt){
		if(l==r) {
			Min[rt]={opt?a[l].y:a[l].x,l};
			return ;
		}
		int mid=l+r>>1;
		build(ls,l,mid,opt),build(rs,mid+1,r,opt);
		pushup(rt);
	}
	#undef ls
	#undef rs
}t[2];
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,n) read(a[i].x),read(a[i].y),Map[{a[i].x,a[i].y}]=1;
	sort(a+1,a+n+1,cmp);
	per(i,n,1) Set.push_back(a[i].x-a[i].y);
	t[0].build(1,1,n,0),t[1].build(1,1,n,1);
	int delta=0;S.push_back(-1),T.push_back(-1);
	rep(i,1,n) {
		int pos=n-(lower_bound(all(Set),delta)-Set.begin())+1;
		pii lans=t[0].query(1,1,n,1,pos-1),rans=t[1].query(1,1,n,pos,n);
		lans.fi-=t[0].tag,rans.fi-=t[1].tag;
		pii Min=min(lans,rans);
		int id=Min.se;
		if(a[id].x-a[id].y==delta) {
			if(S.back()!=a[id].x && T.back()!=a[id].y) {
				t[0].tag++,S.push_back(a[id].x);
				t[1].tag++,T.push_back(a[id].y);
			}
		} else if(a[id].x-a[id].y>delta) {
			if(S.back()!=a[id].x) delta++,t[0].tag++,S.push_back(a[id].x);
		} else if(a[id].x-a[id].y<delta) {
			if(T.back()!=a[id].y) delta--,t[1].tag++,T.push_back(a[id].y);
		}
		t[0].update(1,1,n,id);t[1].update(1,1,n,id);
 	}
 	rep(i,1,m) {
 		int x,y;
 		read(x),read(y);
 		if(Map[{x,y}]) {puts("LOSE");continue;}
 		if(binary_search(all(S),x) || binary_search(all(T),y)) {puts("WIN");continue;}
		x-=lower_bound(all(S),x)-S.begin();
 		y-=lower_bound(all(T),y)-T.begin();
 		puts(x==y?"LOSE":"WIN");
	}
	return 0;
}