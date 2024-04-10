#include <iostream>

const int MAX_N = 2005;

std::string s, p;
int n, m, f[MAX_N][26], t[MAX_N], g[MAX_N][26], h[MAX_N][MAX_N], x[MAX_N];

void mini(int &a, const int b) { if (a > b) a = b; }
void maxi(int &a, const int b) { if (a < b) a = b; }

int main()
{
	std::cin >> s >> p;
	n = s.size(); m = p.size();
	
	std::fill(f[n], f[n] + 26, MAX_N);
	for (int i = n - 1; i >= 0; --i)
		for (int j = 0; j < 26; ++j)
			f[i][j] = s[i] - 'a' == j ? i + 1 : f[i + 1][j];
			
	for (int i = 1, q = 0; i < m; ++i)
	{
		while (q && p[q] != p[i])
			q = t[q - 1];
		t[i] = q += p[q] == p[i];
	}
	
	g[0][p[0] - 'a'] = 1;
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < 26; ++j)
		{
			int q = i;
			while (q && p[q] - 'a' != j)
				q = t[q - 1];
			g[i][j] = q + (p[q] - 'a' == j);
		}
	
	for (int i = 0; i < MAX_N; ++i)
		std::fill(h[i] + !i, h[i] + MAX_N, MAX_N);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
		{
			const int p = h[i][j];
			if (p <= n)
			{
				const int c = j / m, r = j % m;
				maxi(x[n - i], c);
				if (p < n)
					for (int k = 0; k < 26; ++k)
						mini(h[i + 1][c * m + g[r][k]], f[p][k]);
			}
		}
			
	for (int i = 0; i <= n; ++i)
		std::cout << x[i] << ' ';
	std::cout << '\n';
}