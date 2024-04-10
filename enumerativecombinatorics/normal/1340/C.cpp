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
const long double EPS=1e-9;
const long double INF=1e+10;
const long double PI=acos(-1.0);
const int C_SIZE = 3100000;
const int UF_SIZE = 3100000;
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
		// if(UF[a]>UF[b])swap(a,b);
		UF[a]+=UF[b];UF[b]=a;
	}
}
// 
int v[10100][1010];
int ijk[10100][1010];
int p[10100];
queue<pair<int,pair<int,int> > >Q[1100];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		scanf("%d",p+i);
	}
	int G,R;scanf("%d%d",&G,&R);
	std::sort(p,p+b);
	for(int i=0;i<b;i++)for(int j=0;j<=G;j++){
		ijk[i][j]=mod*2;
	}
	ijk[0][0]=0;
	// priority_queue<pair<int,pair<int,int> > > Q;
	Q[0].push(make_pair(0,make_pair(0,0)));
	int D=1010;
	while(1){
		bool chg=false;
		for(int i=0;i<D;i++){
			while(Q[i].size()){
				int cost=-Q[i].front().first;
				int at=Q[i].front().second.first;
				int ind=Q[i].front().second.second;
				Q[i].pop();
				if(v[at][ind])continue;
				v[at][ind]=1;
 
				if(ind==G&&v[at][0]==0&&ijk[at][0]>cost+R){
					ijk[at][0]=cost+R;
					chg=true;
					Q[(cost+R)%D].push(make_pair(-cost-R,make_pair(at,0)));
				}
				if(at){
					int T=p[at]-p[at-1];
					int F=ind+T;
					if(F<=G&&v[at-1][F]==0&&ijk[at-1][F]>cost+T){
						ijk[at-1][F]=cost+T;
						chg=true;
						Q[(cost+T)%D].push(make_pair(-ijk[at-1][F],make_pair(at-1,F)));
					}
				}
				if(at+1<b){
					int T=p[at+1]-p[at];
					int F=ind+T;
					if(F<=G&&v[at+1][F]==0&&ijk[at+1][F]>cost+T){
						ijk[at+1][F]=cost+T;
						chg=true;
						Q[(cost+T)%D].push(make_pair(-ijk[at+1][F],make_pair(at+1,F)));
					}
				}
			}			
		}
		if(!chg){
			break;
		}
	}
 
	int ret=mod*2;
	for(int i=0;i<=G;i++){
		ret=min(ret,ijk[b-1][i]);
	}
	if(ret==mod*2)ret=-1;
	printf("%d\n",ret);
}