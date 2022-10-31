#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1100000];
long long pow2[1100000];
int b[1<<20];
int main(){
	int mod=1000000007;
	int n;scanf("%d",&n);
	pow2[0]=1;
	for(int i=1;i<1100000;i++)pow2[i]=pow2[i-1]*2%mod;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	std::sort(a,a+n);
	for(int i=0;i<n;i++)b[a[i]]++;
	for(int i=0;i<20;i++){
		for(int j=0;j<(1<<20);j++)
			if(0==(j&(1<<i)))b[j]+=b[j|(1<<i)];
	}
//	for(int i=0;i<(1<<20);i++)
	//	if()
	long long ret=0;
	for(int i=0;i<(1<<20);i++){
		int count=0;
		for(int j=0;j<20;j++)if(i&(1<<j))count++;
		if(count%2==0)ret=(ret+pow2[b[i]])%mod;
		else ret=(ret+mod-pow2[b[i]])%mod;
	}
	printf("%d\n",(int)ret);
}