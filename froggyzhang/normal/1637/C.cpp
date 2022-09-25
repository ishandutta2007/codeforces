#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	bool ok=false;
	for(int i=2;i<n;++i){
		ans+=(a[i]+1)/2;
		if(a[i]%2==0)ok=true;
		if(a[i]>=2&&n>=4)ok=true;
	}
	if(!ok)ans=-1;
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