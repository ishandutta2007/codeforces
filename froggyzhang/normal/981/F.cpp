#include<bits/stdc++.h>
using namespace std;
#define N 800020
typedef long long ll;
int n,L;
ll a[N],b[N];
bool check(ll x){
	int mx=-1e9;
	for(int i=n+1,j1=1,j2=1;i<=n+n+n;++i){
		while(j1<n<<2&&b[j1+1]<a[i]-x)++j1;
		while(j2<n<<2&&b[j2+1]<=a[i]+x)++j2;
		mx=max(mx,j1-i+1);
		if(mx+i-j2>0)return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>L;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=3*n;++i){
		a[i+n]=a[i]+L;
		b[i+n]=b[i]+L;
	}
	ll l=0,r=L+1,ans=L+1;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}