#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
vector<int> e[N];
int n;
int d[N],lf[N],fa[N],sz[N];
void dfs(int x){
	d[x]=e[x].size()-1;
	lf[x]=0;
	sz[x]=e[x].size()-1;
	for(int y:e[x]){
		if(y==fa[x])continue;
		fa[y]=x;
		dfs(y);
	}
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(cin>>n){
		for(int i=1;i<=n;++i)e[i].clear();
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1);
		queue<int> q;
		vector<int> a;
		int tot=0;
		for(int i=2;i<=n;++i)if(!d[i])q.push(i);
		// d[x] not leaf son of x
		while(!q.empty()){
			int x=q.front();
			int y=fa[x];
			q.pop();
			if(!lf[x]){
				if(y==1){
					++tot;
				}else{
					--d[y];
					++lf[y];
					if(!d[y])q.push(y);
				}
				continue;
			}
			a.push_back(lf[x]);

			if(y==1)continue;
			--d[y];
			if(!d[y])q.push(y);
		}
		int ans=0;
		for(int s:a)
			ans+=s-1;
		ans+=tot;
		if(!tot)++ans;
		cout<<ans<<"\n";
	}
}