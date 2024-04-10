#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int now = 0;
	for (int i = 1; i < n; i++){
		now += i, now %= n;
		printf("%d ", now + 1);
	}
	printf("\n"); 
	return 0;
}