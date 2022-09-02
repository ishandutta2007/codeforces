#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
         if(n<=2){
                 printf("-1\n");
                 return 0;
         }
	if(n==3){
		printf("210\n");
		return 0;
	}
	if(n%6==0){
		printf("1");
		for(int j=0;j<n-4;j++){
			printf("0");
		}
		printf("170\n");
	}else if(n%6==1){
		printf("1");
		for(int j=0;j<n-3;j++){
			printf("0");
		}
		printf("20\n");
	}else if(n%6==2){
		printf("1");
		for(int j=0;j<n-4;j++){
			printf("0");
		}
		printf("200\n");
	}else if(n%6==3){
		printf("1");
		for(int j=0;j<n-4;j++){
			printf("0");
		}
		printf("110\n");
	}else if(n%6==4){
		printf("1");
		for(int j=0;j<n-3;j++){
			printf("0");
		}
		printf("50\n");
	}else if(n%6==5){
		printf("1");
		for(int j=0;j<n-3;j++){
			printf("0");
		}
		printf("80\n");
	}
	return 0;
}