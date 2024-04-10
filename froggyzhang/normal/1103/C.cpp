#include<bits/stdc++.h>
using namespace std;
#define N 250050
typedef long long ll;
int n,m,k,dfn[N],num,dep[N];
vector<int> G[N];
vector<vector<int> > ans;
void dfs(int u,int fa){
	static int st[N],top;
	dfn[u]=++num;
	dep[u]=dep[fa]+1;
	st[++top]=u;
	if(top>=(n-1)/k+1){
		cout<<"PATH\n";
		cout<<top<<'\n';
		for(int i=1;i<=top;++i){
			cout<<st[i]<<' ';
		}
		cout<<'\n';
		exit(0);
	}
	bool leaf=true;
	for(auto v:G[u]){
		if(!dfn[v]){
			dfs(v,u);leaf=false;
		}
	}
	if(leaf){
		vector<int> A,p;
		for(auto v:G[u]){
			if(v!=fa&&dfn[v]<dfn[u]){
				if((dep[u]-dep[v])%3!=2){
					for(int i=top;;--i){
						A.push_back(st[i]);
						if(st[i]==v)break;
					}
					break;
				}
				else{
					p.push_back(v);
				}
			}
		}
		if(A.empty()){
			if(dep[p[0]]>dep[p[1]])swap(p[0],p[1]);
			A.push_back(u);
			for(int i=1;i<=top;++i){
				if(dep[st[i]]>=dep[p[0]]&&dep[st[i]]<=dep[p[1]]){
					A.push_back(st[i]);	
				}
			}
		}
		ans.push_back(A);
		if(ans.size()==k){
			cout<<"CYCLES\n";
			for(auto v:ans){
				cout<<v.size()<<'\n';
				for(auto x:v){
					cout<<x<<' ';
				}
				cout<<'\n';
			}
			exit(0);
		}
	}
	--top;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	return 0;
}