#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> P;
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define p push
char str[1000005];
int num[2]={};
int main(){
	scanf("%s",&str);
	int leng=strlen(str);
	for(int i=0;i<leng;i++){
		if(str[i]=='x'){
			num[0]++;
		}else{
			num[1]++;
		}
	}
	if(num[0]>num[1]){
		for(int i=0;i<num[0]-num[1];i++){
			printf("x");
		}
		printf("\n");
	}else{
		for(int i=0;i<num[1]-num[0];i++){
			printf("y");
		}
		printf("\n");
	}
	return 0;
}