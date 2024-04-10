#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n,k;
int cnt[26];

string s;

bool mark[400005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k >> s;
	for (int i = 0;i < n;i++)
		cnt[s[i] - 'a']++;
	for (int i = 0;i < 26;i++)
	{
		if (k <= cnt[i])
		{
			cnt[i] -= k;
			k = 0;
			break;
		}
		k -= cnt[i];
		cnt[i] = 0;
	}
	for (int i = n - 1;i >= 0;i--)
		if (cnt[s[i] - 'a'])
		{
			cnt[s[i] - 'a']--;
			mark[i] = true;
		}
	for (int i = 0;i < n;i++)
		if (mark[i])
			cout << s[i];
	cout << endl;
	return 0;
}