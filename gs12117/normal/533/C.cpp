#include<stdio.h>
int ax,ay,bx,by;
int main(){
	scanf("%d%d%d%d",&ax,&ay,&bx,&by);
	if(ax<=bx&&ay<=by){
		printf("Polycarp");
	}
	else if(bx>=ax+ay){
		printf("Polycarp");
	}
	else if(by>=ax+ay){
		printf("Polycarp");
	}
	else{
		printf("Vasiliy");
	}
}