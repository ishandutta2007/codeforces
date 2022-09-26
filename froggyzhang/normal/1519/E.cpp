#include<bits/stdc++.h>
using namespace std;
#define N 400040
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
int n,cnt,vis[N],ok[N],dep[N];
vector<pair<int,int> > G[N];
map<pair<ll,ll>,int> mp;
vector<pair<int,int> > ans;
void dfs(int u){
	vis[u]=1;
	int t=0;
	vector<int> H;
	for(auto [v,id]:G[u]){
		if(!vis[v]||dep[v]>dep[u]){
			if(!vis[v])dep[v]=dep[u]+1,dfs(v);
			if(!ok[id]){
				if(t)ans.emplace_back(t,id),ok[t]=ok[id]=1,t=0;
				else t=id;
			}
		}
		else if(!ok[id]){
			H.push_back(id);
		}
	}
	for(auto id:H){
		if(t)ans.emplace_back(t,id),ok[t]=ok[id]=1,t=0;
		else t=id;		
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int a=read(),b=read(),c=read(),d=read();
		ll x=1LL*(a+b)*d;
		ll y=1LL*b*c;
		ll g=__gcd(x,y);
		x/=g,y/=g;
		auto t=make_pair(x,y);
		if(!mp.count(t))mp[t]=++cnt;
		int u=mp[t];
		x=1LL*a*d;
		y=1LL*b*(c+d);
		g=__gcd(x,y);
		x/=g,y/=g;
		t=make_pair(x,y);
		if(!mp.count(t))mp[t]=++cnt;
		int v=mp[t];
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
	}
	for(int i=1;i<=cnt;++i){
		if(!vis[i])dfs(i);
	}
	printf("%d\n",(int)ans.size());
	for(auto [x,y]:ans){
		printf("%d %d\n",x,y);
	}
	return 0;
}


/*qwq*/