#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int Case, n, Cnts[26], Cntt[26];
char s[N], t[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		scanf("%s%s", s, t);
		for (int i = 0; i < 26; i ++)
			Cnts[i] = Cntt[i] = 0;
		for (int i = 0; i < n; i ++)
		{
			Cnts[s[i] - 'a'] ++;
			Cntt[t[i] - 'a'] ++;
		}
		int flag = 0;
		for (int i = 0; flag != -1 && i < 26; i ++)
		{
			if (Cnts[i] != Cntt[i])
				flag = -1;
			if (Cnts[i] > 1)
				flag = 1;
		}
		if (flag == -1)
			puts("NO");
		else if (flag == 1)
			puts("YES");
		else
		{
			int ics = 0, ict = 0;
			for (int i = 0; i < n; i ++)
				for (int j = i + 1; j < n; j ++)
				{
					if (s[i] > s[j])
						ics ++;
					if (t[i] > t[j])
						ict ++;
				}
			puts(((ics + ict) & 1) ? "NO" : "YES");
		}
	}
	return 0;
}