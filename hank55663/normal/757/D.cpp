#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define N 100005
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359
typedef long long LL	;
using namespace std;
const int mod = 1e9+7;
unsigned int dp[77][1<<20];
int main(){
	int n;
	scanf("%d",&n);
	char c[80];
	scanf("%s",c);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<=n;i++)
	dp[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		int temp=1,sum=0;
		for(int j=i-1;j>=0;j--){
			if(c[j]=='1'&&j<i-7)
			break;
			sum+=temp*(c[j]-'0');
			temp*=2;
			if(sum<=20&&sum!=0)
			for(int k=0;k<(1<<20);k++){
			//	printf("0 %d %d",k,sum);
				//printf("%d %d %d\n",k,sum,k&(1<<(sum-1)));
				dp[i][k|(1<<(sum-1))]+=dp[j][k];
				dp[i][k|(1<<(sum-1))]%=mod;
			//	printf("1 %d\n",k);
			}
			if(sum>20)
			break;
	//		printf("%d %d\n",i,sum);
		}
	}
	unsigned int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=2;j<=(1<<20);j<<=1)
		ans+=dp[i][j-1],ans%=mod;//printf("%d %d %d\n",i,j-1,dp[i][j-1]);
	printf("%u\n",ans);
}