//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a1,a2,a3,dp[301][301][301],sum[301][301],sum2[301][301];
void solve(){
	rb(i,0,300)
		rb(j,0,300) sum[i][j]=sum2[i][j]=1;
	cin>>a1>>a2>>a3;
	if(a3>a2) swap(a3,a2);
	if(a2>a1) swap(a2,a1);
	if(a3>a2) swap(a3,a2);
	dp[0][0][0]=0;
	sum[0][0]=0;
	sum2[0][0]=1;
	rb(i,1,300) dp[i][0][0]=1,sum[i][0]&=1,sum2[i][0]=1;
	rb(i,1,a1)
	{
		rb(j,1,min(i,a2)){
			rb(k,0,min(j,a3)){
				dp[i][j][k]=sum[j][k]&sum[i][k]&sum[i][j]&sum2[i-k][j-k];
				dp[i][j][k]^=1;
				sum[i][j]&=dp[i][j][k];
				sum[i][k]&=dp[i][j][k];
				sum[j][k]&=dp[i][j][k];
				sum2[i-k][j-k]&=dp[i][j][k];
			}
		}
	}
	if(dp[a1][a2][a3]) puts("BitLGM");
	else puts("BitAryo");
}
int main(){
	int n;
	cin>>n;
	if(n==1) {
		int a1;
		cin>>a1;
		if(a1)
		puts("BitLGM");
		else 
		puts("BitAryo");
	}
	else{
		if(n==2){
			int dp[301][301]={0};
			int a1,a2;
			cin>>a1>>a2;
			if(a1<a2) swap(a1,a2);
			dp[0][0]=0;
			rb(i,1,300) dp[i][0]=1;
			rb(i,1,a1){
				rb(j,1,min(i,a2)){
					int OK=1;
					rb(k,1,i){
						int nex1,nex2;
						nex1=i-k,nex2=j;
						if(nex1<nex2) swap(nex1,nex2);
						OK&=dp[nex1][nex2];
					}
					rb(k,1,j){
						OK&=dp[i][j-k];
					}
					rb(k,1,j){ 
						OK&=dp[i-k][j-k];
					}
					dp[i][j]=OK^1;
				}
			}
			if(dp[a1][a2]) puts("BitLGM");
			else puts("BitAryo");
		}
		else{
			solve();
		}
	}
	return 0;
}