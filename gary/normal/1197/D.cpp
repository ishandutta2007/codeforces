//* AuThOr GaRyMr *//
//dp[i][j](i<=3e5&j<10)
//means the maximum cost in the arry to-> the position i-th
//and MOD m = j
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[300000+10][11];
LL n,m,k;
LL a[300000+10];
LL max_cost=0;
LL res=0;
int main(){
//	freopen("Gary.out","w",stdout);
	scanf("%I64d %I64d %I64d",&n,&m,&k);
	if(m==1){
		rb(i,1,n){
			LL ai;
			scanf("%I64d",&ai);
			max_cost+=ai-k;
			res=max(res,max_cost);
			max_cost=max((LL)(0),max_cost);
		}
		printf("%I64d\n",res);
		return 0;
	}
	rb(i,1,n) scanf("%I64d",&a[i]);
//	cout<<dp[0][9]<<endl;
	memset(dp,-0x3f,sizeof(dp));
	rb(i,0,n) dp[i][0]=0;
	rb(i,1,n){
		rb(j,0,m-1){
			if(i<j) break;
			if(j==1){
				dp[i][j]=dp[i-1][0]-k+a[i];
			}
			else{
				if(j==0){
					dp[i][j]=max(dp[i-1][m-1]+a[i],dp[i][j]);
				} 
				else
				dp[i][j]=dp[i-1][j-1]+a[i];
			}
//			cout<<i<<','<<j<<":"<<dp[i][j]<<"    ";
			max_cost=max(max_cost,dp[i][j]);
		}
//		cout<<endl;
	}
	printf("%I64d\n",max_cost);
	return 0;
}