#include<bits/stdc++.h>
using namespace std;
int main(){
	int num[15]={0};//10
	int tempnum,weishu=0;
	scanf("%d",&tempnum);
	while(tempnum!=0) {
		num[++weishu]=tempnum%10;// 
		tempnum/=10;
	}
//	for(int i=weishu;i>=1;i--) cout<<num[i]; //
	sort(num+1,num+1+weishu); 
	for(int i=1;i<=weishu;i++){
		if(num[i]!=0){// 
			swap(num[i],num[1]);
			break;
		}
	} 
	string bob;
	cin>>bob;
	if(bob.length()==1&&bob[0]=='0'&&tempnum==0){
		printf("OK");
		return 0;
	}
	if(bob.length()!=weishu){
		printf("WRONG_ANSWER");
		return 0;
	}
	for(int i=0;i<weishu;i++){
		if(bob[i]-'0'!=num[i+1]){
			printf("WRONG_ANSWER");
			return 0;
		}
	}
	printf("OK");
	return 0;
}