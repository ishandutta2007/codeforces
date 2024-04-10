#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
LL fra[1005];
LL rev[1005];
LL mod=1e9+7;
LL f_pow(int a,int b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
LL dp[15][105];
int nn;
int a[10];
LL DP(int dig,int n){
	if(n<0)
	return 0;
	if(dig==-1&&n==0)
	return 1;
	if(dig==-1)
	return 0;
	if(dp[dig][n]!=-1)
	return dp[dig][n];
	dp[dig][n]=0;
	for(int i=a[dig];i<=n;i++){
		dp[dig][n]+=DP(dig-1,n-i)*rev[i]%mod*rev[n-i]%mod*fra[n]%mod;
		dp[dig][n]%=mod;
	}
	return dp[dig][n];
}
int main(){
	fra[0]=1;
	for(int i=1;i<=1000;i++)
	fra[i]=fra[i-1]*i%mod;
	rev[1000]=f_pow(fra[1000],mod-2); 
	for(int i=999;i>=0;i--)
	rev[i]=rev[i+1]*(i+1)%mod;
	scanf("%d",&nn);
	int sum=0;
	for(int i=0;i<10;i++)
	scanf("%d",&a[i]);
	LL ans=0;
	for(int i=1;i<=nn;i++){
		MEMS(dp);
		LL res=DP(9,i);
		int temp=a[0];	
		a[0]--;
		if(a[0]<0)
		a[0]=0;
		MEMS(dp);
		//printf("%I64d\n",res);
		res=res-DP(9,i-1);
		a[0]=temp;
		ans+=res;
		ans%=mod;
	//	printf("%d\n",i);
	//	printf("%I64d\n",ans);
	}
	printf("%I64d\n",(ans+mod)%mod);
}
/*
910~010  901~001 20
1
110 101 011
10~19 01~91 19
*/