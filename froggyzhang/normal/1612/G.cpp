#include<bits/stdc++.h>
using namespace std;
#define N 2000020
const int B=1e6;
const int mod=1e9+7;
typedef long long ll;
int n,a[N],fac[N],d[N];
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	init(n);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		d[B-(a[i]-1)]++;
  		d[B+(a[i]-1)+2]--;
	}
	int ans1=0,ans2=1,zz=1;
	for(int i=1;i<=B<<1;++i){
		d[i]+=d[i-2];
		if(d[i]){
			ans1=(ans1+1LL*d[i]*(2*zz+d[i]-2)/2%mod*(i-B))%mod;
			ans2=1LL*ans2*fac[d[i]]%mod;
			zz=(zz+d[i])%mod;
		}	
	}
	ans1=(ans1+mod)%mod;
	cout<<ans1<<' '<<ans2<<'\n';
	return 0;
}