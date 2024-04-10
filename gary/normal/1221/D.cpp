//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[300000+10][3];int n,a[300000+10];LL b[300000+10];
void solve(){
	scanf("%d",&n);
	rb(i,1,n)
		{
			scanf("%d %I64d",&a[i],&b[i]);
		}
	dp[1][0]=0;
	dp[1][1]=b[1];
	dp[1][2]=b[1]+b[1];
	rb(i,2,n){
		dp[i][0]=dp[i][1]=dp[i][2]=1000000000000000000+1;
		rb(j,0,2)
		{
			rb(k,0,2){
				if(a[i-1]+k!=a[i]+j){
					dp[i][j]=min(dp[i][j],dp[i-1][k]+j*b[i]);
				}
			}
		}
	} 
	printf("%I64d\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
}
int main(){
	int q;
	cin>>q;
	while(q--) solve();
	return 0;
}