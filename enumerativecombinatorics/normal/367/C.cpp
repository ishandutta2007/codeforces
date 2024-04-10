#include<stdio.h>
#include<algorithm>
using namespace std;
int c[120000];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		int p,q;scanf("%d%d",&p,&q);
		c[i]=q;
	}
	std::sort(c,c+b);
	long long ret=0LL;
	int s=0;
	for(int i=0;i<b;i++){
		int n=i+1;
		if(n%2)s=n*(n-1)/2;
		else s=n*(n-1)/2+n/2-1;
		if(s>=a)break;
		ret+=c[b-1-i];
	}
	printf("%I64d\n",ret);
}