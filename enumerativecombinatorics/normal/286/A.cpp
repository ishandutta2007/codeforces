#include<stdio.h>
int ans[100000];
int main(){
	int a;scanf("%d",&a);
	if(a%4==2||a%4==3){
		printf("-1\n");
		return 0;
	}
	if(a%4==0){
		for(int i=0;i<a/4;i++){
			ans[i*2]=i*2+2;
			ans[i*2+1]=a-i*2;
			ans[a-1-i*2]=a-1-i*2;
			ans[a-2-i*2]=i*2+1;
		}
	}else{
		for(int i=0;i<a/4;i++){
			ans[i*2]=i*2+2;
			ans[i*2+1]=a-i*2;
			ans[a-1-i*2]=a-1-i*2;
			ans[a-2-i*2]=i*2+1;
		}
		ans[a/2]=a/2+1;
	}
	for(int i=0;i<a;i++)printf("%d ",ans[i]);
}