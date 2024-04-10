#include <bits/stdc++.h>
using namespace std;
struct node{
	char c;
	int before, next;
}f[1000001];
char s[1000001];
int n, ans;
int main()
{
	scanf(" %s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n ; i ++)
		f[i].c = s[i], f[i].before = i - 1, f[i].next = i + 1;
	int x = 1;
	while (1)
	{
		if (f[x].next != n + 1 && f[f[x].next].c == f[x].c) {
			ans ++;
			if (f[x].before) {
				f[f[x].before].next = f[f[x].next].next;
				if (f[f[x].next].next != n + 1) f[f[f[x].next].next].before = f[x].before;
				x = f[x].before;
			} else
			if (f[f[x].next].next != n + 1)f[f[f[x].next].next].before = 0, x = f[f[x].next].next;
			else
				break;
		}
		else
		if (f[x].next != n + 1) x = f[x].next;
		else
			break;
	}
	(ans & 1)?printf("Yes"):printf("No");
	return 0;
}