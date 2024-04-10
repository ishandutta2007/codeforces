#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		puts("2");
		if(n==2) {
			puts("1 2");
			continue;
		}
		printf("%d %d\n",n-2,n);
		printf("%d %d\n",n-1,n-1);
		for(int i=1;i+2<n;i++)
			printf("%d %d\n",n-i-2,n-i);
	}
	return 0;
}