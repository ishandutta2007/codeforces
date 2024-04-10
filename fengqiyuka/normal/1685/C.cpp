#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
char s[N];int Ans[N][2];

int main()
{
	
	int T;scanf("%d",&T);
	
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		
		int Sum=0,L=2*n+1,R=1;
		
		for(int i=1;i<=2*n;i++){
			if(s[i]=='(') Sum++;
			else Sum--;
			if(Sum<0) {L=i;break;}
		}
		Sum=0;
		for(int i=2*n;i>=1;i--){
			if(s[i]==')') Sum++;
			else Sum--;
			if(Sum<0) {R=i;break;}
		}
		
		if(L>R){
			printf("0\n");
			continue;
		}
		
		int Max=0,Max1=0;Sum=0;
		for(int i=1;i<=2*n;i++){
			if(s[i]=='(') Sum++;
			else Sum--;
			if(Max<Sum) Max=Sum,Max1=i;
		}
		
		int Max2=0,Max3=-1e9,Max4=0,Max5=0;Sum=0;
		for(int i=1;i<=2*n;i++){
			if(s[i]=='(') Sum++;
			else Sum--;
			if(Max2<Sum&&i<L) Max2=Sum,Max4=i;
			if(Max3<Sum&&i>=R) Max3=Sum,Max5=i;
		}
		
		if(Max2+Max3>=Max){
			printf("1\n");
			printf("%d %d\n",Max4+1,Max5);
		}
		else{
			printf("2\n");
			printf("%d %d\n",1,Max1);
			printf("%d %d\n",Max1+1,2*n);
		}
	}
	
	return 0;
}