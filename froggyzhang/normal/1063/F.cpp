#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
const int mod=7e6+7;
const int base=233;
bitset<mod> ok;
bitset<N> dp[1001];
int n,m,ans,h[N];
char s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>(s+1);
	reverse(s+1,s+n+1);
	for(int i=1;i<=n;++i){
		h[i]=s[i];
		dp[1][i]=1;
	}
	m=sqrt(n<<1);
	for(int j=2;j<=m;++j){
		for(int i=1;i<=n-j;++i){
			if(dp[j-1][i])ok[h[i]]=1;
			if(ok[h[i+j-1]]|ok[h[i+j]])dp[j][i+j]=1;
		}
		if(dp[j].none()){
			cout<<j-1<<'\n';
			return 0;
		}
		for(int i=n;i>=1;--i){
			h[i]=(1LL*h[i-1]*base+s[i])%mod;
		}
		ok.reset();
	}
	cout<<m<<'\n';
	return 0;
}