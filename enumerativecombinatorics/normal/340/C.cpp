#include<stdio.h>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b){
	while(a){
		b%=a;
		long long c=a;
		a=b;
		b=c;
	}
	return b;
}
int t[100001];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",t+i+1);
	std::sort(t,t+a+1);
	long long dis=0;
	for(int i=0;i<a;i++){
		dis+=(long long)(i*2+1)*(a-i)*(t[i+1]-t[i]);
	}
	long long p=gcd(dis,a);
	printf("%I64d %I64d\n",dis/p,a/p);
}