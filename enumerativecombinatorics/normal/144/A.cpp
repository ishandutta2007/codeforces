#include<stdio.h>
#include<algorithm>
using namespace std;
int b[100];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	int c=0;
	int d=100;
	for(int i=0;i<a;i++){
		c=max(c,b[i]);
		d=min(d,b[i]);
	}
	int e=0;
	for(int i=0;i<a;i++){
		if(d==b[i])e=i;
	}
	int ret=0;
	for(int i=e+1;i<a;i++){
		int t=b[i];
		b[i]=b[i-1];
		b[i-1]=t;
		ret++;
	}
	for(int i=0;i<a;i++)if(b[i]==c){
		ret+=i;
		break;
	}
	printf("%d\n",ret);
}