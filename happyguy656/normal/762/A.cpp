#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cmath>

long long n;int k;
const int mxl=3.2e7;
int a[mxl];
int len=0;

long long gtans(void) {
	if(k<=len)return a[k];
	if((long long)a[len]*a[len]==n)len=len*2-1;else len=len*2;
	if(k>len)return -1;
	int pos=len-k+1;
	return n/a[pos];
}
int main(void) {
	scanf("%lld%d",&n,&k);
	for(int i=1;i<=sqrt(n);++i)if(n%i==0)a[++len]=i;
	printf("%lld\n",gtans());
	return 0;
}