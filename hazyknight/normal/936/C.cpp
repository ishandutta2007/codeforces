#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 

using namespace std;

int n;
int cnt[26];
string s,t;

void rev(int len)
{
	cout << len << ' ';
	reverse(s.begin(),s.begin() + n - len);
	reverse(s.begin(),s.end());
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> s >> t;
	for (int i = 0;i < n;i++)
		cnt[s[i] - 'a']++,cnt[t[i] - 'a']--;
	for (int i = 0;i < 26;i++)
		if (cnt[i])
		{
			cout << -1 << endl;
			return 0;
		}
	cout << n * 3 + (n & 1) << endl;
	int mark = 0;
	for (int i = 0;i < n;i++)
	{
		int a = i,b,c = 1,d;
		for (int j = i;j < n;j++)
			if (s[j] == t[i])
			{
				b = j - i;
				d = n - 1 - j;
			}
		if (!mark)
		{
			rev(b + c + d);
			rev(a + b);
			rev(c);
			mark = 1;
		}
		else
		{
			rev(d);
			rev(b + c);
			rev(a);
			mark = 0;
		}
	}
	if (mark)
		rev(s.size());
	cout << endl;
	return 0;
}