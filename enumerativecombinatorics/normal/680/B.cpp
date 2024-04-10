#include<stdio.h>
#include<algorithm>
using namespace std;
int c[110];
int bb[110];
int bs[110];
int ABS(int a){
	return max(a,-a);
}
int main(){
	int a,b;scanf("%d%d",&a,&b);b--;
	for(int i=0;i<a;i++)scanf("%d",c+i);
	for(int i=0;i<a;i++){
		bb[ABS(i-b)]++;
		bs[ABS(i-b)]+=c[i];
	}
	int ret=0;
	for(int i=0;i<110;i++)if(bb[i]==bs[i])ret+=bs[i];
	printf("%d\n",ret);
}