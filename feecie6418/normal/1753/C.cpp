#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int jc[200005],ny[200005];
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int f[200005],n,a[200005],b[200005];
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=(a[i]!=b[i]);
	cnt/=2;
	int ans=0;
	for(int i=1;i<=cnt;i++)ans=(ans+1ll*Power(i,mod-2)*Power(i,mod-2))%mod;
	cout<<1ll*ans*n%mod*(n-1)%mod*(mod+1)/2%mod<<'\n'; 
}
int main(){
	for(int i=1;i<=200000;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[200000]=Power(jc[200000],mod-2);
	for(int i=200000-1;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}