#include<bits/stdc++.h>
using namespace std;
#define N 100010
const int mod=1e9+7;
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
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int root[N],n,Q,lastans;
int Last;
namespace Chair{
	int cnt;
	struct node{
		int ch[2],mul;
		node(){mul=1;}
	}tree[N*280];
	#define ls tree[u].ch[0]
	#define rs tree[u].ch[1]
	inline void update(int u){
		tree[u].mul=1LL*tree[ls].mul*tree[rs].mul%mod;
	}
	void Modify(int &u,int v,int L,int R,int p,int d){
		if(v<=Last)u=++cnt,tree[u]=tree[v];
		tree[u].mul=1LL*tree[u].mul*d%mod;
		if(L==R)return;
		int mid=(L+R)>>1;
		p<=mid?Modify(ls,tree[v].ch[0],L,mid,p,d):Modify(rs,tree[v].ch[1],mid+1,R,p,d);
	}
	int Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return tree[u].mul;
		int ans=1;
		int mid=(L+R)>>1;
		if(l<=mid)ans*=Query(ls,L,mid,l,r);
		if(r>mid)ans=1LL*ans*Query(rs,mid+1,R,l,r)%mod;
		return ans;
	}
}
vector<pair<int,int> > pos[N<<1];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		root[i]=root[i-1];
		int x=read();
		Last=Chair::cnt;
		for(int j=2;x>1;++j){
			if(x%j==0){
				int cnt=0;
				while(x%j==0){
					x/=j;++cnt;
				}
				while(!pos[j].empty()&&cnt>=pos[j].back().second){
					int w=qpow(j,pos[j].back().second);
					Chair::Modify(root[i],root[i],1,n,pos[j].back().first,qpow(w,mod-2));
					pos[j].pop_back();
					if(!pos[j].empty())Chair::Modify(root[i],root[i],1,n,pos[j].back().first,w);
				}
				int w=qpow(j,cnt);
				if(!pos[j].empty()){
					Chair::Modify(root[i],root[i],1,n,pos[j].back().first,qpow(w,mod-2));
				}
				pos[j].emplace_back(i,cnt);
				Chair::Modify(root[i],root[i],1,n,i,w);
			}
			if(j*j>x)j=x-1;
		}
	}
	Q=read();
	while(Q--){
		int l=(read()+lastans)%n+1;
		int r=(read()+lastans)%n+1;
		if(l>r)swap(l,r);
		printf("%d\n",lastans=Chair::Query(root[r],1,n,l,r));
	}
	return 0;
}