#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
int p[N];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
void join(int x,int y){
	x=find(x);y=find(y);
	p[x]=y;
}
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		p[i]=i;
		a[i]=0;b[i]=0;
	}
	int ans=0;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		if(u==v) ans-=2;
		join(u,v);
		b[u]=b[v]=1;
	}
	int duh=0;
	for(int i=1; i<=n ;i++) if(b[i]) a[find(i)]=1;
	
	for(int i=1; i<=n ;i++){
		ans+=a[i]-b[i];
	}
	cout << ans+m+m << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}