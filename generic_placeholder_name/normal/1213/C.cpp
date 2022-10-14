#include <bits/stdc++.h>

#define ll long long

using namespace std;
int main(){
	int t; scanf("%d", &t); for(int l=1; l<=t; l++) {
	ll n, m, end[9], sum=0, ans=0; cin>>n>>m; end[0]=0; for(int i=1; i<=9; i++) {end[i]=(m%10+end[i-1])%10; sum+=end[i];}
	ans=(n/(10*m))*sum;
	for (ll i=(10*m)*(n/(10*m))+m; i<=n; i+=m) {
		ans+=end[(i/m)%10];
	}
	cout<<ans<<endl;
}}