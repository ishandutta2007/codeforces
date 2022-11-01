#include <iostream>
#include <cstdio>

using namespace std;

int ans[1050],n,cnt;
char s[1050];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int tot = 0;
	for (int i=1;i<=n;i++) {
		if (s[i] == 'W') {
			if (tot > 0) ans[++cnt] = tot;
			tot = 0;
		} else {
			tot++;
		}
	}
	
	if (tot) ans[++cnt] = tot;
	
	printf("%d\n",cnt);
		if (cnt) printf("%d",ans[1]);
		for (int i=2;i<=cnt;i++) printf(" %d",ans[i]);
		printf("\n");
		
	return 0;
}