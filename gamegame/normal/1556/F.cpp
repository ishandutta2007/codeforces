#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n;
ll a[1<<14];
int pop[1<<14];
ll pd[1<<14],tot[1<<14];
ll sdp[15][1<<14];
ll scl[15][1<<14];
ll ans[1<<14];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=0; i<n ;i++) cin >> a[i];
	pd[0]=1;tot[0]=1;
	for(int i=1; i<(1<<n) ;i++){
		pop[i]=pop[i^(i&-i)]+1;
		ll cur=1;
		for(int j=0; j<n ;j++){
			if((i>>j)&1){
				pd[i]=pd[i^(1<<j)]*a[j]%mod;
				cur=tot[i^(1<<j)];
				for(int k=j+1; k<n ;k++){
					if((i>>k)&1) cur=cur*(a[j]+a[k])%mod;
				}
				tot[i]=cur;
				break;
			}
		}
		scl[pop[i]][i]=tot[i];
	}
	for(int i=1; i<=n ;i++){
		for(int j=0; j<n ;j++){
			for(int k=0; k<(1<<n) ;k++){
				if((k>>j)&1) scl[i][k]=(scl[i][k]+scl[i][k^(1<<j)])%mod;
			}
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<i ;j++){
			for(int p=0; p<n ;p++){
				for(int k=0; k<(1<<n) ;k++){
					if((k>>p)&1) sdp[j][k]=(sdp[j][k]+mod-sdp[j][k^(1<<p)])%mod;
				}
			}
			for(int k=0; k<(1<<n) ;k++) if(pop[k]==j) sdp[j][k]=sdp[j][k]*pd[k]%mod;
			for(int p=0; p<n ;p++){
				for(int k=0; k<(1<<n) ;k++){
					if((k>>p)&1) sdp[j][k]=(sdp[j][k]+sdp[j][k^(1<<p)])%mod;
				}
			}
		}
		for(int j=0; j<(1<<n) ;j++){
			for(int k=1; k<i ;k++){
				sdp[i][j]=(sdp[i][j]+sdp[k][j]*scl[i-k][j])%mod;
			}
		}
		for(int j=0; j<n ;j++){
			for(int k=0; k<(1<<n) ;k++){
				if((k>>j)&1) sdp[i][k]=(sdp[i][k]+mod-sdp[i][k^(1<<j)])%mod;
			}
		}
		for(int j=0; j<(1<<n) ;j++){
			if(pop[j]!=i) continue;
			sdp[i][j]=(tot[j]+mod-sdp[i][j])%mod;
			ans[j]=sdp[i][j];
		}
		for(int j=0; j<n ;j++){
			for(int k=0; k<(1<<n) ;k++){
				if((k>>j)&1) sdp[i][k]=(sdp[i][k]+sdp[i][k^(1<<j)])%mod;
			}
		}
	}
	ll res=0;
	int king=(1<<n)-1;
	for(int i=1; i<(1<<n) ;i++){
		ll cur=ans[i]*tot[king^i]%mod;
		for(int j=0; j<n-pop[i] ;j++) cur=cur*pd[i]%mod;
		res=(res+cur*pop[i])%mod;
	}
	res=res*pw(tot[king],mod-2)%mod;
	cout << res << '\n';
}