#include <bits/stdc++.h>
using namespace std;
char s[10000];
int main()
{
	scanf(" %s", s + 1);
	bool bz = 0, bz1 = 0;
	for (int i = 1; i <= strlen(s + 1); i ++)
		if (s[i] == '1') {
			if (!bz) printf("4 1\n");
			else	
				printf("4 3\n");
			bz ^= 1;
		} else {
			if (!bz1) printf("1 4\n");
			else
				printf("3 4\n");
			bz1 ^= 1;
		}
	return 0;
}