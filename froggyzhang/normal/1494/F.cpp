#include<bits/stdc++.h>
using namespace std;
#define N 3005
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
int n,m,vis[N],d[N];
vector<pair<int,int> > G[N],H[N];
vector<int> ans;
void dfs(int u,vector<int> &vec){
	while(true){
		while(!H[u].empty()&&vis[H[u].back().second])H[u].pop_back();
		if(H[u].empty())break;
		auto [v,id]=H[u].back();
		vis[id]=1;
		H[u].pop_back();
		dfs(v,vec);
	}
	vec.push_back(u);	
}
vector<int> Euler(int S){
	memset(vis,0,sizeof(vis));
	vector<int> E;
	int ecnt=0,odd=0;
	for(int i=1;i<=n;++i){
		ecnt+=H[i].size();
		if(i^S&&(int)H[i].size()&1)++odd;
	}
	if(odd<=1){
		ecnt>>=1;
		dfs(S,E);
		if((int)E.size()-1!=ecnt)E.clear();
	}
	return E;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
		++d[u],++d[v];	
	}
	int odd=0,S=1;
	for(int i=1;i<=n;++i){
		if(d[i]&1)++odd,S=i;
	}
	if(odd<=2){
		for(int i=1;i<=n;++i)H[i]=G[i];
		ans=Euler(S);	
	}
	else{
		for(int u=1;u<=n&&ans.empty();++u){
			static vector<int> ID;
			ID.clear();
			ID.push_back(0);
			for(auto [v,id]:G[u])ID.push_back(id);
			for(auto ok:ID){
				for(int i=1;i<=n;++i){
					H[i].clear();
					if(u==i){
						for(auto [v,id]:G[i]){
							if(!(d[v]&1)||ok==id)H[i].emplace_back(v,id);
						}
					}
					else{
						for(auto [v,id]:G[i]){
							if(v^u||!(d[i]&1)||ok==id)H[i].emplace_back(v,id);
						}
					}	
				}
				auto z=Euler(u);
				if(!z.empty()){
					ans=z;
					ans.push_back(-1);
					for(auto [v,id]:G[u]){
						if(d[v]&1 && id^ok)ans.push_back(v),ans.push_back(u);
					}
					break;
				}
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",x);
	}
	return 0;
}