#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int BASE = int(1e9) + 7;

string a, b;
long long f[100100][3];
int n;

int main()
{
	int unknown = 0;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) unknown += (a[i] == '?') + (b[i] == '?');
	
	long long total = 1;
	for (int i = 0; i < unknown; i++) total *= 10, total %= BASE;
	
	f[0][0] = 1;
	for (int i = 0; i < n; i++)
		if (a[i] == '?' && b[i] == '?')
		{
			f[i + 1][0] += f[i][0] * 10; f[i + 1][0] %= BASE;
			f[i + 1][1] += (f[i][1] * 11 + f[i][0] * 9) * 5; f[i + 1][1] %= BASE;
			f[i + 1][2] += (f[i][2] * 11 + f[i][0] * 9) * 5; f[i + 1][2] %= BASE;
		}
		else
			if (a[i] != '?' && b[i] != '?')
			{
				if (a[i] == b[i])
					for (int j = 0; j < 3; j++)
						f[i + 1][j] += f[i][j], f[i + 1][j] %= BASE;
				if (a[i] > b[i])
					f[i + 1][1] += f[i][0] + f[i][1], f[i + 1][1] %= BASE;
				if (a[i] < b[i])
					f[i + 1][2] += f[i][0] + f[i][2], f[i + 1][2] %= BASE;
			}
			else
				if (a[i] == '?')
				{
					int c = b[i] - '0';
					f[i + 1][0] += f[i][0]; f[i + 1][0] %= BASE;
					f[i + 1][1] += f[i][0] * (9 - c) + f[i][1] * (10 - c); f[i + 1][1] %= BASE;
					f[i + 1][2] += f[i][0] * c + f[i][2] * (c + 1); f[i + 1][2] %= BASE;
				}
				else
				{
					int c = a[i] - '0';
					f[i + 1][0] += f[i][0]; f[i + 1][0] %= BASE;
					f[i + 1][1] += f[i][0] * c + f[i][1] * (c + 1); f[i + 1][1] %= BASE;
					f[i + 1][2] += f[i][0] * (9 - c) + f[i][2] * (10 - c); f[i + 1][2] %= BASE;
				}
				
	cout << (total - f[n][0] - f[n][1] - f[n][2] + BASE * 5LL) % BASE << endl;
}