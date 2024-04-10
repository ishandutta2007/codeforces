#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		if (d < l) printf("%d\n", d);
		else printf("%d\n", r / d * d + d);
	}
	return 0;
}