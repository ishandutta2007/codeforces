#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int par[200001];
int sz[200001];
bool d1[200001],d2[200001];
vector<int>v1,v2;
int find(int x){
	if(par[x]!=x) par[x]=find(par[x]);
	return par[x];
}
void join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return;
	sz[y]+=sz[x];
	par[x]=y;
}
void solve(){
	cin >> n >> m >> a >> b;
	for(int i=1; i<=n ;i++) par[i]=i,d1[i]=false,d2[i]=false,sz[i]=1;
	v1.clear();v2.clear();
	bool mg=false;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		if(v==a || v==b) swap(u,v);
		if(u!=a && u!=b){
			join(u,v);
		}
		else if(u==a && v==b || u==b && v==a) mg=true;
		else if(u==a) d1[v]=true;
		else d2[v]=true;
	}
	for(int i=1; i<=n ;i++) d1[find(i)]|=d1[i],d2[find(i)]|=d2[i];
	int c1=0,c2=0,c3=0;
	for(int i=1; i<=n ;i++){
		if(find(i)!=i || i==a || i==b) continue;
		//cout << i << ' ' << sz[i] << endl;
		if(d1[i] && d2[i]) c3+=sz[i];
		else if(d1[i]) c1+=sz[i];
		else c2+=sz[i];
	}
	cout << 1LL*c1*c2 << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}