#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;
int n,m;
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

	scanf("%d %d",&n,&m);
	if(n<m){
	for(int i=0;i<n;i++){
		printf("GB");
	}
		for(int i=0;i<m-n;i++){
			printf("G");
		}
	}
else{
	for(int i=0;i<m;i++){
		printf("BG");
	}
		for(int i=0;i<n-m;i++){
			printf("B");
		}
	}
	printf("\n");
	return 0;
}