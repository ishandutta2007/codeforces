#include <string>
#include <iostream>
#include <vector>

using namespace std;

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

char s[10][10];
int dp[10][10][10];

int main() {
	for (int i = 1; i <= 8; ++i) {
		string alfa; cin >> alfa;
		for (int j = 0; j < 8; ++j)
			s[i][j + 1] = alfa[j];
	}

	s[8][1] = s[1][8] = '.';

	dp[0][8][1] = 1;
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j)
			for (int k = 1; k <= 8; ++k)
				if (dp[i - 1][j][k] == 1)
					for (int p = 0; p < 9; ++p)
						if (s[j + dx[p]][k + dy[p]] == '.')
							dp[i][j + dx[p]][k + dy[p]] = 1;

		for (int j = 8; j > 0; --j)
			for (int k = 1; k <= 8; ++k) {
				if (j > 1)
					s[j][k] = s[j - 1][k];
				else
					s[1][k] = '.';
				if (s[j][k] == 'S')
					dp[i][j][k] = 0;
		}
	}

	for (int i = 1; i <= 8; ++i)
		for (int j = 1; j <= 8; ++j)
			if (dp[8][i][j] == 1) {
				cout << "WIN";
				return 0;
			}
	
	cout << "LOSE";
	return 0;
}