#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
const ll inf=1e9;
int n,a[500005];
ll s[500005],premx[500005],sufmn[500005];
ll S(ll l,ll x){
	int pos=lower_bound(a+1,a+n+1,x,greater<int>())-a;
	// <=x 
	if(pos>l)return x*l;
	return x*(pos-1)+s[l]-s[pos-1]; 
}
ll Sum(ll l,ll r,ll x){
	if(l>r)return 0;
	// [l,r]  min(a[i],x) 
	return S(r,x)-S(l-1,x); 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll t=s[i]-1ll*i*(i-1)-Sum(i+1,n,i);
		if(i<t)premx[i]=inf;
		else premx[i]=t;
		premx[i]=max(premx[i],premx[i-1]);
	}
	sufmn[n+1]=inf;
	for(int i=n;i>=0;i--){
		ll t=1ll*i*(i+1)+Sum(i+1,n,i+1)-s[i];
		sufmn[i]=min(sufmn[i+1],t);
	}
	a[0]=n+1;
	ll ansL=inf,ansR=0;
	for(int i=0;i<=n;i++){
		ll r=a[i]-1,l=a[i+1];
		if(l>r)continue;
		l=max(l,premx[i]);
		r=min(r,sufmn[i]);
		if(l<=r)ansL=min(ansL,l),ansR=max(ansR,r);
		// i+1  
	}
	int cnt=0;
	for(int i=ansL;i<=ansR;i++){
		if(i%2==s[n]%2)cnt++,cout<<i<<' ';
	}
	if(!cnt)cout<<-1;
}