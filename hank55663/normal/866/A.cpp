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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int dp[1000005];
	int ans[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=1e6;i++)
	dp[i]=1;
	for(int i=2;i<=1e6;i++)
	dp[i]+=dp[i-2];
	for(int i=1;i<=1e6;i++){
		if(dp[i]==n){
			printf("%d %d\n",i,2);
			printf("1 2\n");
			break;
		}
	}
}