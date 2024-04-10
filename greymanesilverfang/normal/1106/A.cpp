#include <iostream>
const int N = 501;
char m[N][N];

int main()
{
	int n; std::cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			std::cin >> m[i][j];
	int res = 0;
	for (int i = 2; i < n; ++i)
		for (int j = 2; j < n; ++j)
			if (m[i][j] == 'X'
			 && m[i - 1][j - 1] == 'X'
			 && m[i - 1][j + 1] == 'X'
			 && m[i + 1][j - 1] == 'X'
			 && m[i + 1][j + 1] == 'X')
				++res;
	std::cout << res;
	return 0;
}