#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	k = 240 - k;
	int ans=0 , t = 0;
	for (int i=1;i<=n;i++) {
		if (ans + 5*i <= k) ans += 5*i , t++;
	}
	printf("%d\n",t);
	return 0;
}