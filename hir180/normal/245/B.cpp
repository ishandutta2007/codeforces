////}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char x[100];
int main(){
	scanf("%s",&x);
	if(x[0]=='h'){
		if(x[4]=='r' && x[5]=='u'){
		for(int i=6;i<strlen(x);i++){
			if(x[i]=='r' && x[i+1]=='u'){
				printf("http://");
				for(int j=4;j<i;j++){
					printf("%c",x[j]);
				}
				if(i==strlen(x)-2){
				printf(".ru");
				}else{
					printf(".ru/");
				}
				for(int j=i+2;j<strlen(x);j++){
					printf("%c",x[j]);
				}
				break;
			}
		}
		}else{
		for(int i=0;i<strlen(x);i++){
			if(x[i]=='r' && x[i+1]=='u'){
				printf("http://");
				for(int j=4;j<i;j++){
					printf("%c",x[j]);
				}
				if(i==strlen(x)-2){
				printf(".ru");
				}else{
					printf(".ru/");
				}
				for(int j=i+2;j<strlen(x);j++){
					printf("%c",x[j]);
				}
				break;
			}
		}
	}
	}else{
		if(x[3]=='r' && x[4]=='u'){
		for(int i=5;i<strlen(x);i++){
			if(x[i]=='r' && x[i+1]=='u'){
				printf("ftp://");
				for(int j=3;j<i;j++){
					printf("%c",x[j]);
				}
				if(i==strlen(x)-2){
				printf(".ru");
				}else{
					printf(".ru/");
				}
				for(int j=i+2;j<strlen(x);j++){
					printf("%c",x[j]);
				}
				break;
			}
		}
		}else{
		for(int i=0;i<strlen(x);i++){
			if(x[i]=='r' && x[i+1]=='u'){
				printf("ftp://");
				for(int j=3;j<i;j++){
					printf("%c",x[j]);
				}
				if(i==strlen(x)-2){
				printf(".ru");
				}else{
					printf(".ru/");
				}
				for(int j=i+2;j<strlen(x);j++){
					printf("%c",x[j]);
				}
				break;
			}
	}
		}
	}
	printf("\n");
	scanf("%s",&x);
	return 0;
}