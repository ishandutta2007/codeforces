#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define fi first
#define se second
int n,m,k;
ll fh[3601];//number of ways to take k horizontal
ll fv[3601];
bool th[3601],tv[3601];
int sth,stv=0;
ll dp[3][3601];
ll f[3601],inf[3601];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
void tmw(){
	const int iu=3600;
	f[0]=inf[0]=1;
	for(int i=1; i<=iu ;i++){
		f[i]=i*f[i-1]%mod;
		inf[i]=pw(f[i],mod-2);
	}
}
ll c(int x,int y){
	if(x<y || x<0 || y<0) return 0;
	return f[x]*inf[y]%mod*inf[x-y]%mod;
}
int main(){
	ios::sync_with_stdio(false);tmw();
	cin >> n >> m >> k;
	for(int i=1; i<=k ;i++){
		int w,x,y,z;cin >> w >> x >> y >> z;
		th[w]=th[y]=true;
		tv[x]=tv[z]=true;
	}
	dp[0][0]=1;
	for(int i=1; i<=m ;i++){
		int c=i%3;
		for(int j=0; j<=m/2 ;j++){
			dp[c][j]=dp[(c+2)%3][j];
			if(j!=0 && !tv[i] && !tv[i-1]) dp[c][j]=(dp[c][j]+dp[(c+1)%3][j-1])%mod; 
		}
	}
	for(int i=0; i<=m/2 ;i++) fh[i]=dp[m%3][i];
	for(int i=0; i<=n/2 ;i++) dp[0][i]=dp[1][i]=dp[2][i]=0;
	dp[0][0]=1;
	for(int i=1; i<=n ;i++){
		int c=i%3;
		for(int j=0; j<=n/2 ;j++){
			dp[c][j]=dp[(c+2)%3][j];
			if(j!=0 && !th[i] && !th[i-1]) dp[c][j]=(dp[c][j]+dp[(c+1)%3][j-1])%mod; 
		}
	}
	for(int i=0; i<=n/2 ;i++) fv[i]=dp[n%3][i];
	for(int i=1; i<=n ;i++) sth+=th[i];
	for(int i=1; i<=m ;i++) stv+=tv[i];
	sth=n-sth;stv=m-stv;
	ll ans=0;
	for(int i=0; i<=n/2 ;i++){
		for(int j=0; j<=m/2 ;j++){
			ll w=fh[j]*fv[i]%mod;
			int rh=sth-i*2;
			int rv=stv-j*2;
			w=w*c(rh,j)%mod*c(rv,i)%mod*f[i]%mod*f[j]%mod;
			ans=(ans+w)%mod;
			//cout << i << ' ' << j << ' ' << rh << ' ' << rv << ' ' << w << endl;
		}
	}
	cout << ans << '\n';
}