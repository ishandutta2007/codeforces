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
#define pi 3.14159265359
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define N 300005
using namespace std;
typedef long long LL;
int prime[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int dp[71][1<<19];
int mod=1e9+7;
LL f_pow(int a,int b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	int cnt[71];
	MEM(cnt);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
	//	a=2;
		cnt[a]++;
	}
	//printf("%d\n",f_pow(2,n)-1);
	MEM(dp);
	dp[0][0]=1;
	for(int i=0;i<70;i++){
		int sum=0,k=i+1;
		for(int j=0;j<19;j++){
			sum<<=1;
			while(k%prime[j]==0){
				k/=prime[j];
				sum^=1;
			}
		}
		LL kk=f_pow(2,cnt[i+1]);
		LL rev=f_pow(2,mod-2);
		for(int j=0;j<(1<<19);j++){
			if(cnt[i+1]==0){
				dp[i+1][j]+=dp[i][j];
				continue; 
			}
			dp[i+1][j]+=dp[i][j]*(kk*rev%mod)%mod;
			dp[i+1][j]%=mod;
			dp[i+1][j^sum]+=dp[i][j]*(kk*rev%mod)%mod;
			dp[i+1][j^sum]%=mod;
		}
		//printf("%d\n",dp[i][0]);
	}
	printf("%d\n",(dp[70][0]-1+mod)%mod);
}