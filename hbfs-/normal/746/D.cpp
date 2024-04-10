#include <iostream>
#include <cstdio>
#define N 200050

using namespace std;
int n,k,a,b;
int ans[N];
int main()
{
	scanf("%d%d%d%d",&n,&k,&a,&b);
	int t = 1;
	for (int i=1;i<=n;i++) {
		if (a > b) {
			if (ans[i-1] == 1) ++t;
			if (t>k) {
				t = 1;
				ans[i] = 2;
				b--;
			} else {
				ans[i] = 1;
				a--;
			}
		} else {
			if (ans[i-1] == 2) ++t;
			if (t>k) {
				t = 1;
				ans[i] = 1;
				a--;
			} else {
				ans[i] = 2;
				b--;
			}
		}
	}
	if (a<0 || b<0) {
		puts("NO"); return 0;
	}
	for (int i=1;i<=n;i++) printf("%c",ans[i]==1?'G':'B');
	printf("\n");
	return 0;
}