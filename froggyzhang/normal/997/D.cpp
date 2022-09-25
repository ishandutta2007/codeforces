#include<bits/stdc++.h>
using namespace std;
#define N 4004
#define M 80
const int mod=998244353;
typedef long long ll;
int K,n1,n2,C[M][M],ans;
inline void Plus(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);	
}
struct Tree{
	int n,x[N],y[N];
public:
	int dp[2][N],g[M];
	void init(int _n){
		n=_n;
		for(int i=1;i<n;++i){
			cin>>x[i]>>y[i];
		}
		g[0]=n;
		for(int s=1;s<=n;++s){
			memset(dp[0],0,sizeof(dp[0]));
			dp[0][s]=1;
			for(int j=1;j<=K;++j){
				memset(dp[j&1],0,sizeof(dp[j&1]));
				for(int i=1;i<n;++i){
					Plus(dp[j&1][x[i]],dp[j&1^1][y[i]]);
					Plus(dp[j&1][y[i]],dp[j&1^1][x[i]]);
				}
				Plus(g[j],dp[j&1][s]);
			}
		}
	}
}T1,T2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n1>>n2>>K;
	T1.init(n1);
	T2.init(n2);
	for(int i=0;i<=K;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for(int k=0;k<=K;k+=2){
		ans=(ans+1LL*T1.g[k]*T2.g[K-k]%mod*C[K][k])%mod;	
	}
	cout<<ans<<'\n';
	return 0;
}