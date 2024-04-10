#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int n,m;
char s[N];
inline int ID(int x,int y){
	return (x-1)*m+y;	
}
struct Segment_tree{
	struct node{
		int sum,cov;
	}tree[N<<3];
	#define ls i<<1
	#define rs i<<1|1
	void update(int i,int len){
		if(tree[i].cov){
			tree[i].sum=len;
		}
		else{
			tree[i].sum=tree[ls].sum+tree[rs].sum;
		}
	}
	void Plus(int i,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r){
			tree[i].cov+=d;
			update(i,R-L+1);
			return;
		}
		int mid=(L+R)>>1;
		if(l<=mid)Plus(ls,L,mid,l,r,d);
		if(r>mid)Plus(rs,mid+1,R,l,r,d);
		update(i,R-L+1);
	}	
}T;
vector<int> G[N];
int dfn[N],siz[N],num,to[N],isrt[N];
void dfs(int u){
	dfn[u]=++num;
	siz[u]=1;
	for(auto v:G[u]){
		dfs(v);
		siz[u]+=siz[v];
	}	
}
vector<tuple<int,int,int> > q[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j){
			if(s[j]=='L'){
				to[ID(i,j)]=ID(i,j+1);
				if(j+2<=m)G[ID(i,j+2)].push_back(ID(i,j));
				else isrt[ID(i,j)]=1;
			}
			else if(s[j]=='R'){
				to[ID(i,j)]=ID(i,j-1);
				if(j-2>=1)G[ID(i,j-2)].push_back(ID(i,j));
				else isrt[ID(i,j)]=1;
			}
			else if(s[j]=='U'){
				to[ID(i,j)]=ID(i+1,j);
				if(i+2<=n)G[ID(i+2,j)].push_back(ID(i,j));
				else isrt[ID(i,j)]=1;
			}
			else{
				to[ID(i,j)]=ID(i-1,j);
				if(i-2>=1)G[ID(i-2,j)].push_back(ID(i,j));
				else isrt[ID(i,j)]=1;
			}
		}
	}
	for(int i=1;i<=n*m;++i){
		if(isrt[i])dfs(i);
	}
	for(int i=1;i<=n*m;++i){
		q[dfn[i]].emplace_back(dfn[to[i]],dfn[to[i]]+siz[to[i]]-1,1);
		q[dfn[i]+siz[i]].emplace_back(dfn[to[i]],dfn[to[i]]+siz[to[i]]-1,-1);
	}
	ll ans=0;
	for(int i=1;i<=n*m;++i){
		for(auto [l,r,x]:q[i]){
			T.Plus(1,1,n*m,l,r,x);
		}
		ans+=T.tree[1].sum;
	}
	printf("%lld\n",ans>>1);
	return 0;
}