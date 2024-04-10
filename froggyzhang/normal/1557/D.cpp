#include<bits/stdc++.h>
using namespace std;
#define N 300030
const int M=1e9;
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
vector<int> zyk;
struct Data{
	int mx,pos;
	Data(int _a=0,int _b=0){mx=_a,pos=_b;}
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		c.mx=max(a.mx,b.mx);
		c.pos=(c.mx==a.mx?a.pos:b.pos);
		return c;	
	}
}dp[N];
class Segment_Tree{
	int cnt;
public:
	int rt;
	struct node{
		int ch[2];
		Data p,t;
	}tree[N*30];
	#define ls tree[u].ch[0]
	#define rs tree[u].ch[1]
	inline void update(int u){
		tree[u].t=tree[u].p+tree[ls].t+tree[rs].t;
	}
	void Cover(int &u,int L,int R,int l,int r,Data d){
		if(!u)u=++cnt;
		if(L>=l&&R<=r){tree[u].p=tree[u].p+d;tree[u].t=tree[u].p;return;}
		int mid=(L+R)>>1;
		if(l<=mid)Cover(ls,L,mid,l,r,d);
		if(r>mid)Cover(rs,mid+1,R,l,r,d);
		update(u);
	}
	Data Query(int u,int L,int R,int l,int r){
		if(!u)return Data(0,0);
		if(L>=l&&R<=r)return tree[u].t;
		Data ans=tree[u].p;
		int mid=(L+R)>>1;
		if(l<=mid)ans=ans+Query(ls,L,mid,l,r);
		if(r>mid)ans=ans+Query(rs,mid+1,R,l,r);
		return ans;
	}
}T;
vector<pair<int,int> > g[N];
void dfs(int u){
	if(!u)return;
	dfs(dp[u].pos);
	for(int i=dp[u].pos+1;i<u;++i)zyk.push_back(i);	
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),l=read(),r=read();
		g[u].emplace_back(l,r);
	}
	for(int i=1;i<=n;++i){
		dp[i]=Data(1,0);
		for(auto [l,r]:g[i]){
			Data tmp=T.Query(T.rt,1,M,l,r);
			++tmp.mx;
			dp[i]=dp[i]+tmp;
		}
		for(auto [l,r]:g[i]){
			T.Cover(T.rt,1,M,l,r,Data(dp[i].mx,i));	
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,dp[i].mx);	
	}
	printf("%d\n",n-ans);
	for(int i=1;i<=n;++i){
		if(ans==dp[i].mx){
			dfs(i);
			for(int j=i+1;j<=n;++j)zyk.push_back(j);
			break;
		}	
	}
	for(auto x:zyk)printf("%d ",x);
	return 0;
}