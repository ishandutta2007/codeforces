#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

string s;
char c[2][1000005];

int n[2];
int pos[2][1000005];

long long sum[1000005][3][3];
long long ans;

int type(char C)
{
	if (C == 'R')
		return 0;
	if (C == 'G')
		return 1;
	if (C == 'B')
		return 2;
}

void calc(int p)
{
	for (int i = 1;i <= n[p];i++)
	{
		pos[p][i] = pos[p][i - 1] + 1;
		while (pos[p][i] <= n[!p] && c[!p][pos[p][i]] != c[p][i])
			pos[p][i]++;
		if (pos[p][i] > n[!p])
			pos[p][i] = n[!p];
	}
}

long long get_sum(int pos,int c1,int c2)
{
	if (pos <= 1)
		return 0;
	if (sum[pos][c1][c2] != -1)
		return sum[pos][c1][c2];
	return sum[pos][c1][c2] = (get_sum(pos - 1,c1,c2) + ((type(c[1][pos]) == c2 && type(c[1][pos - 1]) == c1) ? 1 : 0));
}

int main()
{
	ios::sync_with_stdio(false);
	memset(sum,-1,sizeof(sum));
	cin >> s;
	n[0] = s.size();
	for (int i = 0;i < n[0];i++)
		c[0][i + 1] = s[i];
	cin >> s;
	n[1] = s.size();
	for (int i = 0;i < n[1];i++)
		c[1][i + 1] = s[i];
	calc(0),calc(1);
	int L = 1,R;
	for (int i = 1;i <= n[0];i++)
	{
		R = pos[0][i];
		while (L <= R && L <= n[1] && pos[1][L] < i)
			L++;
		ans += R - L + 1;
		if (L <= R && i > 1 && c[0][i - 1] != c[0][i])
			ans = ans + get_sum(L - 1,type(c[0][i]),type(c[0][i - 1])) - get_sum(R,type(c[0][i]),type(c[0][i - 1]));
	}
	cout << ans << endl;
	return 0;
}