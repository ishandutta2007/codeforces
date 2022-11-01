#include <iostream>
#include <cstdio>

using namespace std;
int n;
char s[2050],ans[2050];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int mid = (n+1) / 2 , c = 0;
	if (n&1) {
		ans[mid] = s[++c];
		for (int i=1;i<=n/2;i++) ans[mid-i] = s[++c] , ans[mid+i] = s[++c];
	} else {
		for (int i=1;i<=n/2;i++) ans[mid-i+1] = s[++c] , ans[mid+i] = s[++c];
	}
	for (int i=1;i<=n;i++) printf("%c",ans[i]);
	printf("\n");
	return 0;
}