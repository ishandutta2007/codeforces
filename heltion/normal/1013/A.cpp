#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, sum = 0, x, y;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1) {
		scanf("%d", &x);
		sum += x;
	}
	for(int i = 0; i < n; i += 1) {
		scanf("%d", &y);
		sum -= y;
	}
	printf(sum >= 0 ? "Yes" : "No");
}