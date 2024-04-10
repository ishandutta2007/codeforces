#include<stdio.h>
char t[32];
char ans[32];
int a,b,c,d,e,f,g,max;
int main(){
	int n;
	max=-100000;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%d%d%d%d%d%d%d",t,&a,&b,&c,&d,&e,&f,&g);
		if(c+d+e+f+g+100*a-50*b>max){
			for(int j=0;j<32;j++)ans[j]=t[j];
			max=c+d+e+f+g+100*a-50*b;
		}
	}
	printf("%s\n",ans);
}