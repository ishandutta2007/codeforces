#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
mt19937 rnd(time(0));
int n,Q,las[N];
ll lastans;
class Segment_Tree{
	int Len;
	struct node{
		int mn;
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].mn=min(t[ls].mn,t[rs].mn);
	}
public:
	void _change(int u,int L,int R,int pos,int d){
		if(L==R){
			t[u].mn=d;
			return;
		}
		int mid=(L+R)>>1;
		pos<=mid?_change(ls,L,mid,pos,d):_change(rs,mid+1,R,pos,d);
		update(u);
	}
	int _qmin(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return t[u].mn;
		}
		int mid=(L+R)>>1;
		int mn=Q+233;
		if(l<=mid)mn=min(mn,_qmin(ls,L,mid,l,r));
		if(r>mid)mn=min(mn,_qmin(rs,mid+1,R,l,r));
		return mn;
	}
	int _qmex(int u,int L,int R,int lim){
		if(L==R)return L;
		int mid=(L+R)>>1;
		return t[ls].mn>=lim?_qmex(rs,mid+1,R,lim):_qmex(ls,L,mid,lim);
	}
public:
	void init(int n){
		Len=n;
	}
	void Change(int u,int d){
		_change(1,0,Len,u,d);
	}
	int Query_min(int l,int r){
		return _qmin(1,0,Len,l,r);
	}
	int Query_mex(int lim){
		return _qmex(1,0,Len,lim);
	}
	#undef ls
	#undef rs
}T;
struct Rmex{
	int l1,r1,l2,r2;
}now[N];
class FHQ_Treap{
	int cnt,rt[N];
	struct node{
		int ch[2];
		unsigned int key;
		array<ll,3> sum;
		Rmex v;
	}t[N<<1];
	#define ls t[u].ch[0]
	#define rs t[u].ch[1]
	inline void update(int u){
		t[u].sum[2]=t[ls].sum[2]+t[rs].sum[2]+1LL*(t[u].v.r1-t[u].v.l1+1)*(t[u].v.r2-t[u].v.l2+1);
		t[u].sum[1]=t[ls].sum[1]+t[rs].sum[1]+1LL*t[u].v.r1*(t[u].v.r2-t[u].v.l2+1);
		t[u].sum[0]=t[ls].sum[0]+t[rs].sum[0]+(t[u].v.r2-t[u].v.l2+1);
	}
	int NewNode(Rmex v){
		int u=++cnt;
		t[u].key=rnd();
		t[u].v=v;
		t[u].sum[0]=v.r2-v.l2+1;
		t[u].sum[1]=1LL*v.r1*(v.r2-v.l2+1);
		t[u].sum[2]=1LL*(v.r1-v.l1+1)*(v.r2-v.l2+1);
		return u;
	}
	int Merge(int l,int r){
		if(!l||!r)return l|r;
		if(t[l].key<t[r].key){
			t[l].ch[1]=Merge(t[l].ch[1],r);
			update(l);
			return l;
		}
		else{
			t[r].ch[0]=Merge(l,t[r].ch[0]);
			update(r);
			return r;
		}
	}
	template<typename sp_fun>
	void Split(int u,int &l,int &r,sp_fun fun){
		if(!u){
			l=r=0;return;
		}
		if(fun(t[u].v)){
			l=u;
			Split(rs,rs,r,fun);
		}
		else{
			r=u;
			Split(ls,l,ls,fun);
		}
		update(u);
	}
	void pushback(int k,Rmex v){
		rt[k]=Merge(rt[k],NewNode(v));
	}
public:
	void Insert(int x){
		if(n==1){
			now[!x]={1,1,1,0};
			T.Change(x,1);
			return;
		}
		int l=T.Query_min(0,x);
		int r=!x?n-1:T.Query_min(0,x-1);
		// (l,r]
		T.Change(x,n);
		auto Del=[&](int k){
			pushback(k,now[k]);
			now[k]={-1,0,0,0};
		};
		if(l<r){
			now[x].r2=n-1;
			Del(x);
			if(l){
				int k=T.Query_mex(l);
				now[k].r2=n-1;
				Del(k);
			}
			while(l<r){
				int k=T.Query_mex(r);
				int nxt=T.Query_min(0,k);
				now[k]={nxt+1,r,n,0};
				r=nxt;
			}
		}
		int k=!x;
		if(~now[k].l1&&now[k].l2<n){
			now[k].r2=n-1;Del(k);
		}
		now[k]={T.Query_min(0,k)+1,n,n,0};
	}
	ll Query(int l,int r,int k){
		static int d[4];
		memset(d,0,sizeof(d));
		Split(rt[k],rt[k],d[3],[&](const Rmex &v){return v.l2<=r;});
		Split(rt[k],rt[k],d[2],[&](const Rmex &v){return v.r2<=r;});
		Split(rt[k],rt[k],d[1],[&](const Rmex &v){return v.l1<l;});
		Split(rt[k],rt[k],d[0],[&](const Rmex &v){return v.r1<l;});
		ll ans=0;
		auto calc=[&](Rmex v)->ll{
			return 1LL*max(0,min(r,v.r2)-max(l,v.l2)+1)*max(0,min(r,v.r1)-max(l,v.l1)+1);
		};
		if(d[2]){
			ans+=calc(t[d[2]].v);
		}
		ans+=t[d[1]].sum[2]+t[d[0]].sum[1]-(l-1)*t[d[0]].sum[0];
		for(int i=0;i<4;++i)rt[k]=Merge(rt[k],d[i]);
		if(~now[k].l1){
			now[k].r2=n;
			ans+=calc(now[k]);
		}
		return ans;
	}
}F;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>Q;
	T.init(Q);
	for(int i=0;i<=Q;++i)now[i].l1=-1;
	for(n=1;n<=Q;++n){
		int x,l,r,k;
		cin>>x>>l>>r>>k;
		x=(x+lastans)%(Q+1);
		l=(l+lastans)%n+1;
		r=(r+lastans)%n+1;
		k=(k+lastans)%(Q+1);
		if(l>r)swap(l,r);
		F.Insert(x);
		cout<<(lastans=F.Query(l,r,k))<<'\n';
	}
	return 0;
}