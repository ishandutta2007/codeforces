#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
const int M=1000000007;
int _,n,p[120];
ll ans,b[60][maxn/60];
void solve(){
	int n;scanf("%d",&n);
	int m=(n+60-1)/60;
	for (int i=0;i<60;i++)
		for (int j=0;j<m;j++)
			b[i][j]=0;
	for (int i=0;i<n;i++){
		ll x;scanf("%lld",&x);
		for (int j=0;j<60;j++){
			if ((x>>j)&1) b[j][i/60]|=1ll<<(i%60);
		}
	}
	ans=0;
	for (int i=0;i<60;i++)
	for (int j=0;j<60;j++){
        ll c1=0,c2=0,c3=0;
		for (int k=0;k<m;k++){
			c1+=__builtin_popcountll((~b[i][k])&b[j][k]);
			c2+=__builtin_popcountll(b[i][k]&(~b[j][k]));
			c3+=__builtin_popcountll(b[i][k]&b[j][k]);
		}
        (ans+=(c3*n+c1*(c2+c3))%M*(c1+c3)%M*p[i+j])%=M;
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&_);
	p[0]=1; for (int i=1;i<120;i++) p[i]=p[i-1]*2%M;
	while (_--) solve();
}