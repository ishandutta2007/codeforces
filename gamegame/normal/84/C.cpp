#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll x[10001],r[10001];
pair<ll,int>y[10001];
int ans[10001];
int cnt=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> x[i] >> r[i];
		y[i]={x[i]-r[i],i};
		ans[i]=-1;
	}
	sort(y+1,y+n+1);
	int m;cin >> m;
	for(int i=1; i<=m ;i++){
		ll u,v;cin >> u >> v;
		int z=lower_bound(y+1,y+n+1,pair<ll,int>{u,0})-y;
		z-=2;
		for(int j=0; j<2 ;j++){
			z++;
			if(z>n) break;
			if(z<=0) continue;
			int zz=y[z].second;
			if(ans[zz]!=-1) continue;
			if((x[zz]-u)*(x[zz]-u)+v*v<=r[zz]*r[zz]){
				ans[zz]=i;cnt++;
			}
		}
	}
	cout << cnt << endl;
	for(int i=1; i<=n ;i++) cout << ans[i] << ' ';
}