#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,tot1=0,tot2=0;
	int v1[2001];//ou
	int v2[2001];//ji
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		if(num%2==0){
			v1[++tot1]=num;
		}
		else{
			v2[++tot2]=num;
		}
	}
	sort(v1+1,v1+tot1+1);
	sort(v2+1,v2+tot2+1);
	if(abs(tot1-tot2)==1){
		printf("0\n");	
	}
	else{int sum=0;
		if(tot1>tot2){
			tot1-=tot2;
			tot1--;
//			int sum=0;
			for(int i=1;i<=tot1;i++) sum+=v1[i];
		}
		else{
			tot2-=tot1;
			tot2--;
			
			for(int i=1;i<=tot2;i++) sum+=v2[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}