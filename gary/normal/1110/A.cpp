#include<bits/stdc++.h>
using namespace std;
int main(){
	int b,k,tot=0;
	scanf("%d %d",&b,&k);
	for(int i=k-1;i>=0;i--){
		int a;
		scanf("%d",&a);
		if((b%2==0&&i!=0)||a%2==0){
				
		}
		else{
			tot++;
		}
	}
//	cout<<tot<<endl;
	if(tot%2==0){
		printf("even\n");
	}
	else{
		printf("odd\n");
	}
	return 0;
}