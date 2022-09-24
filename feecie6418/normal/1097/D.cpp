#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
ll n,K;
int f[10005][60],inv[60];
void upd(int &x,int y){
	x=(x+y)%mod;
}
int F(int t,int p){
	memset(f,0,sizeof(f));
	f[0][t]=1;
	for(int i=0;i<K;i++){
		for(int j=0;j<=t;j++){
			for(int k=0;k<=j;k++){
				upd(f[i+1][k],1ll*f[i][j]*inv[j+1]%mod);
			}
		}
	}
	int ans=0;
	for(int i=0,w=1;i<=t;i++,w=1ll*w*p%mod)ans=(ans+1ll*w*f[K][i])%mod;
	return ans;
}
int main(){
	inv[1]=1;
	for(int i=2;i<=58;i++)inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	cin>>n>>K;
	int ans=1;
	for(ll i=2;i*i<=n;i++){
		if(n%i)continue;
		int cnt=0;
		while(n%i==0)n/=i,cnt++;
		ans=1ll*ans*F(cnt,i%mod)%mod;
	}
	if(n>1)ans=1ll*ans*F(1,n%mod)%mod;
	cout<<ans;
}