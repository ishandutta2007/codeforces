#include<stdio.h>
#include<algorithm>
using namespace std;
int p[120];
int main(){
	int sum=0;
	for(int i=0;i<5;i++){
		int a;scanf("%d",&a);p[a]++;
		sum+=a;
	}
	int ret=sum;
	for(int i=0;i<=100;i++){
		if(p[i]>=2)ret=min(ret,sum-i*min(p[i],3));
	}
	printf("%d\n",ret);
}