#include <iostream>
#include <cstdio>
#include <cstring>

char line[10011];

int main()
{
	int n;
	scanf("%d ", &n);
	fgets(line, 10010, stdin);
	int ret = 0;
	int last = 0;
	int len = strlen(line);

	int start = 0;
	for (int i = 1; i < len; i++)
		if (line[i] == '.' || line[i] == '?' || line[i] == '!') {
			int len2 = i-start+1;
			if (len2 > n) {
				printf("Impossible\n");
				return 0;
			}
			if (last == 0)
				last = len2;
			else if (last+1+len2 <= n)
				last += 1+len2;
			else {
				ret ++;
				last = len2;
			}
			start = i+2;
			i++;
		}
	if (last != 0)
		ret ++;

	printf("%d\n", ret);

	return 0;
}