#include<bits/stdc++.h>
using namespace std;
#define N 101010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int a[N],n,Q;
struct Seg_ment{
	struct node{
		int l,r;
		ll sum,add;
		inline void Add(ll d){
			sum+=(r-l+1)*d,add+=d;
		}
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		tree[i].sum=tree[ls].sum+tree[rs].sum;
	}
	inline void pushdown(int i){
		if(tree[i].add){
			tree[ls].Add(tree[i].add);
			tree[rs].Add(tree[i].add);
			tree[i].add=0;
		}
	}
	void build(int i,int l,int r){
		tree[i].l=l;
		tree[i].r=r;
		tree[i].add=tree[i].sum=0;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	void Plus(int i,int l,int r,int d){
		if(tree[i].l>=l&&tree[i].r<=r){
			tree[i].Add(d);
			return;
		}
		pushdown(i);
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid)Plus(ls,l,r,d);
		if(r>mid)Plus(rs,l,r,d);
		update(i);
	}
	ll Query(int i,int l,int r){
		if(tree[i].l>=l&&tree[i].r<=r){
			return tree[i].sum;
		}
		pushdown(i);
		int mid=(tree[i].l+tree[i].r)>>1;
		ll tot=0;
		if(l<=mid)tot+=Query(ls,l,r);
		if(r>mid)tot+=Query(rs,l,r);
		return tot;
	}
}T;
int tot;
map<int,int> id;
set<pair<int,int> > s[N];
set<pair<pair<int,int>,int> > all; 
void Change(int A,int B,int w){
	if(A>B)swap(A,B);
	T.Plus(1,1,A,w);
	if(B<n)T.Plus(1,B+1,min(n,A+B),-w);
}
inline void Erase(int l,int r,int u){
	all.erase(make_pair(make_pair(l,r),u));
	auto it=s[u].lower_bound(make_pair(l,r));
	int R=n+1;
	if((++it)!=s[u].end()){
		R=it->first;
	}
	--it,--it;
	int L=it->second;
	if(R<=n){
		Change(R-r,n-R+1,-1);
		Change(R-L,n-R+1,1);
	}
	++it;
	s[u].erase(it);
	Change(l-L,n-l+1,-1);
	if(l<r){
		T.Plus(1,1,1,-(r-l));
		T.Plus(1,n-r+2,min(n,n-l+1),1);
	}
}
inline void Insert(int l,int r,int u){
	all.insert(make_pair(make_pair(l,r),u));
	auto it=s[u].lower_bound(make_pair(l,r));
	int R=n+1;
	if(it!=s[u].end()){
		R=it->first;
	}
	--it;
	int L=it->second;
	if(R<=n){
		Change(R-r,n-R+1,1);
		Change(R-L,n-R+1,-1);
	}
	s[u].insert(make_pair(l,r));
	Change(l-L,n-l+1,1);
	if(l<r){
		T.Plus(1,1,1,r-l);
		T.Plus(1,n-r+2,min(n,n-l+1),-1);
	}
}
int main(){
	n=read(),Q=read();
	T.build(1,1,n);
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(!id.count(a[i]))id[a[i]]=++tot,s[tot].insert(make_pair(0,0));
		Insert(i,i,id[a[i]]);
	}
	while(Q--){
		int opt=read();
		if(opt==1){
			int l=read(),r=read(),x=read();
			if(!id.count(x))id[x]=++tot,s[tot].insert(make_pair(0,0));
			x=id[x];
			auto it=--all.lower_bound(make_pair(make_pair(l,n+1),233));
			int itl=it->first.first,itr=it->first.second,itu=it->second;
			Erase(itl,itr,itu);
			if(itl < l){
				Insert(itl,l-1,itu);	
			}
			if(itr > r){
				Insert(r+1,itr,itu);
			}
			else{
				while(true){
					it=all.lower_bound(make_pair(make_pair(l,0),0));
					if(it==all.end()||it->first.second > r)break;
					Erase(it->first.first,it->first.second,it->second);
				}
				if(it!=all.end()&&it->first.first <=r ){
					itl=it->first.first,itr=it->first.second,itu=it->second;
					Erase(itl,itr,itu);
					Insert(r+1,itr,itu);
				}
			}
			Insert(l,r,x);
		}
		else{
			int k=read();
			printf("%lld\n",T.Query(1,1,k));
		}
	}
	return 0;
}