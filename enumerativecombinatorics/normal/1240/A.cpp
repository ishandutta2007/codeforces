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
int p[210000];
int gcd(int a,int b){
	while(a){
		b%=a;swap(a,b);
	}return b;
}
long long lcm(int a,int b){
	return (long long)a/gcd(a,b)*b;
}
int main(){
	int Q;scanf("%d",&Q);
	while(Q--){
		int a;scanf("%d",&a);
		for(int i=0;i<a;i++)scanf("%d",p+i);
		std::sort(p,p+a);
		reverse(p,p+a);
		int x,c,y,d;
		scanf("%d%d%d%d",&x,&c,&y,&d);
		if(x<y){
			swap(x,y);
			swap(c,d);
		}
		long long s=lcm(c,d);
		long long e;scanf("%lld",&e);
		int left=0;
		int right=a+1;
		while(left+1<right){
			int M=(left+right)/2;
			long long cur=0;
			int A=M/s;
			int B=M/c-A;
			int C=M/d-A;
			for(int i=0;i<A;i++){
				cur+=p[i]/100*(x+y);
			}
			for(int i=0;i<B;i++){
				cur+=p[A+i]/100*(x);
			}
			for(int i=0;i<C;i++){
				cur+=p[A+B+i]/100*(y);
			}
			
			if(cur>=e){
				right=M;
			}else left=M;
		}
		if(right>a){
			right=-1;
		}
		printf("%d\n",right);
	}
}