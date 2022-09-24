#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m,jc[100005]={1},ny[100005]={1},ans=0;
ll C(ll x,ll y){
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
void Solve(){
	cin>>n>>m;
	int ans=2;
	for(int i=3;i<=n;i++)ans=(ans+1ll*C(n-1ll*(m-1)*(i-2),i-1)*Power(C(n,i-1),mod-2))%mod;
	cout<<ans<<'\n';
}
int main(){
	for(int i=1;i<=100000;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[100000]=Power(jc[100000],mod-2);
	for(int i=99999;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}