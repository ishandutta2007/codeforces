#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

long long f[1000100][5];
int n;
string s;

int canBeBomb(char ch)
{
	return ch == '*' || ch == '?';
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> s;
	n = s.size();
	
	if (s[0] == '?') f[0][0] = f[0][2] = f[0][4] = 1;
	if (s[0] == '0') f[0][0] = 1;
	if (s[0] == '1') f[0][2] = 1;
	if (s[0] == '2') 
	{
		cout << 0 << endl;
		return 0;
	}
	if (s[0] == '*') f[0][4] = 1;
	
	for (int i = 1; i < n; i++)
	{
		if (s[i] == '0' || s[i] == '?')
		{
			f[i][0] += f[i - 1][0] + f[i - 1][1];
			f[i][0] %= BASE;
		}
		
		if (s[i] == '1' || s[i] == '?')
		{
			f[i][1] += f[i - 1][4];
			f[i][1] %= BASE;
			f[i][2] += f[i - 1][0] + f[i - 1][1];
			f[i][2] %= BASE;
		}
		
		if (s[i] == '2' || s[i] == '?')
		{
			f[i][3] += f[i - 1][4];
			f[i][3] %= BASE;
		}
		
		if (s[i] == '*' || s[i] == '?')
		{
			f[i][4] += f[i - 1][2] + f[i - 1][3] + f[i - 1][4];
			f[i][4] %= BASE;
		}
	}
	
	long long ans = (f[n - 1][0] + f[n - 1][1] + f[n - 1][4]) % BASE;
	cout << ans << endl;
}