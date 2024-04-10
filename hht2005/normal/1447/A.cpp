#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
			printf("%d ",i);
		puts("");
	}
	return 0;
}