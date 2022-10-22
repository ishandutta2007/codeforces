#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,totz,totm;
	scanf("%d",&n);
	totz=ceil(double(n)/2);
	totm=ceil(double(n)/2);
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp>0) totz--;
		if(tmp<0) totm--;	
	}
	if(totz<=0||totm<=0){
		if(totz<=0) 
		printf("8\n");
		else 
			printf("-8\n");
	} 
	else printf("0\n");
}