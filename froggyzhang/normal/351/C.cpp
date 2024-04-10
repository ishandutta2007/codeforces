#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const ll inf=1e18;
int n,p[N];
ll m,a[N];
__int128 ans;
class Segment_Tree{
	struct node{
		ll mn,add;
		inline void Add(ll d){
			add+=d,mn+=d;
		}	
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].mn=min(t[ls].mn,t[rs].mn);	
	}
	inline void pushdown(int u){
		if(t[u].add){
			t[ls].Add(t[u].add);
			t[rs].Add(t[u].add);
			t[u].add=0;
		}
	}
public:
	void build(int u,int L,int R,ll tmp){
		if(L==R){
			t[u].mn=tmp+L;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid,tmp);
		build(rs,mid+1,R,tmp);
		update(u);
	}
	void Plus(int u,int L,int R,int l,int r,ll d){
		if(L>=l&&R<=r){
			t[u].Add(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Plus(ls,L,mid,l,r,d);
		if(r>mid)Plus(rs,mid+1,R,l,r,d);
		update(u);
	}
	ll Query(int u,int L,int R,int l,int r){
		if(l>r)return inf;
		if(L>=l&&R<=r){
			return t[u].mn;
		}
		pushdown(u);
		ll mn=inf;
		int mid=(L+R)>>1;
		if(l<=mid)mn=min(mn,Query(ls,L,mid,l,r));
		if(r>mid)mn=min(mn,Query(rs,mid+1,R,l,r));
		return mn;
	}
}Pre,Suf;
void Output(__int128 x){
	if(!x){cout<<0<<'\n';return;}
	static int buf[233],len;
	len=0;
	while(x)buf[++len]=x%10,x/=10;
	while(len)putchar(buf[len--]+'0');	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ans+=(__int128)m*a[i];
	}
	for(int i=1;i<=n;++i){
		ll x;
		cin>>x;
		a[i]=x-a[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return a[i]<a[j];});
	Pre.build(1,1,n,0);
	Suf.build(1,1,n,1LL*n*(m-1));
	for(int zyk=1;zyk<=n;++zyk){
		int i=p[zyk];
		ll t=min(m,min(Suf.Query(1,1,n,1,i-1)/2+1,Suf.Query(1,1,n,i,n)/2));
		if(Pre.Query(1,1,n,i,n)<=1)t=min(t,m-1);
		if(t){
			ans+=(__int128)t*a[i];
			if(t==m)Pre.Plus(1,1,n,i,n,-2);
			if(i>1)Suf.Plus(1,1,n,1,i-1,-2*(t-1));
			Suf.Plus(1,1,n,i,n,-2*t);
		}
	}
	Output(ans);
	return 0;
}