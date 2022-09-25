#include<bits/stdc++.h>
using namespace std;
#define N 100010
const int mod=95542721;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
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
int n,Q,a[N];
class Segment_Tree{
public:
	struct node{
		int w[48],z;
		node(){memset(w,0,sizeof(w));}
		inline void Add(int d){
			z=(z+d)%48;
			static int _w[48];
			for(int i=0;i<48;++i){
				_w[i]=w[(i+d)%48];
			}
			memcpy(w,_w,sizeof(_w));
		}
	}tree[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		for(int i=0;i<48;++i){
			tree[u].w[i]=(tree[ls].w[i]+tree[rs].w[i])%mod;
		}
	}
	inline void pushdown(int u){
		if(tree[u].z){
			tree[ls].Add(tree[u].z);
			tree[rs].Add(tree[u].z);
			tree[u].z=0;
		}
	}
	void Change(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			tree[u].Add(1);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Change(ls,L,mid,l,r);
		if(r>mid)Change(rs,mid+1,R,l,r);
		update(u);	
	}
	int Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return tree[u].w[0];
		}
		pushdown(u);
		int ans=0;
		int mid=(L+R)>>1;
		if(l<=mid)ans=(ans+Query(ls,L,mid,l,r))%mod;
		if(r>mid)ans=(ans+Query(rs,mid+1,R,l,r))%mod;
		return ans;
	}
	void build(int u,int L,int R){
		if(L==R){
			tree[u].w[0]=a[L];
			for(int i=1;i<48;++i){
				tree[u].w[i]=1LL*tree[u].w[i-1]*tree[u].w[i-1]%mod*tree[u].w[i-1]%mod;
			}
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
}T;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();	
	}
	Q=read();
	T.build(1,1,n);
	while(Q--){
		int opt=read(),l=read(),r=read();
		if(opt==2){
			T.Change(1,1,n,l,r);
		}
		else{
			printf("%d\n",T.Query(1,1,n,l,r));
		}
	}
	return 0;
}