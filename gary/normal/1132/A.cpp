#include<bits/stdc++.h>
using namespace std;
int main(){
	int cnt1,cnt2,cnt3,cnt4;
	scanf("%d %d %d %d",&cnt1,&cnt2,&cnt3,&cnt4);
	if(cnt1!=cnt4){
		printf("0\n");
		return 0;
	}
	if(cnt3!=0){
		if(cnt1==0){
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");
	return 0;
}