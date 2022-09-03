/*#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;*/
#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
vector<int> v[200005];
LL dp[200005][3];
int mod=998244353;
void dfs(int x){
	if(v[x].empty()){
		dp[x][0]=dp[x][1]=dp[x][2]=1;
		return ;
	}
	LL sum=1;
	LL sum1=1;
	vector<LL> pri,suf;
	//pri.resize(v[x].size()+1);
	suf.resize(v[x].size()+1);
	pri.pb(1);
	for(auto it:v[x]){
		dfs(it);
		sum*=(dp[it][0]+dp[it][1]);
		sum%=mod;
		sum1*=dp[it][0];
		sum1%=mod;
		pri.pb(sum1);
	}
	dp[x][0]=sum;
	dp[x][1]=((sum-sum1)%mod+mod)%mod;
	sum1=1;
	suf[v[x].size()]=1;
	for(int i = v[x].size()-1;i>=0;i--){
		suf[i]=suf[i+1]*dp[v[x][i]][0];
		suf[i]%=mod;
	}
	dp[x][2]=0;
	for(int i = 0;i<v[x].size();i++){
		dp[x][2]+=pri[i]*suf[i+1]%mod*dp[v[x][i]][1]%mod;
		dp[x][2]%=mod;
	}
	dp[x][0]-=dp[x][2];
	dp[x][0]=(dp[x][0]%mod+mod)%mod;
	//printf("%d %d %d\n",dp[x][0],dp[x][1],dp[x][2]);
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i =2;i<=n;i++){
		int x;
		scanf("%d",&x);
		v[x].pb(i);
	}
	dfs(1);
	printf("%lld\n",dp[1][0]);
	return 0;
}
/*
0 1
1 1
2 1
3 2
4 2
5 2

6 3

*/
/*
 9 10 11
*/