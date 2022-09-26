#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,q,x;
int a[1505];
int f[1505][1505];
int ans[26][1505];

char c;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1;i <= n;i++)
		a[i] = s[i - 1] - 'a';
	for (int cha = 0;cha < 26;cha++)
	{
		memset(f,0,sizeof(f));
		for (int i = 1;i <= n;i++)
			if (a[i] == cha)
				f[0][i] = f[0][i - 1] + 1;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				f[i][j] = f[i - 1][j];
				if (a[j] == cha)
					f[i][j] = max(f[i][j],f[i][j - 1] + 1);
				else
					f[i][j] = max(f[i][j],f[i - 1][j - 1] + 1);
				ans[cha][i] = max(ans[cha][i],f[i][j]);
			}
		}
	}
	cin >> q;
	for (int i = 1;i <= q;i++)
	{
		cin >> x >> c;
		cout << ans[c - 'a'][x] << endl;
	}
	return 0;
}