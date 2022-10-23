#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,a[1000005],s[1000005],pw2[1000005];
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
void Solve(){
	scanf("%d",&n);
	for(int i=n-1;i>=n/2;i--){
		a[i]=pw2[max(0,n-i-2)];
		s[i]=(s[i+1]+a[i])%mod;
	}
	for(int i=n/2-1;i>=1;i--){
		a[i]=(s[i+1]-s[i+i+1]+mod)%mod;
		s[i]=(s[i+1]+a[i])%mod;
	}
	for(int i=0;i<n;i++)a[i]=1ll*a[i]*pw2[(i+3)/2]%mod;
	//for(int i=0;i<n;i++)cout<<a[i]<<' ';
	int inv=Power(pw2[n],mod-2);
	for(int i=0;i<n;i++)cout<<1ll*a[i]*inv%mod<<'\n';
	for(int i=0;i<n;i++)a[i]=s[i]=0;
}
int main(){
	pw2[0]=1;
	for(int i=1;i<=1000000;i++)pw2[i]=1ll*pw2[i-1]*2%mod;
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}