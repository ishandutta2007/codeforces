#include<bits/stdc++.h>
using namespace std;
#define N 3030
typedef long long ll;
int n,a[N];
ll s[N],b[N],len,cnt[N];
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		if(i%2==1)a[i]=-a[i];
		s[i+1]=s[i]+a[i];
	}
	for(int i=0;i<n;i+=2){
		ll mn=1e18;
		for(int j=i+1;j<n;j+=2){
			ll l=max(s[i],s[j+1]),r=min(s[i+1],s[j]);
			r=min(r,mn);
			ans+=max(r-l+1,0LL);
			ans-=(j==i+1);
			mn=min(mn,s[j+1]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}