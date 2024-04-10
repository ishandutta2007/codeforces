// #pragma GCC target("avx")  // CPU 
// #pragma GCC optimize("O3")  // CPU 
// #pragma GCC optimize("unroll-loops")  // 
// #define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));
// #define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);

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
#include<unordered_map>
#include<complex>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-11;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 11100000;
const int UF_SIZE = 3100000;
namespace{
	long long fact[C_SIZE];
	long long finv[C_SIZE];
	long long inv[C_SIZE];
	inline long long Comb(int a,int b){
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
	int UF[UF_SIZE];
	void init_UF(int n){
		for(int i=0;i<n;i++)UF[i]=-1;
	}
	int FIND(int a){
		if(UF[a]<0)return a;
		return UF[a]=FIND(UF[a]);
	}
	void UNION(int a,int b){
		a=FIND(a);b=FIND(b);if(a==b)return;
		if(UF[a]>UF[b])swap(a,b);
		UF[a]+=UF[b];UF[b]=a;
	}
}
// 
char in[110];
int dp[80][80][80][2];
int n;
int calc(int a,int b,int c,int d){
	int ret=0;
	for(int i=0;i<n;i++){
		if(in[i]=='K'){
			if(a==0){
				if(d==0)return ret;
				ret++;
			}
			else a--;
		}else if(in[i]=='V'){
			if(c==0){
				if(d==2)return ret;
				ret++;
			}
			else c--;
		}else{
			if(b==0){
				if(d==1)return ret;
				ret++;
			}
			else b--;
		}
	}
	return mod;
}
int main(){
	int a;scanf("%d",&a);n=a;
	scanf("%s",in);
	int V=0;
	int K=0;
	for(int i=0;i<a;i++){
		if(in[i]=='K')K++;
		if(in[i]=='V')V++;
	}
	for(int i=0;i<80;i++)for(int j=0;j<80;j++)for(int k=0;k<80;k++)for(int l=0;l<2;l++)dp[i][j][k][l]=mod;
	dp[0][0][0][0]=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<=K;j++){
			for(int k=0;k<=a-K-V;k++){
				for(int l=0;l<2;l++){
					if(dp[i][j][k][l]==mod)continue;
					if(l==0&&j<K){
						dp[i+1][j+1][k][0]=min(dp[i+1][j+1][k][0],dp[i][j][k][l]+calc(j,k,i-j-k,0));
					}
					if(k<a-K-V){
						dp[i+1][j][k+1][0]=min(dp[i+1][j][k+1][0],dp[i][j][k][l]+calc(j,k,i-j-k,1));
					}
					if(i-j-k<V){
						dp[i+1][j][k][1]=min(dp[i+1][j][k][1],dp[i][j][k][l]+calc(j,k,i-j-k,2));
					}
				}
			}
		}
	}
	int ret=min(dp[a][K][a-K-V][0],dp[a][K][a-K-V][1]);
	printf("%d\n",ret);
}