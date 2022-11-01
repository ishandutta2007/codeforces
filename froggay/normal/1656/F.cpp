#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=2e18;
int n;
ll a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll k=0,b=0;
	for(int i=2;i<=n;++i){
		k+=a[1]+a[i];
		b+=a[1]*a[i];
	}
	ll ans=-inf;
	for(int i=1;i<n;++i){
		if(i>1){
			k-=a[1]+a[i],k+=a[n]+a[i];
			b-=a[1]*a[i],b+=a[n]*a[i];
		}
		if(i==1&&k>0)ans=inf;
		if(i==n-1&&k<0)ans=inf;
		ans=max(ans,max(-k*a[i],-k*a[i+1])+b);
	}
	if(ans==inf)cout<<"INF\n";
	else cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}