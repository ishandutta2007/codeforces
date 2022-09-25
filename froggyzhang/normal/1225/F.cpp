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
int n,f[N],dep[N];
unordered_set<int> G[N];
vector<int> ans;
void dfs(int u){
	vector<int> son;
	for(auto v:G[u]){
		son.push_back(v);
	}	
	sort(son.begin(),son.end(),[&](int i,int j){return dep[i]>dep[j];});
	for(auto x:son)dep[x]=1145142333;
	for(int i=0;i<(int)son.size()-1;++i){
		int x=son[i],y=son[i+1];
		G[u].erase(x);
		G[y].insert(x);
		ans.push_back(x);
	}
	if(!son.empty())dfs(son.back());
}
int main(){
	n=read();
	for(int i=2;i<=n;++i){
		f[i]=read()+1;
		G[f[i]].insert(i);
	}
	for(int i=1;i<=n;++i)dep[i]=dep[f[i]]+1;
	for(int i=n;i>=2;--i){
		dep[f[i]]=max(dep[f[i]],dep[i]);
	}
	dfs(1);
	for(int u=1;;u=(*G[u].begin())){
		printf("%d ",u-1);
		if(G[u].empty())break;
	}
	reverse(ans.begin(),ans.end());
	printf("\n%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",x-1);
	}
	return 0;
}