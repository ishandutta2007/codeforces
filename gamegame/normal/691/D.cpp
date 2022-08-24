#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int par[1000001];
int find(int x){
	if(par[x]!=x) par[x]=find(par[x]);
	return par[x];
}
void addlink(int x,int y){
	par[find(x)]=find(y);
}
vector<int>v[1000001];
int ptr[1000001];
int a[1000001];
int main(){
	ios::sync_with_stdio(false);
	int n,m,p,q;
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		par[i]=i;
	}
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=m ;i++){
		cin >> p >> q;
		addlink(p,q);
	}
	for(int i=n; i>=1 ;i--){
		v[find(i)].push_back(a[i]);
	}
	for(int i=1; i<=n ;i++){
		sort(v[i].begin(),v[i].end());
		ptr[i]=v[i].size()-1;
	}
	for(int i=1; i<=n ;i++){
		cout << v[par[i]][ptr[par[i]]] << ' ';
		ptr[par[i]]--;
	}
	
}