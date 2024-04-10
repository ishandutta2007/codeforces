#include<stdio.h>
using namespace std;
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r,d;
		scanf("%d %d %d",&l,&r,&d);
		if(d<l){
			printf("%d\n",d);
		}
		else{
			printf("%d\n",r/d*d+d);
		}
	}
}