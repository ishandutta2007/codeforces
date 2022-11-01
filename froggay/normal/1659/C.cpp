#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,A,B,a[N];
ll suf[N];
void Solve(){
	cin>>n>>A>>B;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	suf[n+1]=0;
	for(int i=n;i>=1;--i){
		suf[i]=suf[i+1]+a[i];
	}
	ll ans=1e18;
	ll now=0;
	for(int i=0;i<=n;++i){
		ans=min(ans,now+B*(suf[i+1]-1LL*(n-i)*a[i]));
		now+=1LL*(A+B)*(a[i+1]-a[i]);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}