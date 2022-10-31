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
const long long mod=998244353;
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
	int pw_mod_int(int a,int b,int M){
		if(a<0)return 0;
		if(b<0)return 0;
		int ret=1;
		while(b){
			if(b%2)ret=(long long)ret*a%M;
			a=(long long)a*a%M;
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
int x[4000];
int y[4000];
long long dp[4000][2000];
long long S[2000];
long long T[2000];

int main(){
	init_C(11000);
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<c;i++){
		int p,q,r,s;scanf("%d%d%d%d",&p,&q,&r,&s);
		p--;q--;r--;s--;
		x[p]=1;
		x[r]=1;
		y[q]=1;
		y[s]=1;
	}
	int rx=0;
	int ry=0;
	for(int i=0;i<a;i++){
		if(x[i]==0)rx++;
	}
	for(int i=0;i<b;i++){
		if(y[i]==0)ry++;
	}
	dp[0][0]=1;
	for(int i=0;i<a;i++){
		for(int j=0;j<=a/2;j++){
			if(dp[i][j]==0)continue;
			dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
			if(i<a-1&&x[i]==0&&x[i+1]==0){
				dp[i+2][j+1]=(dp[i+2][j+1]+dp[i][j])%mod;
			}
		}
	}
	for(int i=0;i<2000;i++)S[i]=dp[a][i];
	for(int i=0;i<4000;i++)for(int j=0;j<2000;j++)dp[i][j]=0;
	dp[0][0]=1;
	for(int i=0;i<b;i++){
		for(int j=0;j<=b/2;j++){
			if(dp[i][j]==0)continue;
			dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
			if(i<b-1&&y[i]==0&&y[i+1]==0){
				dp[i+2][j+1]=(dp[i+2][j+1]+dp[i][j])%mod;
			}
		}
	}
	for(int i=0;i<2000;i++)T[i]=dp[b][i];
	long long ret=0;
	for(int i=0;i<2000;i++)for(int j=0;j<2000;j++){
		if(S[i]==0||T[j]==0)continue;
		if(i*2+j>rx)continue;
		if(j*2+i>ry)continue;
		long long ks=Comb(rx-i*2,j)*Comb(ry-j*2,i)%mod;
		ks=ks*fact[i]%mod;
		ks=ks*fact[j]%mod;
		ret=(ret+ks*S[i]%mod*T[j])%mod;
	}
	printf("%lld\n",ret);
}