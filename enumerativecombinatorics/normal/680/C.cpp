#include<stdio.h>
#include<algorithm>
using namespace std;
int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
char in[100];
int main(){
	int at=-1;
	for(int i=0;i<4;i++){
		printf("%d\n",pr[i]);
		fflush(stdout);
		scanf("%s",in);
		if(in[0]=='y'){
			at=i;break;
		}
	}
	if(at==-1){
		printf("prime\n");return 0;
	}
	for(int i=0;i<15;i++){
		if(pr[at]*pr[i]>100)break;
		printf("%d\n",pr[at]*pr[i]);
		fflush(stdout);
		scanf("%s",in);
		if(in[0]=='y'){
			printf("composite\n");return 0;
		}
	}
	printf("prime\n");return 0;
}