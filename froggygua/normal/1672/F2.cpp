#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],b[N],cnt[N];
vector<int> G[N];
int ins[N],vis[N];
bool ok;
void dfs(int u){
	vis[u]=ins[u]=1;
	for(auto v:G[u]){
		if(vis[v]){
			if(ins[v]){
				ok=1;
			}
		}
		else{
			dfs(v);
		}
	}
	ins[u]=0;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)G[i].clear(),cnt[i]=vis[i]=ins[i]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		++cnt[b[i]];
	}
	int jb=max_element(cnt+1,cnt+n+1)-cnt;
	for(int i=1;i<=n;++i){
		if(a[i]!=jb&&b[i]!=jb)G[a[i]].push_back(b[i]);
	}
	ok=0;
	for(int i=1;i<=n;++i){
		if(!vis[i])dfs(i);
		if(ok){
			cout<<"WA\n";
			return;
		}
	}
	cout<<"AC\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}