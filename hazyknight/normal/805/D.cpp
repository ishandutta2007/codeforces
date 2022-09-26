#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <ctime>

using namespace std;

const int MOD = 1000000007;

int ans;
int f[1000005];

string s;

int main()
{
	cin >> s;
	f[1] = 1;
	for (int i = 2;i < s.size();i++)
		f[i] = ((f[i - 1] << 1) + 1) % MOD;
	int cnt = 0;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == 'a')
			cnt++;
		if (s[i] == 'b')
			(ans += f[cnt]) %= MOD;
	}
	cout << ans << endl;
	return 0;
}