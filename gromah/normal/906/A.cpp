#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, ans;
bool ok, Flag[26], _Flag[26];
char c, op[9], s[N];

int main()
{
	for (int i = 0; i < 26; i ++)
		Flag[i] = 0;
	scanf("%d", &n);
	for (int T = 1; T <= n; T ++)
	{
		scanf("%s%s", op, s);
		if (op[0] == '!')
		{
			if (ok) ans ++;
			else
			{
				for (int i = 0; i < 26; i ++)
					_Flag[i] = 1;
				for (int i = 0; s[i]; i ++)
					_Flag[s[i] - 'a'] = 0;
				int ret = 26;
				for (int i = 0; i < 26; i ++)
				{
					Flag[i] |= _Flag[i];
					if (Flag[i]) ret --;
					else c = i;
				}
				if (ret == 1) ok = 1;
			}
		}
		else if (op[0] == '.')
		{
			for (int i = 0; i < 26; i ++)
				_Flag[i] = 0;
			for (int i = 0; s[i]; i ++)
				_Flag[s[i] - 'a'] = 1;
			int ret = 26;
			for (int i = 0; i < 26; i ++)
			{
				Flag[i] |= _Flag[i];
				if (Flag[i]) ret --;
				else c = i;
			}
			if (ret == 1) ok = 1;
		}
		else if (op[0] == '?')
		{
			if (T < n)
			{
				if (ok) ans ++;
				else
				{
					Flag[s[0] - 'a'] = 1;
					int ret = 26;
					for (int i = 0; i < 26; i ++)
					{
						if (Flag[i]) ret --;
						else c = i;
					}
					if (ret == 1) ok = 1;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}