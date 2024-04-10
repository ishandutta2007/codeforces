// Codeforces Beta Round #13
// Problem D -- Triangles
#include <cstring>
#include <iostream>

#define N 500

using namespace std;

int n, m, f[N][N];
long long rx[N], ry[N], bx[N], by[N], a, b, c;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i != n; ++ i)
		cin >> rx[i] >> ry[i];
	for(int i = 0; i != m; ++ i)
		cin >> bx[i] >> by[i];
	memset(f, 0, sizeof(f));
	for(int i = 0; i != n; ++ i)
		for(int j = 0; j != n; ++ j)
			if(rx[i] < rx[j])
			{
				a = ry[j] - ry[i];
				b = rx[i] - rx[j];
				c = - rx[i] * a - ry[i] * b;
				for(int k = 0; k != m; f[i][j] += bx[k] > rx[i] && bx[k] <= rx[j] && a * bx[k] + b * by[k] + c > 0, ++ k);
				f[j][i] = - f[i][j];
			}
	int s = 0;
	for(int i = 0; i != n; ++ i)
		for(int j = i + 1; j != n; ++ j)
			for(int k = j + 1; k != n; ++ k)
				s += f[i][j] + f[j][k] + f[k][i] == 0;
	cout << s << "\n";
	return 0;
}