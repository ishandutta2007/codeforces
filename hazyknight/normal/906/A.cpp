#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,ans;
bool mark[26];
bool can[26];
int flag = -1;
char type;

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0;i < 26;i++)
		can[i] = true;
	for (int i = 1;i <= n;i++)
	{
		memset(mark,0,sizeof(mark));
		cin >> type >> s;
		for (int j = 0;j < s.size();j++)
			mark[s[j] - 'a'] = true;
		if (flag != -1)
		{
			if (type == '!')
				ans++;
			if (type == '?' && s[0] - 'a' != flag)
				ans++;
		}
		else
		{
			if (type == '!')
			{
				for (int j = 0;j < 26;j++)
					if (!mark[j])
						can[j] = false;
			}
			if (type == '.')
			{
				for (int j = 0;j < 26;j++)
					if (mark[j])
						can[j] = false;
			}
			if (type == '?')
				can[s[0] - 'a'] = false;
			int cnt = 0;
			for (int j = 0;j < 26;j++)
			{
				if (can[j])
					flag = j;
				cnt += can[j];
			}
			if (cnt != 1)
				flag = -1;
		}
	}
	cout << ans << endl;
	return 0;
}