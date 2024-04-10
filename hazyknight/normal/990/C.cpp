#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

const int MAXN = 300005;

int n;
int cnt[MAXN];
int MIN[MAXN];
int Cnt[MAXN];

long long ans;

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s;
		for (int j = 0;j < s.size();j++)
		{
			if (s[j] == '(')
				cnt[i]++;
			else
				cnt[i]--;
			MIN[i] = min(MIN[i],cnt[i]);
		}
		if (MIN[i] < cnt[i])
			continue;
		Cnt[-cnt[i]]++;
	}
	for (int i = 1;i <= n;i++)
		if (MIN[i] >= 0 && cnt[i] >= 0)
			ans += Cnt[cnt[i]];
	cout << ans << endl;
	return 0;
}