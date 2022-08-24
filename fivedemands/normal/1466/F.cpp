#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
const int N=2e6+1;
const int iu=60;
ll n,m;
int p[N];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> m >> n;
	for(int i=1; i<=n ;i++) p[i]=i;
	ll ans=1;
	vector<int>vans;
	for(int i=1; i<=m ;i++){
		int t,u,v;cin >> t >> u;
		if(t==1) v=0;
		else cin >> v;
		u=find(u);v=find(v);
		if(u==v) continue;
		else{
			ans=ans*2%mod;
			p[u]=v;
			vans.push_back(i);
		}
	}
	cout << ans << ' '<< vans.size() << '\n';
	for(auto c:vans) cout << c << " ";
	cout << endl;
}