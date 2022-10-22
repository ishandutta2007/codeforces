//* AuThOr GaRyMr *//
//dp[i][j][k]->to the i-th pos. and set it j(j<=200),and if(k) then a[i-1]>a[i] else a[i-1]<a[i]
//ifk==2 a[i-1]==a[i]
//if(a[i]!=-1) dp[i][j][0]=dp[i-1][1][0]+dp[i-1][2][0]+......dp[i-1][j][0]& dp[i-1][1][1]+....dp[i-1][j][1]
//else dp[i][j][1]=dp[i-1][j+1][0]+......+dp[i-1][200][0]& dp[i-1][j+1][1]+....dp[i-1][200][1]
//
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[100000+10];
LL sum[2][202][3];
LL dp[2][205][3];
const int MOD=998244353;
int main(){
	int n;
	//n<+1e5;
//	cout<<"OK"<<endl;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
//	cout<<"OK"<<endl;
	int pre=0,now=1;
	if(a[1]!=-1){
		dp[pre][a[1]][0]=1;
		rb(j,a[1],200){
			sum[pre][j][0]=1;
		}
	}
	else{
		rb(j,1,200){
			dp[pre][j][0]=1;
			sum[pre][j][0]=sum[pre][j-1][0]+1;
		}
	}
	rb(i,2,n){
		rb(j,0,200){
			sum[now][j][0]=sum[now][j][1]=sum[now][j][2]=0;
			dp[now][j][0]=dp[now][j][1]=dp[now][j][2]=0;
		}
		if(a[i]!=-1){
			dp[now][a[i]][0]=sum[pre][a[i]-1][0]+sum[pre][a[i]-1][1]+sum[pre][a[i]-1][2];
			dp[now][a[i]][1]=(sum[pre][200][1]-sum[pre][a[i]][1]+MOD)%MOD;
			dp[now][a[i]][1]+=(sum[pre][200][2]-sum[pre][a[i]][2]+MOD)%MOD;
			dp[now][a[i]][1]%=MOD;
			dp[now][a[i]][2]=dp[pre][a[i]][1]+dp[pre][a[i]][2]+dp[pre][a[i]][0];
			rb(j,a[i],200){
				sum[now][j][1]=dp[now][a[i]][1];
				sum[now][j][0]=dp[now][a[i]][0];
				sum[now][j][2]=dp[now][a[i]][2];
				sum[now][j][1]%=MOD;
				sum[now][j][0]%=MOD;
				sum[now][j][2]%=MOD;
			}
		}
		else{
			rb(j,1,200){
				a[i]=j;
				dp[now][a[i]][0]=sum[pre][a[i]-1][0]+sum[pre][a[i]-1][1]+sum[pre][a[i]-1][2];
				dp[now][a[i]][1]=(sum[pre][200][1]-sum[pre][a[i]][1]+MOD)%MOD;
				dp[now][a[i]][1]+=(sum[pre][200][2]-sum[pre][a[i]][2]+MOD)%MOD;
				dp[now][a[i]][1]%=MOD;
				dp[now][a[i]][2]=dp[pre][a[i]][1]+dp[pre][a[i]][2]+dp[pre][a[i]][0];
			}
			rb(j,1,200){
				sum[now][j][0]=sum[now][j-1][0]+dp[now][j][0];
				sum[now][j][0]%=MOD;
				sum[now][j][1]=sum[now][j-1][1]+dp[now][j][1];
				sum[now][j][1]%=MOD;
				sum[now][j][2]=sum[now][j-1][2]+dp[now][j][2];
				sum[now][j][2]%=MOD;
			}
			a[i]=-1;
		}
		swap(now,pre);
	}
//	cout<<sum[2][200][2]<<endl;
//	cout<<dp[2][2][0]<<endl;
	LL res=0;
	if(a[n]==-1){
		rb(j,1,200){
//			cout<<dp[n][j][1]<<" "<<dp[n][j][2]<<endl;
			res+=dp[pre][j][1]+dp[pre][j][2];
			res%=MOD;
		}
	}
	else{
		res=dp[pre][a[n]][1]+dp[pre][a[n]][2];
		res%=MOD;
	}
	printf("%I64d\n",res);
	return 0;
}