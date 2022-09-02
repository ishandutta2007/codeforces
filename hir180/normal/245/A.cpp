#include <cstdio>
int x[2]={},y[2]={};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1){
			x[0]+=b;
			x[1]+=c;
		}else{
		    y[0]+=b;
			y[1]+=c;
		}
	}
	if(x[0]>=x[1]){
		printf("LIVE\n");
	}else if(x[0]<x[1]){
		printf("DEAD\n");
	}
	if(y[0]>=y[1]){
		printf("LIVE\n");
	}else if(y[0]<y[1]){
		printf("DEAD\n");
	}
	return 0;
}