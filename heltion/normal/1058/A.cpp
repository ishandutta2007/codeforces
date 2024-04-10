#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, x;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1){
		scanf("%d", &x);
		if(x){
			printf("HARD");
			return 0;
		}
	}
	printf("EASY");
}