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
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
long long pw(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
long long inv(long long a){
	return pw(a,mod-2);
}
long long A[210000];
long long B[210000];
long long C[210000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%lld",A+i);
	for(int i=0;i<a;i++)scanf("%lld",B+i);
	long long ret=a;
	for(int i=0;i<a-1;i++){
		C[i]=max(0LL,min(B[i],B[i+1])-max(A[i],A[i+1])+1);
	}
	for(int i=0;i<a-1;i++){
		ret=(ret+mod-C[i]*inv(B[i]-A[i]+1)%mod*inv(B[i+1]-A[i+1]+1)%mod)%mod;
	}
	ret=ret*ret%mod;
	for(int i=0;i<a-1;i++){
		ret=(ret+C[i]*inv(B[i]-A[i]+1)%mod*inv(B[i+1]-A[i+1]+1)%mod*(mod+1-C[i]*inv(B[i]-A[i]+1)%mod*inv(B[i+1]-A[i+1]+1)%mod))%mod;
		//printf("%lld %lld\n",C[i]*inv(B[i]-A[i]+1)%mod,(mod+1-C[i]*inv(B[i]-A[i]+1)%mod));
	}
	//printf("%lld\n",ret);
	
	for(int i=0;i<a-2;i++){

		long long p01=0;
		p01+=max(0LL,min(B[i],min(B[i+1],B[i+2]))-max(A[i],max(A[i+1],A[i+2]))+1)*inv(B[i]-A[i]+1)%mod*inv(B[i+1]-A[i+1]+1)%mod*inv(B[i+2]-A[i+2]+1)%mod*(B[i]-A[i])%mod;
		long long rem=max(0LL,min(B[i+2],B[i+1])-max(A[i+2],A[i+1])+1)-max(0LL,min(B[i],min(B[i+1],B[i+2]))-max(A[i],max(A[i+1],A[i+2]))+1);
		p01+=rem*inv(B[i+2]-A[i+2]+1)%mod*inv(B[i+1]-A[i+1]+1)%mod;
		p01%=mod;

		long long p10=0;
		p10+=max(0LL,min(B[i],min(B[i+1],B[i+2]))-max(A[i],max(A[i+1],A[i+2]))+1)*inv(B[i]-A[i]+1)%mod*inv(B[i+1]-A[i+1]+1)%mod*inv(B[i+2]-A[i+2]+1)%mod*(B[i+2]-A[i+2])%mod;
		rem=max(0LL,min(B[i],B[i+1])-max(A[i],A[i+1])+1)-max(0LL,min(B[i],min(B[i+1],B[i+2]))-max(A[i],max(A[i+1],A[i+2]))+1);
		p10+=rem*inv(B[i]-A[i]+1)%mod*inv(B[i+1]-A[i+1]+1)%mod;
		p10%=mod;
		long long p11=max(0LL,min(B[i],min(B[i+1],B[i+2]))-max(A[i],max(A[i+1],A[i+2]))+1)*inv(B[i]-A[i]+1)%mod*inv(B[i+1]-A[i+1]+1)%mod*inv(B[i+2]-A[i+2]+1)%mod;

		long long p00=(mod*4+1-p01-p10-p11)%mod;
	//	printf("%lld %lld %lld %lld\n",p00,p01,p10,p11);
		long long tmp=0;
		tmp=(tmp+(p10+p11)*(p01+p11)%mod*p00)%mod;
		tmp=(tmp+mod-(2*mod+1-p10-p11)*(p01+p11)%mod*p10%mod)%mod;
		tmp=(tmp+mod-(p10+p11)*(2*mod+1-p01-p11)%mod*p01%mod)%mod;
		tmp=(tmp+(2*mod+1-p10-p11)*(2*mod+1-p01-p11)%mod*p11)%mod;
		ret=(ret+tmp*2)%mod;
	}
	printf("%lld\n",ret);
}