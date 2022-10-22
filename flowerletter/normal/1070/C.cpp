/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define mst0(x) memset(x,0,sizeof(x))
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
const int MAXN = 2e6+10;
int n,k,m,l,r;
ll ans;
pll x;
vector<pii> add[MAXN],del[MAXN];
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
inl pll operator + (const pll a,const pll b){return {a.fir+b.fir,a.sec+b.sec};}
struct FHQ_Treap{
	template<class T>struct MemoryPool{
		T buf[MAXN],*tail,*st[MAXN];
		int top;
		MemoryPool():top(0),tail(buf){}
		inl T *alloc(){return top?st[top--]:tail++;}
		inl void recycle(T *x){st[++top]=x;} 
	};
	struct Node{
		Node *ls,*rs;
		pll val,sum;
		ll ans;
		int rnd,size;
		inl void PushUp(){sum=ls->sum+rs->sum+val;size=ls->size+rs->size+1;ans=ls->ans+rs->ans+val.fir*val.sec;}
	}*root,*null;
	MemoryPool<Node> pool;
	inl Node *NewNode(pll x){
		Node *tmp=pool.alloc();
		tmp->ls=tmp->rs=null,tmp->val=tmp->sum=x,tmp->rnd=rand(),tmp->ans=x.fir*x.sec;
		return tmp;
	}
	inl Node *Merge(Node *u,Node *v){
		if(u==null || v==null) return u==null?v:u;
		if(u->rnd<v->rnd){
			u->rs=Merge(u->rs,v),u->PushUp();
			return u;
		}else {
			v->ls=Merge(u,v->ls),v->PushUp();
			return v;
		}
	}
	inl void Split(Node *u,Node *&x,Node *&y,pll k){
		if(u==null) return x=y=null,void();
		if(u->val<k)x=u,Split(u->rs,x->rs,y,k);
		else y=u,Split(u->ls,x,y->ls,k);
		u->PushUp();
	}
	inl void Split(Node *u,Node *&x,Node *&y,ll k){
		if(u==null) return x=y=null,void();
		if(u->ls->sum.sec+u->val.sec<=k)x=u,Split(u->rs,x->rs,y,k-u->ls->sum.sec-u->val.sec);
		else y=u,Split(u->ls,x,y->ls,k);
		u->PushUp();
	}
	inl void Split(Node *u,Node *&x,Node *&y,int k){
		if(u==null) return x=y=null,void();
		if(u->ls->size<k)x=u,Split(u->rs,x->rs,y,k-u->ls->size-1);
		else y=u,Split(u->ls,x,y->ls,k);
		u->PushUp();
	}
	inl void insert(pll x){
		Node *u,*v;
		Split(root,u,v,x);
		root=Merge(Merge(u,NewNode(x)),v);
	}
	inl void Delete(pll x){
		Node *u,*v,*w;
		Split(root,u,v,x),Split(v,v,w,1);
		pool.recycle(v);
		root=Merge(u,w);
	}
	inl ll Query(ll k){
		Node *u,*v;
		Split(root,u,v,k);
		if(v==null || k==u->sum.sec) {
			ll ans=u->ans;
			root=Merge(u,v);
			return ans;
		}
		else {
			Node *w;
			Split(v,v,w,1);
			ll ans=u->ans+(k-u->sum.sec)*v->val.fir;
			root=Merge(u,Merge(v,w));
			return ans; 
		}
	}
	inl void iod(Node *u){
		if(u==null) return ;
		iod(u->ls);
		printf("%d %d %d %d\n",u->val.fir,u->val.sec,u->sum.fir,u->sum.sec);
		iod(u->rs);
	}
	inl void init(){root=null=new (Node){null,null,{0,0},{0,0},0,0};}
}mjy;
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(k),read(m);mjy.init();
	rep(i,1,m)read(l),read(r),read(x.sec),read(x.fir),add[l].pb(x),del[r].pb(x);
	rep(i,1,n){
		for(auto x:add[i]) mjy.insert(x);
		ans+=mjy.Query(k);
		for(auto x:del[i]) mjy.Delete(x);
	}printf("%lld\n",ans);
	return 0;
}