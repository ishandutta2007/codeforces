#include <bits/stdc++.h>
using namespace std;

char buf[1000010];
string s;

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", buf), s = buf;
	for (int i = 1; i <= n; i++){
		if (i * (i + 1) / 2 - 1 >= n) break;
		printf("%c", s[i * (i + 1) / 2 - 1]);
	}
	printf("\n");
	return 0;
}