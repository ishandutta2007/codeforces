#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
typedef pair<int,int> pii;
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
int m,n;
vector<pair<int,int> > fish[N],G[N];
struct Data{
	int add;
	map<int,int> sz,sf;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	void adjust(int x,int opt){
		if(opt==1){
			auto it=sf.upper_bound(x-2*add);
			if(it==sf.begin())return;
			q.push(make_pair(x-prev(it)->first,x));	
		}	
		else{
			auto it=sz.lower_bound(x+2*add);
			if(it==sz.end())return;
			q.push(make_pair(it->first-x,it->first));
		}
	}
	void move(int d){
		while(!q.empty()&&q.top().first<=2*(add+d)){
			auto t=q.top();
			q.pop();
			int x=t.second,y=t.second-t.first;
			auto itx=sz.find(x),ity=sf.find(y);
			if(itx==sz.end()||ity==sf.end())continue;
			if(itx->second<(-ity->second)){
				ity->second+=itx->second;
				sz.erase(itx);
				adjust(ity->first,-1);
			}
			else{
				itx->second+=ity->second;
				sf.erase(ity);
				adjust(itx->first,1);	
			}
		}
		add+=d;
	}
	void insert(int t,int x){
		if(x>0){
			sz[t+add]+=x;
			adjust(t+add,1);
		}
		else{
			sf[t-add]+=x;
			adjust(t-add,-1);
		}	
	}
	inline int query(int p){
		return (sz.count(p+add)?sz[p+add]:0)+(sf.count(p-add)?sf[p-add]:0);	
	}
	inline int size(){
		return sz.size()+sf.size();	
	}
	int getans(){
		map<int,int> all;
		for(auto [t,x]:sz)all[t-add]+=x;
		for(auto [t,x]:sf)all[t+add]+=x;
		int mx=0,now=0;
		for(auto [t,x]:all)now+=x,mx=max(mx,now);
		return mx;
	}
}dp[N];
void Merge(Data &A,Data &B){
	if(A.size()<B.size())swap(A,B);
	for(auto [t,x]:B.sz)A.insert(t-B.add,x);
	for(auto [t,x]:B.sf)A.insert(t+B.add,x);
}
void dfs(int u,int fa){
	for(auto [v,w]:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		for(auto &[d,x]:fish[v]){
			x-=max(0,max(-dp[v].query(d),dp[v].query(d+1)));
		}
		dp[v].move(1);
		for(auto [d,x]:fish[v]){
			if(x>0){
				dp[v].insert(d,x);
				dp[v].insert(d+1,-x);
			}
		}
		dp[v].move(w-1);
		Merge(dp[u],dp[v]);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		G[u].emplace_back(v,w<<1);
		G[v].emplace_back(u,w<<1);
	}
	m=read();
	for(int i=1;i<=m;++i){
		int d=read()*2,f=read(),u=read();
		fish[u].emplace_back(d,f);
	}
	int rt=n+1;
	G[rt].emplace_back(1,2);
	dfs(rt,0);
	printf("%d\n",dp[rt].getans());
	return 0;
}