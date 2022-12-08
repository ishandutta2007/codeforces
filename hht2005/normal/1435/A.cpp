#include<bits/stdc++.h>
using namespace std;
int a[110];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=1;i<=n;i+=2)
			printf("%d %d ",-a[i+1],a[i]);
		puts("");
	}
	return 0;
}