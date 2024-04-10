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
vector<int> v[100005];
LL dp[100005][15][3];
int k,m,x;
int mod =1e9+7;
void dfs(int n,int f){
	LL bag[2][15];
	LL bag1[2][15];
	LL bag2[2][15];
	MEM(bag);
	MEM(bag1);
	MEM(bag2);
	bag[0][0]=1;
	bag1[0][0]=1;
	bag2[0][0]=1;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(*it!=f){
			dfs(*it,n);
			for(int i=x;i>=0;i--)
				for(int j=0;j<=x-i;j++){
					bag[1][i+j]+=bag[0][i]*(dp[*it][j][0]+dp[*it][j][2])%mod;
					bag[1][i+j]%=mod;
					bag1[1][i+j]+=bag1[0][i]*(dp[*it][j][0]+dp[*it][j][1]+dp[*it][j][2])%mod;
					bag1[1][i+j]%=mod;
					bag2[1][i+j]+=bag2[0][i]*(dp[*it][j][0])%mod;
					bag2[1][i+j]%=mod; 
				}
			for(int i=0;i<=x;i++){
				bag[0][i]=bag[1][i];bag[1][i]=0;
				bag1[0][i]=bag1[1][i];bag1[1][i]=0;
				bag2[0][i]=bag2[1][i];bag2[1][i]=0;
			}
		}
	}
	for(int i=0;i<=x;i++){
		bag1[0][i]-=bag[0][i];
		bag1[0][i]=(bag1[0][i]+mod)%mod;
	}
	for(int i=0;i<=x;i++){
		dp[n][i][0]=bag1[0][i]*(k-1)%mod+bag[0][i]*(k-1)%mod;
		if(i<x)
		dp[n][i+1][1]=bag2[0][i];
		dp[n][i][2]=bag[0][i]*(m-k)%mod;
	//	printf("%d %d %d %d %d\n",n,i,dp[n][i][0],dp[n][i+1][1],dp[n][i][2]);
	} 
}
int main(){
	int n;
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	MEM(dp);
	scanf("%d %d",&k,&x);
	dfs(1,0);
	LL ans=0;
	for(int i=0;i<=x;i++){
		ans+=dp[1][i][0]+dp[1][i][1]+dp[1][i][2];
		ans%=mod;
	}
	printf("%d\n",ans);
}