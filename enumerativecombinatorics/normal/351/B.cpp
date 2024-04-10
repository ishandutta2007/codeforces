#include<stdio.h>
int b[3000];
int main(){
	int a;
	scanf("%d",&a);
	int r=0;
	for(int i=0;i<a;i++)
		scanf("%d",b+i);
	for(int i=0;i<a;i++)
		for(int j=i+1;j<a;j++)
			if(b[i]>b[j])r++;
	if(r%2)printf("%d\n",2*r-1);
	else printf("%d\n",2*r);
}