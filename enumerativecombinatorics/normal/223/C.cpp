#include<stdio.h>
#include<algorithm>
using namespace std;
int c[2000];
long long inv[3000];
long long ter[2000];
long long ret[2000];
int main(){
	int mod=1000000007;
	inv[1]=1LL;
	for(int i=2;i<3000;i++){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
	}
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%d",c+i);
	if(b==0){
		for(int i=0;i<a;i++){
			printf("%d",c[i]);
			if(i<a-1)printf(" ");
			else printf("\n");
		}
		return 0;
	}
	b--;
	for(int i=0;i<a;i++){
		ter[i]=1LL;
		for(int j=0;j<i;j++){
			ter[i]=ter[i]*(b+i-j)%mod;
			ter[i]=ter[i]*inv[j+1]%mod;
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;i+j<a;j++){
			ret[i+j]=(ret[i+j]+ter[j]*c[i])%mod;
		}
	}
	for(int i=0;i<a;i++){
		printf("%d",(int)(ret[i]));
		if(i<a-1)printf(" ");
		else printf("\n");
	}
}