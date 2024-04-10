#include<stdio.h>
#include<algorithm>
using namespace std;
int c[1000];
int d[1000];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		int p,q;
		scanf("%d%d",&p,&q);
		p--;q--;
		c[p]++;
		d[q]++;
	}
	int ret=0;
	for(int i=1;i<a/2;i++){
		if(!c[i])ret++;
		if(!c[a-1-i])ret++;
		if(!d[i])ret++;
		if(!d[a-1-i])ret++;
	}
	if(a%2){
		if(!c[a/2]||!d[a/2])ret++;
	}
	printf("%d\n",ret);
}