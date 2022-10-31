// #pragma GCC target("avx2")  // CPU 
// #pragma GCC optimize("O3")  // CPU 
// #pragma GCC optimize("unroll-loops")  // 
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
#include<numeric>
#include<unordered_set>
#include<complex>
using namespace std;
const long long mod=1008691207;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3121000;
namespace{
	long long fact[C_SIZE];
	long long finv[C_SIZE];
	long long inv[C_SIZE];
	long long Comb(int a,int b){
	 	if(a<b||b<0)return 0;
	 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
	}
	void init_C(int n){
		fact[0]=finv[0]=inv[1]=1;
		for(int i=2;i<n;i++){
			inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
		}
		for(int i=1;i<n;i++){
			fact[i]=fact[i-1]*i%mod;
			finv[i]=finv[i-1]*inv[i]%mod;
		}
	}
	long long pw(long long a,long long b){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%mod;
			a=a*a%mod;
			b/=2;
		}
		return ret;
	}
	long long pw_mod(long long a,long long b,long long M){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%M;
			a=a*a%M;
			b/=2;
		}
		return ret;
	}
	int ABS(int a){return max(a,-a);}
	long long ABS(long long a){return max(a,-a);}
	double ABS(double a){return max(a,-a);}
	int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
}
// 
vector<pair<int,int> >g[510000];
long long dp[510000][2];
pair<long long,int> tmp[510000];
int K;
void calc(int a,int b,int c){
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i].first)continue;
		calc(g[a][i].first,a,g[a][i].second);
	}
	int sz=0;
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i].first)continue;
		tmp[sz++]=make_pair(dp[g[a][i].first][1]-dp[g[a][i].first][0],g[a][i].first);
	}
	std::sort(tmp,tmp+sz);
	reverse(tmp,tmp+sz);
	long long bk=0;
	long long bk1=0;
	for(int i=0;i<sz;i++){
		int at=tmp[i].second;
		if(i<K){
			bk+=max(dp[at][0],dp[at][1]);
		}else{
			bk+=dp[at][0];
		}
		if(i<K-1){
			bk1+=max(dp[at][0],dp[at][1]);
		}else{
			bk1+=dp[at][0];
		}
	}
	dp[a][0]=bk;
	dp[a][1]=bk1+c;
}
int main(){
	int Q;scanf("%d",&Q);
	while(Q--){
		int a,b;scanf("%d%d",&a,&b);
		K=b;
		for(int i=0;i<a;i++){
			g[i].clear();
			dp[i][0]=dp[i][1]=0LL;
		}
		for(int i=0;i<a-1;i++){
			int p,q,r;scanf("%d%d%d",&p,&q,&r);p--;q--;
			g[p].push_back(make_pair(q,r));
			g[q].push_back(make_pair(p,r));
		}
		calc(0,-1,0);
		printf("%lld\n",dp[0][0]);
	}
}