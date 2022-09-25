#include<bits/stdc++.h>
using namespace std;
#define N 2020
const int mod=1e9+7;
typedef long long ll;
inline void Plus(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
int n;
char s[N];
void Read(int *a){
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='?')a[i]='?';
		else a[i]=(s[i]-'0')^1;
	}
}
int a[N],b[N];
int dp[N][N][2],g[N][N][2];
void Solve(){
	cin>>n;
	Read(a),Read(b);
	for(int i=0;i<=n;++i)
		for(int j=0;j<=i;++j)
			dp[i][j][0]=dp[i][j][1]=g[i][j][0]=g[i][j][1]=0;
	g[0][0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
			for(int k=0;k<2;++k){
				for(int x=0;x<2;++x){
					for(int y=0;y<2;++y){
						if(x==(a[i]^1)||y==(b[i]^1))continue;
						int tmp=(1LL*g[i-1][j][k]*j+dp[i-1][j][k])%mod;
						int tk=x,tj=j;
						if(j&&tk==k){
							tk^=1;
							if(tk==y)--tj;
						}
						else{
							if(tk^y)++tj;
						}
						Plus(dp[i][tj][tk],tmp);
						Plus(g[i][tj][tk],g[i-1][j][k]);
					}
				}
			}	
		}
	}
	cout<<(dp[n][0][0]+dp[n][0][1])%mod<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}