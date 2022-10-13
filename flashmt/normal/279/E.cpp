#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
using namespace std;

char s[1000100];
int n, tmp;

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i = n - 1; i >= 0; )
		if (s[i] == '1')
		{
			int j = i;
			while (j >= 0 && s[j] == '1') j--;
			if (i - j > 1)
			{
				for (int k = i - 1; k > j; k--) s[k] = '0';
				if (j >= 0) s[j] = '1';
				else tmp++;
			}
			i = j;
		}
		else i--;
		
	int ans = tmp;
	for (int i = 0; i < n; i++) ans += s[i] - '0';
	cout << ans << endl;
}