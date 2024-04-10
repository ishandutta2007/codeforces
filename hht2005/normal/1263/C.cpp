#include<bits/stdc++.h>
using namespace std;
int s[100010];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		int cnt=0;
		scanf("%d",&n);
		for(int i=1,j=0;i<=n;i=j+1) {
			s[++cnt]=n/i;
			j=n/(n/i);
		}
		printf("%d\n0",cnt+1);
		for(int i=cnt;i>=1;i--)
			printf(" %d",s[i]);
		puts("");
	}
	return 0;
}