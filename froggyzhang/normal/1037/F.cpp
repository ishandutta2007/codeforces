#include<bits/stdc++.h>
using namespace std;
#define N 10001000
const int mod=1e9+7;
typedef long long ll;
int n,k,a[N],L[N],R[N],ans;
inline int calc(int p){
	return 1LL*(p+p%k)*(p/k+1)/2%mod;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	--k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		L[i]=1,R[i]=n;
		ans=(ans-a[i])%mod;
	}
	for(int i=1;i<=n;++i){
		static int st[N],top;
		while(top&&a[i]>a[st[top]])--top;
		if(top)L[i]=st[top]+1;
		st[++top]=i;
	}
	for(int i=n;i>=1;--i){
		static int st[N],top;
		while(top&&a[i]>=a[st[top]])--top;
		if(top)R[i]=st[top]-1;
		st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		ans=(ans+1LL*(calc(R[i]-L[i]+1)-calc(i-L[i])-calc(R[i]-i))*a[i])%mod;
	}
	ans=(ans+mod)%mod;
	cout<<ans<<'\n';
	return 0;
}