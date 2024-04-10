#include<stdio.h>
#include<algorithm>
using namespace std;
int d[1000];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<b;i++)scanf("%d",d+i);
	c--;
	d[c]--;
	int e=1;
	for(int i=0;i<b;i++)e+=d[i];
	if(e<a){
		printf("-1.0\n");
		return 0;
	}
	double q=(double)a/e;
	double p=1;
	for(int i=0;i<a-1;i++){
		p*=e-i-1-d[c];
		p/=e-i-1;
	}
	printf("%.9f\n",1.0-p);
}