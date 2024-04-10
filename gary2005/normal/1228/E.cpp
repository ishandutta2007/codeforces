/*
IDEA:
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MOD=1e9+7;
int n,k; 
LL c[300][300],my_pow[300],my_pow2[300],dp[300][300];
int main(){
	fastio;
	cin>>n>>k;
	c[0][0]=1;
	rb(i,1,300-1)
		c[0][i]=1;
	my_pow[0]=my_pow2[0]=1;
	rb(i,1,300-1)
		my_pow[i]=my_pow[i-1]*(k),my_pow[i]%=MOD,my_pow2[i]=my_pow2[i-1]*(k-1),my_pow2[i]%=MOD; 
	rb(i,1,300-1)
		rb(j,1,300-1){
			c[i][j]=c[i-1][j-1]+c[i][j-1],c[i][j]%=MOD;
		}
	dp[1][n]=1;
	rb(i,1,n)
		rb(j,0,n){
			dp[i][j]%=MOD;
			rb(k,0,j){//k 
				dp[i+1][j-k]+=((((dp[i][j]*c[k][j]%MOD)*my_pow2[j-k]%MOD)*(my_pow[n-j]-(k==0? my_pow2[n-j]:0)+MOD))%MOD),dp[i+1][j-k]%=MOD;
			}		
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	cout<<dp[n+1][0]<<endl;
	return 0;
}