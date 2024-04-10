#include<stdio.h>
int main(){
	int i;
	scanf("%d",&i);
	i++;
	for(;;i++){
		if(i/1000!=(i/100)%10&&i/1000!=(i/10)%10&&i/1000!=i%10&&(i/100)%10!=(i/10)%10&&(i/100)%10!=i%10&&(i/10)%10!=i%10){
			printf("%d",i);
			return 0;
		}
	}
}