#include <iostream>
#include <cstdio>

using namespace std;

char s[1050][10];

int main()
{
	int n;
	bool flag = false;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		if (s[i][1] == 'O' && s[i][2] == 'O') {
			if (flag == false) s[i][1] = s[i][2] = '+';
			flag = true;
		}
		if (s[i][4] == 'O' && s[i][5] == 'O') {
			if (flag == false) s[i][4] = s[i][5] = '+';
			flag = true;
		}
	}
	if (!flag) { printf("NO\n"); return 0; }
	printf("YES\n");
	for (int i=1;i<=n;i++) printf("%s\n",s[i]+1);
	return 0;
}