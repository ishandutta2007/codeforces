#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m;
ll a[200005];
void Solve(){
	scanf("%d%d",&n,&m);
	ll sum=0;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum+=a[i],a[i]-=n-i;
	sort(a+1,a+n+1,[](ll x,ll y){return x>y;});
	ll ans=sum;
	for(int i=1;i<=m;i++){
		sum-=a[i];
		ans=min(ans,sum-1ll*i*(i-1)/2);
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}