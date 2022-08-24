#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll s,t;
ll p[200001],c[200001];
ll g[400001];
ll h[400001];
ll pf[400001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> s >> t;
	for(int i=1; i<=n ;i++){
		cin >> p[i] >> c[i];
	}
	for(int i=1; i<=k ;i++){
		cin >> g[i];
	}
	g[k+1]=s;
	sort(g+1,g+k+1);
	for(int i=1; i<=k+1 ;i++){
		h[i]=g[i]-g[i-1];
	}
	k++;
	sort(h+1,h+k+1);
	for(int i=1; i<=k ;i++){
		pf[i]=pf[i-1]+h[i];
	}
	ll ans=1e18;
	for(int i=1; i<=n ;i++){
		//shorter than capacity /2
		//cout << h[k] << endl;
		if(h[k]>c[i]){
			continue;
		}
		int x=lower_bound(h+1,h+k+1,(c[i]+1)/2)-h-1;
		ll fast=pf[x]+(pf[k]-pf[x])*3-1*(k-x)*c[i];
	//	cout << fast << endl;
		if(fast<=t) ans=min(ans,p[i]);
	}
	if(ans==1e18) cout << "-1\n";
	else cout << ans << endl;
}