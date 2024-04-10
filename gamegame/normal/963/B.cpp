#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>c[200001];
int s[200001];
bool vis[200001];
void dfs(int id){
	s[id]=1;
	vis[id]=true;
	for(auto i:c[id]){
		if(vis[i]) continue;
		dfs(i);
		s[id]+=s[i];
	}
}
void solve(int id){
	for(auto i:c[id]) if(s[i]%2==0) solve(i);
	cout << id << '\n';
	for(auto i:c[id]) if(s[i]%2==1) solve(i);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	if(n%2==0){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int rt;
	for(int i=1; i<=n ;i++){
		int p;
		cin >> p;
		if(p==0) rt=i;
		else c[p].push_back(i);
	}
	dfs(rt);
	solve(rt);
}