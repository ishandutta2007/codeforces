#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
ll c[N];
vector<int>adj[N];
bool ok;
ll ans=0;
vector<int>v;
void dfs(int id){
	c[id]=a[id];
	for(auto x:adj[id]){
		dfs(x);
		c[id]+=max(c[x],0LL);
	}
	ans+=c[id];
}
void dfs2(int id){
	for(auto x:adj[id]){
		if(c[x]>0) dfs2(x);
	}
	v.push_back(id);
	for(auto x:adj[id]){
		if(c[x]<=0) dfs2(x);
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		if(b[i]!=-1) adj[b[i]].push_back(i);
	}
	for(int i=1; i<=n ;i++){
		if(b[i]==-1) dfs(i);
	}
	for(int i=1; i<=n ;i++){
		if(b[i]==-1) dfs2(i);
	}
	cout << ans << '\n';
	for(auto c:v) cout << c << ' ';
	cout << endl;
}