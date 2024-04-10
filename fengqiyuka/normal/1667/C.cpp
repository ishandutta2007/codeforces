#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;scanf("%d",&n);
	
	if(n%3==2||n%3==1){
		if(n%3==1) n++;
		printf("%d\n",2*((n-2)/3)+1);
		int t=((n-2)/3);
		int Max1,Max2;
		if(t%2==1) Max1=t,Max2=t-1;
		else Max1=t-1,Max2=t;
		Max1++;
		for(int i=1;i<=(Max1+1)/2;i++){
			printf("%d %d\n",i,Max1+1-i);
			printf("%d %d\n",Max1+1-i,i);
		}
		for(int i=Max1+1;;i++){
			if(i==(2*t+1+Max1+1-i)){
				printf("%d %d\n",i,i);
				break;
			}
			
			printf("%d %d\n",i,(2*t+1+Max1+1-i));
			printf("%d %d\n",(2*t+1+Max1+1-i),i);
		}
	}
	else{
		printf("%d\n",n/3*2);
		printf("%d %d\n",n/3*2,n/3*2);
		n--;
		int t=((n-2)/3);
		int Max1,Max2;
		if(t%2==1) Max1=t,Max2=t-1;
		else Max1=t-1,Max2=t;
		Max1++;
		for(int i=1;i<=(Max1+1)/2;i++){
			printf("%d %d\n",i,Max1+1-i);
			printf("%d %d\n",Max1+1-i,i);
		}
		for(int i=Max1+1;;i++){
			if(i==(2*t+1+Max1+1-i)){
				printf("%d %d\n",i,i);
				break;
			}
			
			printf("%d %d\n",i,(2*t+1+Max1+1-i));
			printf("%d %d\n",(2*t+1+Max1+1-i),i);
		}
	}
	
	return 0;
}