#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int n,m;
int c[100001];
int par[100001];
int mini[100001];
bool vis[100001];
int find(int x){
	if(par[x]!=x) par[x]=find(par[x]);
	return par[x];
}
void add(int x,int y){
	int u=find(x),v=find(y);
	if(u!=v){
		par[u]=v;
		mini[v]=min(mini[v],mini[u]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		par[i]=i;
		cin >> c[i];
		mini[i]=c[i];
	}
	for(int i=1; i<=m ;i++){
		int p,q;
		cin >> p >> q;
		add(p,q);
	}
	long long ans=0;
	for(int i=1 ;i<=n ;i++){
		int num=find(i);
		if(!vis[num]){
			ans+=mini[num];
			vis[num]=true;
		}
		
	}
	cout << ans << endl;
}