#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define maxn 30
using namespace std;
int cnt[maxn];
bool che(char a)
{
	return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}
char inp[5005];
int main()
{
	scanf("%s", inp);
	int l = strlen(inp);
	for(int i = 0; i < l;)
	{
		memset(cnt, 0, sizeof(cnt));
		int j = 0;
		int nms = 0, len = 0;
		for(j = i; j < l; j++)
		{
			if(che(inp[j])) len = nms = 0, memset(cnt, 0, sizeof(cnt));
			else
			{
				len++;
				if(!cnt[inp[j] - 'a']) nms++;
				cnt[inp[j] - 'a'] = 1;
				if(len >= 3 && nms >= 2)
					break;
			}
		}
		for(int k = i; k < j; k++)
			printf("%c", inp[k]);
		printf(" ");
		i = j;
	}
	return 0;
}