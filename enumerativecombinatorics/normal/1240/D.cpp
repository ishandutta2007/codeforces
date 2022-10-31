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
int p[310000];
int par[310000];
int num[310000];
int cnt[310000];
map<pair<int,int>,int>M;
int main(){
	int Q;scanf("%d",&Q);
	while(Q--){
		int a;scanf("%d",&a);
		for(int i=0;i<a;i++){
			scanf("%d",p+i);
			p[i]--;
		}
		for(int i=0;i<=a+10;i++){
			par[i]=num[i]=cnt[i]=0;
		}
		M.clear();
		long long ret=0;
		int at=0;
		int sz=1;
		num[at]=-1;
		cnt[at]=1;
		for(int i=0;i<a;i++){
			if(p[i]==num[at]){
				at=par[at];
			}else{
				if(M.count(make_pair(at,p[i]))){
					int id=M[make_pair(at,p[i])];
					at=id;
				}else{
					M[make_pair(at,p[i])]=sz;
					num[sz]=p[i];
					par[sz]=at;
					at=sz;
					sz++;
				}
			}
			ret+=cnt[at];
			cnt[at]++;
		}
		printf("%lld\n",ret);
	}
}