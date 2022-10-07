#include<stdio.h>
int n;
char a[20];
int b[12];
int main(){
	int i;
	scanf("%d",&n);
	scanf("%s",a);
	for(i=0;i<n;i++){
		a[i]-='0';
		if(a[i]==2)b[2]++;
		if(a[i]==3)b[3]++;
		if(a[i]==4){
			b[3]++;
			b[2]++;
			b[2]++;
		}
		if(a[i]==5)b[5]++;
		if(a[i]==6){
			b[5]++;
			b[3]++;
		}
		if(a[i]==7)b[7]++;
		if(a[i]==8){
			b[7]++;
			b[2]++;
			b[2]++;
			b[2]++;
		}
		if(a[i]==9){
			b[7]++;
			b[3]++;
			b[3]++;
			b[2]++;
		}
	}
	for(i=7;i>1;i--){
		while(b[i]){
			b[i]--;
			printf("%d",i);
		}
	}
}