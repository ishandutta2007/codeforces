#include<stdio.h>
#include<algorithm>
using namespace std;
int b[100];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	std::sort(b,b+a);
	int sum=0;
	for(int i=0;i<a;i++)sum+=b[i];
	int now=0;
	for(int i=a-1;i>=0;i--){
		now+=b[i];
		if(sum-now<now){
			printf("%d\n",a-i);
			break;
		}
	}
}