#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 1005 
using namespace std;
char x[maxn], y[maxn];
int nm[27];
int ans = 0;

int main()
{
	scanf("%s", x);
	scanf("%s", y);
	memset(nm, -1, sizeof(nm));
	bool flag = true;
	for(int i = 0; i < strlen(x); i++)
	{
		int n1 = x[i] - 'a', n2 = y[i] - 'a';
		if( (nm[n1] != -1 && nm[n1] != n2) || (nm[n2] != -1 && nm[n2] != n1))
			flag = false;
		else
			if(nm[n1] == -1)
			{
				nm[n1] = n2, nm[n2] = n1;
				if(n1 != n2)
					ans++;
			}
	}
	if(!flag)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n", ans);
	for(int i = 0; i < 27; i++)
	{
		if(nm[i] > i)
			printf("%c %c\n", char(i + 'a'), char(nm[i] + 'a'));
	}
	return 0;
}