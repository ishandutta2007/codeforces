#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1){
		int a;
		scanf("%d", &a);
		printf("%d ", a & 1 ? a : a - 1);
	}
}