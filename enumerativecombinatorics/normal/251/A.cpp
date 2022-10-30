#include<stdio.h>
#include<algorithm>
using namespace std;
int p[100000];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	int right=0;
	long long ret=0;
	for(int i=0;i<a;i++){
		while(right<a&&p[right]<=p[i]+b){
			right++;
		}
		long long n=right-i;
		ret+=(n-1)*(n-2)/2;
	}
	printf("%I64d\n",ret);
}