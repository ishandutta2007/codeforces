#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,a[N];
bool check(int x){
	static ll b[N];
	for(int i=1;i<=n;++i)b[i]=0;
	for(int i=n;i>=1;--i){
		if(a[i]+b[i]<x)return false;
		if(i>=3){
			ll t=min((ll)a[i]/3,(a[i]+b[i]-x)/3);
			b[i-1]+=t,b[i-2]+=t<<1;
		}
	}
	return true;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int l=1,r=1e9+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid;
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