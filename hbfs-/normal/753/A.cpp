 #include <iostream>
#include <cstdio>

using namespace std;

int ans[1050],cnt;
int main()
{
	int i,n;
	scanf("%d",&n);
	for (i=1;(1+i)*i/2 <= n;i++);
	for (int j=1;j<=i-2;j++) {
		ans[++cnt] = j;
		n-=j;
	}
	if (n) ans[++cnt] = n;
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d%c",ans[i],i==cnt?'\n':' ');
	return 0;
}