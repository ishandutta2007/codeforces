#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,a[3][N];
ll s[3][N],pre[N],suf[N];
struct Range{
	int l,r,w;
};
vector<Range> q[N];
ll dp[N];
class Segment_Tree_1{
	struct node{
		ll mx;
		node(){mx=-inf;}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].mx=max(t[ls].mx,t[rs].mx);
	}
	void _change(int u,int L,int R,int p,ll d){
		if(L==R){
			t[u].mx=max(t[u].mx,d);
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?_change(ls,L,mid,p,d):_change(rs,mid+1,R,p,d);
		update(u);
	}
	ll _query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return t[u].mx;
		int mid=(L+R)>>1;
		ll mx=-inf;
		if(l<=mid)mx=max(mx,_query(ls,L,mid,l,r));
		if(r>mid)mx=max(mx,_query(rs,mid+1,R,l,r));
		return mx;
	}
public:
	void Change(int u,ll w){
		_change(1,1,n,u,w);
	}
	ll Query(int l,int r){
		return _query(1,1,n,l,r);
	}
}T;
struct Data{
	ll A,B,AB;
	Data(ll _A=-inf,ll _B=-inf,ll _AB=-inf):A(_A),B(_B),AB(_AB){}
	friend Data operator + (const Data &a,const Data &b){
		return Data(max(a.A,b.A),max(a.B,b.B),max(max(a.AB,b.AB),a.A+b.B));
	}
};
class Segment_Tree_2{
	struct node{
		Data d;
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].d=t[ls].d+t[rs].d;	
	}
	void build(int u,int L,int R,ll *a,ll *b){
		if(L==R){
			t[u].d.A=a[L];
			t[u].d.B=b[L];
			t[u].d.AB=a[L]+b[L];
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid,a,b);
		build(rs,mid+1,R,a,b);
		update(u);
	}
	Data _query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return t[u].d;
		}
		int mid=(L+R)>>1;
		if(l<=mid&&r>mid)return _query(ls,L,mid,l,r)+_query(rs,mid+1,R,l,r);
		if(l<=mid)return _query(ls,L,mid,l,r);
		return _query(rs,mid+1,R,l,r);
	}
public:
	ll Query(int l,int r){
		return _query(1,1,n,l,r).AB;
	}
	void init(ll *a,ll *b){
		build(1,1,n,a,b);
	}
}P;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<3;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			s[i][j]=s[i][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		pre[i]=s[0][i]-s[1][i-1];
		suf[i]=s[2][n]-s[2][i-1]+s[1][i];
	}
	for(int i=1;i<=m;++i){
		int l,r,k;
		cin>>l>>r>>k;
		q[r].push_back({l,r,k});
	}
	memset(dp,~0x3f,sizeof(dp));
	for(int i=1;i<=n;++i){
		T.Change(i,pre[i]);
		for(auto t:q[i]){
			dp[i]=max(dp[i],T.Query(t.l,t.r)-t.w);
		}
		if(i<n)T.Change(i+1,dp[i]);
	}
	for(int i=1;i<=n;++i)pre[i]=max(pre[i],dp[i-1]);
	P.init(pre,suf);
	ll ans=-inf;
	for(int i=1;i<=n;++i){
		for(auto t:q[i]){
			ans=max(ans,P.Query(t.l,t.r)-t.w);
		}
	}
	cout<<ans<<'\n';
	return 0;
}