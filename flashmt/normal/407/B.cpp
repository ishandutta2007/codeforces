#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int n, p[1111];
long long f[1111][2];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	
	f[1][1] = 0;
	f[1][0] = 1;
	for (int i = 2; i <= n; i++) 
	{
		f[i][1] = (f[i - 1][0] + 1) % BASE;
		if (p[i] == i) f[i][0] = (f[i][1] + 1) % BASE;
		else f[i][0] = (f[i][1] * 2 - f[p[i]][1] + 1 + BASE) % BASE;
	}
	
	cout << (f[n][0] + 1) % BASE << endl;
}