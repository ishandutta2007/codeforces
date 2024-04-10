#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const ll N=5001;
int z;
int c[N][N];
int w[N/2][N/2];
int pw[N/2][N/2];
ll ans=0;
void solve(int n,int m,int k){//blue disconnected
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			ll r=c[i-1+m-j][m-j];
			ll l=c[i+j-1][j-1];
			w[i][j]=l*r%mod;
			pw[i][j]=(pw[i][j-1]+w[i][j])%mod;
			//cout << w[i][j] << ' ';
		}
	//	cout << endl;
	}
	for(int i=1; i<n ;i++){
		for(int j=1; j<m ;j++){
			ans+=1LL*w[i][j]*pw[n-i][m-j];
			if(k==1){
				ans-=1LL*w[i][j]*w[n-i][m-j];
			}
			ans=(ans%mod+mod)%mod;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m;
	cin >> n >> m;z=n+m;
	c[0][0]=1;
	for(int i=1; i<=z ;i++){
		c[i][0]=1;
		for(int j=1; j<=i ;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	solve(n,m,1);
	solve(m,n,0);
	ans=ans*2%mod;
	cout << ans << '\n';
}