#include<stdio.h>
char a[100100];
int main(){
	int i;
	scanf("%s",a);
	for(i=0;a[i];i++){
		if(a[i]=='0'){
			a[i]=0;
			if(a[i+1]!=0)printf("%s%s",a,a+i+1);
			else printf("%s",a);
			return 0;
		}
	}
	printf("%s",a+1);
	return 0;
}