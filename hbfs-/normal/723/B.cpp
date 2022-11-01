#include <iostream>
#include <cstdio>

#define N 1050

using namespace std;

int n;
char s[N];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	bool flag = false;
	int l = 0,tot = 0 , ans = 0;
	for (int i=1;i<=n;i++) {
		if (s[i] == '_') {
			if (flag && l>0) tot++;
			if (!flag) ans = max(ans,l);
			l = 0;
			continue;
		}
		if (s[i] == '(') {
			ans = max(ans,l);
			flag = true;
			l = 0;
			continue;
		}
		if (s[i] == ')') {
			if (l > 0) tot++;
			l = 0; flag = false;
			continue;
		}
		l++;
	}
	ans = max(ans,l);
	printf("%d %d\n",ans,tot);
	return 0;
}