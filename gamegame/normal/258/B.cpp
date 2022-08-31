#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2001;
const ll mod=1e9+7;
ll n;
ll dp[20][11],dp2[20][11];
ll f[10];
ll dp3[10][7][10];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
ll C[7][7];
int main(){
	ios::sync_with_stdio(false);
	C[0][0]=1;
	for(int j=1; j<=6 ;j++){
		C[j][0]=1;
		for(int k=1; k<=j ;k++){
			C[j][k]=C[j-1][k-1]+C[j-1][k];
		}
	}
	string m;
	cin >> m;
	reverse(m.begin(),m.end());
	int k=m.size();
	dp[k][0]=1;
	for(int i=k-1; i>=0 ;i--){
		for(int j=0; j<10 ;j++){
			for(int z=0; z<10 ;z++){//new digit
				if(m[i]-'0'>z){
					dp2[i][j+(z==4 || z==7)]+=dp[i+1][j];
					dp2[i][j+(z==4 || z==7)]+=dp2[i+1][j];
				}
				else if(m[i]-'0'==z){
					dp[i][j+(z==4 || z==7)]+=dp[i+1][j];
					dp2[i][j+(z==4 || z==7)]+=dp2[i+1][j];
				}
				else{
					dp2[i][j+(z==4 || z==7)]+=dp2[i+1][j];
				}
			}
		}
	}
	for(int j=0; j<10 ;j++){
		f[j]+=dp[0][j];
		f[j]+=dp2[0][j];
	}
	f[0]--;
	ll ans=0;
	dp3[0][0][0]=1;
	for(int i=1; i<10 ;i++){
		for(int j=0; j<7 ;j++){
			for(int k=0; k<10 ;k++){
				for(int l=0; j+l<=6 ;l++){
					if(k+l*(i-1)>=10) continue;
					int nj=j+l;
					int nk=k+l*(i-1);
					ll fun=1;
					for(int t=0; t<l ;t++) fun=fun*(f[i-1]+mod-t)%mod;
					fun=fun*C[6-j][l]%mod;
					dp3[i][nj][nk]=(dp3[i][nj][nk]+dp3[i-1][j][k]*fun)%mod;
				}
			}
		}
		ll ways=0;
		for(int k=0; k<i ;k++){
			ways=ways+dp3[i][6][k];
			ways%=mod;
		}
		ans=(ans+ways*f[i])%mod;
	}
	cout << ans << '\n';
}