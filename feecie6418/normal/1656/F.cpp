#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[200005];
ll b[200005];
ll Calc(ll x){
	ll sum=0;
	for(int i=1;i<=n;i++)b[i]=a[i]+x;
	if(b[n]<=0){
		for(int i=1;i<n;i++)sum+=1ll*b[i]*b[n];
		return sum-x*x*(n-1);
	}
	if(b[1]>=0){
		for(int i=2;i<=n;i++)sum+=1ll*b[1]*b[i];
		return sum-x*x*(n-1);
	}
	for(int i=1;i<n;i++)if(b[i]<=0)sum+=1ll*b[n]*b[i];else sum+=1ll*b[1]*b[i];
	return sum-x*x*(n-1);
}
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ll s1=0,s2=0;
	for(int i=1;i<=n;i++){
		if(i!=1)s1+=a[1]+a[i];
		if(i!=n)s2+=a[i]+a[n];
	}
	if(s1>0||s2<0)return puts("INF"),void();
	ll l=-1e6,r=1e6;
	while(r-l>5){
		ll l1=(l+l+r)/3,l2=(l+r+r)/3;
		if(Calc(l1)>Calc(l2))r=l2-1;
		else l=l1+1;
	}
	ll mx=-1e18;
	for(int i=l;i<=r;i++)mx=max(mx,Calc(i));
	cout<<mx<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}