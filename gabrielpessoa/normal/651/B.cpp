#include <bits/stdc++.h>
using namespace std;


int n, x;
int amount[1005];
int amountRepeated[1005];

int main() {
	scanf("%d", &n);
	int total;
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		if(amountRepeated[++amount[x]]++ > 0) {
			total++;
		}
	}
	printf("%d", total);
	
	return 0;
}