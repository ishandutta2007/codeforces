#include <bits/stdc++.h>
using namespace std; 
int main(){
	int n; cin >> n;
	int ans = 0x3f3f3f3f, xx, yy;
	for (int i = 0; i <= n / 4; i++){
		if ((n - 4 * i) % 7 != 0) continue;
		int j = (n - 4 * i) / 7;
		if (ans > i + j || ans == i + j && i > xx){
			ans = i + j, xx = i, yy = j;
		}
	}
	if (ans == 0x3f3f3f3f){
		printf("-1\n");
		return 0;
	}
	while (xx--) putchar('4');
	while (yy--) putchar('7');
	putchar('\n');
	return 0;
}