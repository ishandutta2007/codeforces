#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
long long b[110000];
long long d3=(mod+1)/3;
long long d2=(mod+1)/2;
long long pw(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		b/=2;
		a=a*a%mod;
	}
	return ret;
}
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%I64d",b+i);
	bool gu=false;
	for(int i=0;i<a;i++)if(b[i]%2==0)gu=true;
	long long tmp=pw(2,b[0]);
	for(int i=1;i<a;i++)tmp=pw(tmp,b[i]);
	tmp=tmp*d2%mod;
	long long bs;
	if(gu)bs=(tmp+1)%mod;
	else bs=(tmp+mod-1)%mod;
	bs=bs*d3%mod;
	printf("%d/%d\n",(int)bs,(int)tmp);
}