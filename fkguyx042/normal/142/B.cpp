#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n == 1 || m == 1) {
		printf("%d\n", max(n,m));
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < n;i ++) {
		for(int j = 0;j < m; j ++) {
			ans += ((i^j^1)&1);
		}
	}
	ans = max(4, ans);
	int tans = 0;
	for(int i = 0; i < max(n,m);i ++) {
		if((i&3) <= 1) {
			tans += 2;
		}
	}
	ans = max(ans,tans);
	printf("%d\n", ans);
	return 0;
}