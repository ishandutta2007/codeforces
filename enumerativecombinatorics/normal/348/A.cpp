#include<stdio.h>
#include<algorithm>
using namespace std;
int b[100100];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",b+i);
	}
	long long left=0LL;
	long long right=1000000000000LL;
	while(left+1<right){
		long long M=(left+right)/2;
		long long now=0;
		bool ok=true;
		for(int i=0;i<a;i++){
			if(M<b[i])ok=false;
			now+=M-b[i];
		}
		if(ok&&M<=now){
			right=M;
		}else left=M;
	}
	printf("%I64d\n",right);
}