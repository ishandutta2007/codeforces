#include<stdio.h>
#include<algorithm>
using namespace std;
typedef unsigned int wolf;
wolf d[100000];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		int c,p,e,f;
		scanf("%d.%d.%d.%d",&c,&p,&e,&f);
		d[i]=((wolf)c<<24)+(p<<16)+(e<<8)+f;
	}
	std::sort(d,d+a);
	for(int i=1;i<32;i++){
		int n=1;
		wolf t=0;
		for(int j=0;j<i;j++){
			t*=2;
			t+=1;
		}
		for(int j=i;j<32;j++)t*=2;
		for(int j=1;j<a;j++)if((d[j-1]&t)!=(d[j]&t))n++;
		if(n==b){
			printf("%d.%d.%d.%d",t>>24,(t>>16)%256,(t>>8)%256,t%256);
			return 0;
		}
	}
	printf("-1\n");
}