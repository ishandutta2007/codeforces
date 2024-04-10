#include<stdio.h>
#include<algorithm>
using namespace std;
int key[]={1,2,9,64,625,7776,117649,2097152};
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	long long ret=key[b-1];
	int mod=1000000007;
	for(int i=0;i<a-b;i++)ret=ret*(a-b)%mod;
	printf("%I64d\n",ret);
}