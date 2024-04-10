#include<stdio.h>
#include<algorithm>
using namespace std;
int c[1000000];
int d[1000000];
int e[1000000];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++)scanf("%d%d",c+i,d+i);
	long long ret=(long long)a*(a-1)*(a-2)/6-(long long)b*(a-2);
	for(int i=0;i<b;i++){
		e[c[i]-1]++;
		e[d[i]-1]++;
	}
	for(int i=0;i<a;i++)ret+=(long long)e[i]*(e[i]-1)/2;
	printf("%I64d\n",ret);
}