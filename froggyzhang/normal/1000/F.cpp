#include<bits/stdc++.h>
using namespace std;
#define N 500010
typedef long long ll;
int n,a[N],m,ans[N];
vector<pair<int,int> > q[N];
class Segment_Tree{
	struct node{
		pair<int,int> val;
		node(){val=make_pair(1e9,0);}
	}tree[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		tree[u].val=min(tree[ls].val,tree[rs].val);	
	}
public:
	void Change(int u,int L,int R,int p,pair<int,int> x){
		if(L==R)return (void)(tree[u].val=x);
		int mid=(L+R)>>1;
		p<=mid?Change(ls,L,mid,p,x):Change(rs,mid+1,R,p,x);
		update(u);
	}
	pair<int,int> Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return tree[u].val;
		}
		int mid=(L+R)>>1;
		pair<int,int> ans=make_pair(1e9,0);
		if(l<=mid)ans=min(ans,Query(ls,L,mid,l,r));
		if(r>mid)ans=min(ans,Query(rs,mid+1,R,l,r));
		return ans;
	}
}T;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		int l,r;
		cin>>l>>r;
		q[r].emplace_back(l,i);	
	}
	for(int i=1;i<=n;++i){
		static int las[N];
		if(las[a[i]]){
			T.Change(1,1,n,las[a[i]],make_pair(1e9,0));	
		}	
		T.Change(1,1,n,i,make_pair(las[a[i]]+1,a[i]));
		for(auto [l,id]:q[i]){
			auto [mn,num]=T.Query(1,1,n,l,i);
			ans[id]=mn<=l?num:0;	
		}
		las[a[i]]=i;
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<'\n';	
	}
	return 0;
}