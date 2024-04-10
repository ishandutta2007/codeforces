#include<stdio.h>
#include<algorithm>
using namespace std;
int b[1000000];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	std::sort(b,b+a);
	int L=-1;
	int R=a/2+1;
	while(L+1<R){
		int M=(L+R)/2;
		bool ok=true;
		for(int i=0;i<M;i++){
			if(b[i]*2>b[a-M+i])ok=false;
		}
		if(ok)L=M;
		else R=M;
	}
	printf("%d\n",a-L);
}