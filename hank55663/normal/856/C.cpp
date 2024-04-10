#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
int dp1[2005][2005][11];
int dp2[2005][2005][11];
int mod =998244353;
LL f_pow(int a,int b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
LL fra[2005];
LL C(int a,int b){
	return fra[a]*f_pow(fra[b],mod-2)%mod*f_pow(fra[a-b],mod-2)%mod;
}
int main(){
	int t;
	scanf("%d",&t);
	fra[0]=1;
	for(int i=1;i<2005;i++)
	fra[i]=fra[i-1]*i%mod;
	while(t--){	
		int num1=0,num2=0;
		dp2[0][0][0]=1;
		dp1[0][0][0]=1;
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			int sum=0;
			int len=0;
			while(a){
				sum=a%10-sum;
				len++;
				a/=10;
			}
			sum%=11;
			if(len%2==0){
				for(int j=0;j<=num2;j++){
					for(int k=0;k<11;k++){
						dp2[num2+1][j+1][((k+sum)%11+11)%11]+=dp2[num2][j][k];
						dp2[num2+1][j+1][((k+sum)%11+11)%11]%=mod;
						dp2[num2+1][j][((k-sum)%11+11)%11]+=dp2[num2][j][k];
						dp2[num2+1][j][((k-sum)%11+11)%11]%=mod;
					}
				}
				num2++;
			}
			else{
				for(int j=0;j<=num1;j++){
					for(int k=0;k<11;k++){
						dp1[num1+1][j+1][((k+sum)%11+11)%11]+=dp1[num1][j][k];
						dp1[num1+1][j+1][((k+sum)%11+11)%11]%=mod;
						dp1[num1+1][j][((k-sum)%11+11)%11]+=dp1[num1][j][k];
						dp1[num1+1][j][((k-sum)%11+11)%11]%=mod;
					}
				}
				num1++;
			}
		}
		if(num1==0){
			printf("%I64d\n",(LL)dp2[num2][num2][0]*fra[num2]%mod);
			for(int i=0;i<=num1;i++)
			MEM(dp1[i]);
			for(int i=0;i<=num2;i++)
			MEM(dp2[i]);
			continue;
		}
		int k=num1/2+num1%2;
		LL ans=0; 
		for(int i=0;i<11;i++){
		//	printf("%d ",i);
			for(int j=0;j<=num2;j++){
				ans+=(LL)dp1[num1][k][i]*fra[k]%mod*fra[num1-k]%mod*dp2[num2][j][(11-i)%11]%mod*fra[j]%mod*fra[num2-j]%mod*C(j+num1/2,j)%mod*C(num2-j+(num1-1)/2,num2-j)%mod;
				ans%=mod;
			}
		//	printf("%d\n",ans);
		}
		printf("%I64d\n",ans);
		for(int i=0;i<=num1;i++)
		MEM(dp1[i]);
		for(int i=0;i<=num2;i++)
		MEM(dp2[i]);
	}
}