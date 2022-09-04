#include<bits/stdc++.h>
using namespace std;
main(){
	int n;
	scanf("%d",&n);
	if(n%2==1){
		printf("1");
		for(int i=3;i<=n;i+=2)
		printf(" %d",i);
		for(int i=n-2;i>=1;i-=2)
		printf(" %d",i);
		printf(" %d",n);
		for(int i=2;i<n;i+=2)
		printf(" %d",i);
		for(int i=n-1;i>1;i-=2)
		printf(" %d",i);
	} 
	else{
		printf("2");
		for(int i=4;i<=n;i+=2)
		printf(" %d",i);
		for(int i=n-2;i>=2;i-=2)
		printf(" %d",i);
		printf(" %d",n);
		for(int i=1;i<n;i+=2)
		printf(" %d",i);
		for(int i=n-1;i>=1;i-=2)
		printf(" %d",i);
	} 
	printf("\n");
	return 0;
}