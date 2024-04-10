#include <bits/stdc++.h>
using namespace std;

int main() {
	int weight;
	scanf("%d", &weight);
	if(weight > 2 && weight % 2 == 0) {
	    puts("YES");
	} else {
	    puts("NO");
	}
	return 0;
}