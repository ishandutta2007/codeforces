#include <bits/stdc++.h>

using namespace std;

int main() {
	int N,x=0;
	char ch[6];
	scanf("%d",&N);
	while(N--) {
		scanf(" %s",ch);
		x += ch[1]=='+' ? 1 : -1;
	}
	printf("%d\n",x);
	return 0;
}