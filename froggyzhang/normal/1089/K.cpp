#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000010
const int mx=1e6;
int Q,a[N],b[N];
class Segment_Tree{
	struct node{
		ll sum,wait;
		node(){sum=wait=0;}
	}tree[N<<2];
public:
	#define ls u<<1
	#define rs u<<1|1
	inline void update(node &u,const node &ul,const node &ur){
		u.sum=ul.sum+ur.sum;
		u.wait=max(ul.wait+ur.sum,ur.wait);
	}
	void build(int u,int L,int R){
		if(L==R){tree[u].wait=L,tree[u].sum=0;return;}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(tree[u],tree[ls],tree[rs]);
	}
	void Change(int u,int L,int R,int x,int y){
		if(L==R){
			tree[u].sum+=y;
			tree[u].wait+=y;
			return;
		}
		int mid=(L+R)>>1;
		x<=mid?Change(ls,L,mid,x,y):Change(rs,mid+1,R,x,y);
		update(tree[u],tree[ls],tree[rs]);
	}
	node Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return tree[u];
		int mid=(L+R)>>1;
		node ans;
		if(l<=mid)ans=Query(ls,L,mid,l,r);
		if(r>mid)update(ans,ans,Query(rs,mid+1,R,l,r));
		return ans;
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>Q;
	T.build(1,1,mx);
	for(int i=1;i<=Q;++i){
		char opt;
		cin>>opt>>a[i];
		if(opt=='+'){
			cin>>b[i];
			T.Change(1,1,mx,a[i],b[i]);
		}
		else if(opt=='-'){
			T.Change(1,1,mx,a[a[i]],-b[a[i]]);
		}
		else{
			cout<<T.Query(1,1,mx,1,a[i]).wait-a[i]<<'\n';	
		}
	}
	return 0;
}