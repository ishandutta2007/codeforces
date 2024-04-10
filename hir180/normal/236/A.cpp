#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
/*(^(^(^(^(^o^)^)^)^)^) ('') */
int i,j,y,sum=0,a,b=0;
char x[101];
int main(){
	scanf("%s",&x);
	for(i=0;i<strlen(x);i++){
		for(j=0;j<i;j++){
			if(x[i]==x[j]){
				b=1;
			}
		}
		if(b==0){
			sum++;
		}
		b=0;
	}
	if(sum%2==0){
		printf("CHAT WITH HER!\n");
	}else{
		printf("IGNORE HIM!\n");
	}
	return 0;
}