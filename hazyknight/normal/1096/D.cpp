#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n;

ll a[MAXN];
ll f[MAXN][4];

string s; 

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		if (s[i - 1] == 'h')
		{
			f[i][0] = f[i - 1][0] + a[i];
			f[i][1] = min(f[i - 1][0],f[i - 1][1]);
			f[i][2] = f[i - 1][2];
			f[i][3] = f[i - 1][3];
		}
		else if (s[i - 1] == 'a')
		{
			f[i][0] = f[i - 1][0];
			f[i][1] = f[i - 1][1] + a[i];
			f[i][2] = min(f[i - 1][1],f[i - 1][2]);
			f[i][3] = f[i - 1][3];
		}
		else if (s[i - 1] == 'r')
		{
			f[i][0] = f[i - 1][0];
			f[i][1] = f[i - 1][1];
			f[i][2] = f[i - 1][2] + a[i];
			f[i][3] = min(f[i - 1][2],f[i - 1][3]);
		}
		else if (s[i - 1] == 'd')
		{
			f[i][0] = f[i - 1][0];
			f[i][1] = f[i - 1][1];
			f[i][2] = f[i - 1][2];
			f[i][3] = f[i - 1][3] + a[i];
		}
		else
		{
			f[i][0] = f[i - 1][0];
			f[i][1] = f[i - 1][1];
			f[i][2] = f[i - 1][2];
			f[i][3] = f[i - 1][3];
		}
	}
	cout << min(min(f[n][0],f[n][1]),min(f[n][2],f[n][3])) << endl;
	return 0;
}