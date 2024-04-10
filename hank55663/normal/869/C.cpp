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
#define MAXN 100005
#define MAXD 2
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int mod=998244353;
int C[5005][5005];
int main(){
	for(int i=1;i<=5000;i++)
	C[i][0]=C[i][i]=1;
	for(int i=1;i<=5000;i++)
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	LL res=1;
	int sum=1;
	for(int i=1;i<=min(a,b);i++){
		LL tot=1;
		for(int j=0;j<i;j++){
			tot*=max(a,b)-j;
			tot%=mod;
			
		}
	//	printf("%d",tot);
	//	printf("%d\n",C[min(a,b)][i]);
		sum+=(LL)C[min(a,b)][i]*tot%mod;
		sum%=mod;
	//	printf("%d\n",sum);
	}
//	printf("%d\n",sum);
	res*=sum;
	res%=mod;
	sum=1;
	for(int i=1;i<=min(a,c);i++){
		LL tot=1;
		for(int j=0;j<i;j++){
			tot*=max(a,c)-j;
			tot%=mod;
		}
	//	printf("%d\n",C[min(a,b)][i]);
		sum+=(LL)C[min(a,c)][i]*tot%mod;
		sum%=mod;
	//	printf("%d\n",sum);
		//res*=sum;
	}
//	printf("%d\n",sum);
	res*=sum;
	res%=mod;
	sum=1;
	for(int i=1;i<=min(c,b);i++){
		LL tot=1;
		for(int j=0;j<i;j++){
			tot*=max(c,b)-j;
			tot%=mod;
		}
	//	printf("%d\n",C[min(a,b)][i]);
		sum+=(LL)C[min(c,b)][i]*tot%mod;
		sum%=mod;
	//	printf("%d\n",sum);
	}
	res*=sum;
	res%=mod;
	printf("%I64d\n",res);
} 
//200 2048 11
//10 
//01 
//1001 
//10011