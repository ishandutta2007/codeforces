#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int a;
	scanf("%d",&a);
	int ret=0;
	int v=0;
	for(int i=0;i<a;i++){
		int b,c;
		scanf("%d%d",&b,&c);
		v=v-b+c;
		ret=max(ret,v);
	}
	printf("%d\n",ret);
}