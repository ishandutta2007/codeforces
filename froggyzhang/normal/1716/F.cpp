#include<bits/stdc++.h>
using namespace std;
#define N 2005
typedef long long ll;
const int mod=998244353;
int n,m,k,S[N][N];
void init(int n){
	S[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			S[i][j]=(S[i-1][j-1]+1LL*j*S[i-1][j])%mod;
		}
	}
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void Solve(){
	cin>>n>>m>>k;
	int ans=0;
	int x=(m+1)/2;
	int invm=qpow(m,mod-2);
	for(int i=1,tmp=1LL*x*n%mod*qpow(m,n-1)%mod;i<=min(n,k);++i){
		ans=(ans+1LL*S[k][i]*tmp)%mod;
		tmp=1LL*tmp*x%mod*invm%mod*(n-i)%mod;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(2000);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}
//qwq