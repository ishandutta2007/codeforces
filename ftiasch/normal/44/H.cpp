#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

char s[60];
int n;
long long f[60][10];

int main()
{
	gets(s + 1);
	n = strlen(s + 1);
	for (int j = 0; j < 10; ++j) f[1][j] = 1;
	for (int i = 1; i < n; ++i) for (int j = 0; j < 10; ++j) {
		int sum = j + s[i + 1] - 48;
		if (sum & 1) {
			f[i + 1][sum - 1 >> 1] += f[i][j];
			f[i + 1][sum + 1 >> 1] += f[i][j];
		} else 
			f[i + 1][sum >> 1] += f[i][j];
	}
	long long ans = 0;
	for (int j = 0; j < 10; ++j) ans += f[n][j];
	bool flag = true;
	for (int i = 2; i <= n; ++i) {
		int sum = s[i - 1] + s[i] - 48 * 2;
		if (sum & 1) {
			if ((sum - 1 >> 1) != s[i] - 48 && (sum + 1 >> 1) != s[i] - 48) flag = false;
		} else if ((sum >> 1) != s[i] - 48) flag = false;
	}
	if (flag) --ans;
	cout << ans << endl;
}