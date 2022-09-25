#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
#define YES cout<<"White\n";return;
#define NO cout<<"Draw\n";return;
int n,d[N];
char s[N];
vector<int> G[N];
pair<int,int> dfs(int u,int fa){
	pair<int,int> mx=make_pair(0,u);
	for(auto v:G[u]){
		if(v==fa)continue;
		auto t=dfs(v,u);
		++t.first;
		mx=max(mx,t);
	}
	return mx;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		G[i].clear();d[i]=0;
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		++d[u],++d[v];
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin>>(s+1);
	if(n<=3){
		if((s[1]=='W')+(s[2]=='W')+(s[3]=='W')>=2){YES;}
		NO;
	}
	for(int i=1;i<=n;++i){
		if(d[i]>=4){YES;}
	}
	for(int i=1;i<=n;++i){
		if(d[i]==3){
			int tmp=0;
			for(auto v:G[i]){
				tmp+=d[v]>=2||s[v]=='W';
			}
			if(tmp>=2){YES;}
		}
	}
	for(int i=1;i<=n;++i){
		if(s[i]=='W'&&(d[i]>=2||d[G[i][0]]>=3)){YES;}
	}
	int cnt=accumulate(s+1,s+n+1,0,[&](int i,char c){return i+(c=='W');});
	int ck=cnt+accumulate(d+1,d+n+1,0,[&](int i,int j){return i+(j==3);});
	if(ck^2){NO;}
	int rt=dfs(1,0).second;
	int len=dfs(rt,0).first;
	if(!(len&1)){YES;}
	NO;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}