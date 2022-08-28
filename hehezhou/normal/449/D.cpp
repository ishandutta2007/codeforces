#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n,a[1000010],ans,g[30];
ll power(ll x){
	ll res=2,ans=1;
	for(;x;x>>=1,res=res*res%mod)if(x&1)ans=ans*res%mod;
	return ans;
}
int main(){
	scanf("%lld",&n);
	for(ll x;n--;)scanf("%lld",&x),a[x]++;
	for(int j=0;(1<<j)<=1000000;j++)
		for(int i=0;i<=1000000;i++)
			if(i&(1<<j))a[i^(1<<j)]+=a[i];
	for(int i=0,l=0;i<=1000000;i++,l=0){
		for(int k=i;k;k-=(k&(-k)))l++;
		(g[l]+=power(a[i])-1)%=mod;
	}
	for(int i=0;i<=25;i++)ans=ans+(i%2?-1:1)*g[i];
	return cout<<(ans%mod+mod)%mod,0;
}