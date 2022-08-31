#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
ll x[300001],y[300001];
pair<ll,int>a[300001];
ll sumx,sumy,prex,prey;
ll ans[300001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> x[i] >> y[i];
		sumx+=x[i];
		sumy+=y[i];
		a[i]={x[i]-y[i],i};
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n ;i++){
		int cur=a[i].se;
		ans[cur]=y[cur]*(i-1)+x[cur]*(n-i)+prex+sumy-y[cur]-prey;
		prex+=x[cur];
		prey+=y[cur];
	}
	for(int i=1; i<=m ;i++){
		int u,v;
		cin >> u >> v;
		ans[u]-=min(x[u]+y[v],x[v]+y[u]);
		ans[v]-=min(x[u]+y[v],x[v]+y[u]);
	}
	for(int i=1; i<=n ;i++) cout << ans[i] << ' ';
	cout << endl;
}