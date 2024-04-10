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
long long a[4];
char out[1010000];
int main(){
	for(int i=0;i<4;i++)scanf("%I64d",a+i);
	long long t=0;
	for(int i=0;i<4;i++)t+=a[i];
	if(t==0){
		printf("1\n");return 0;
	}
	int sz=0;
	while((long long)sz*(sz-1)/2<t)sz++;
	if((long long)sz*(sz-1)/2!=t){
		printf("Impossible\n");return 0;
	}
	for(int i=0;i<=sz;i++){
		long long B=(long long)i*(i-1)/2;
		long long W=(long long)(sz-i)*(sz-i-1)/2;
		if(a[0]==B&&a[3]==W){
			if(a[1]+a[2]!=(long long)i*(sz-i)){
				printf("Impossible\n");return 0;
			}
			if(i==0){
				for(int j=0;j<sz;j++)printf("1");printf("\n");return 0;
			}else if(i==sz){
				for(int j=0;j<sz;j++)printf("0");printf("\n");return 0;
			}

			int ind=0;
			for(int j=0;j<a[2]/i;j++)out[ind++]='1';
			for(int j=0;j<i-a[2]%i;j++)out[ind++]='0';
			out[ind++]='1';
			for(int j=0;j<a[2]%i;j++)out[ind++]='0';
			for(int j=0;j<sz-i-a[2]/i-1;j++)out[ind++]='1';
				out[sz]=0;
			printf("%s\n",out);
			return 0;
		}
	}
	printf("Impossible\n");
}