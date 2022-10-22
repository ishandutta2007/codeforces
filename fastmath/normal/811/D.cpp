#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>


using namespace std;


int inf = 1e9;
long long big_inf = 1e18;


int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	char a[102][102];

	int x1, y1;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			cin >> a[i][j];

			if (a[i][j] == 'F'){
				x1 = i;
				y1 = j;
			}
		}
	}


	pair <int, char> dp[102][102];

	for (int i = 0; i <= n + 1; ++i){
		for (int j = 0; j <= m + 1; ++j){
			dp[i][j].first = inf;
		}
	}

	dp[x1][y1].first = 0;

	for (int k = 0; k < 10000; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				if (a[i][j] == '*'){
					continue;
				}

				int mn = min(min(min(min(dp[i][j].first, dp[i - 1][j].first + 1), dp[i + 1][j].first + 1), dp[i][j - 1].first + 1), dp[i][j + 1].first + 1);

				if (mn == dp[i - 1][j].first + 1){
					dp[i][j].second = 'U';
				}
				else if (mn == dp[i + 1][j].first + 1){
					dp[i][j].second = 'D';
				}
				else if (mn == dp[i][j + 1].first + 1){
					dp[i][j].second = 'R';
				}
				else if (mn == dp[i][j - 1].first + 1){
					dp[i][j].second = 'L';
				}

				dp[i][j].first = mn;
			}
		}
	}


	int x, y, x2, y2;
	x = 1;
	y = 1;
	int f = 0;
	int s = 0;

	while (!(x == x1 && y == y1)){
		if (dp[x][y].second == 'L'){
			if (f == 0){
				cout << "L\n";
				cin >> x2 >> y2;
				fflush(stdout);

				if (x2 == x && y2 == y){
					f = 2;
				}
				else{
					f = 1;
				}
			}
			else if (f == 2){
				cout << "R\n";
				cin >> x2 >> y2;
				fflush(stdout);
			}
			else if (f == 1){
				cout << "L\n";
				cin >> x2 >> y2;
				fflush(stdout);
			}

			x = x2;
			y = y2;
		}
		else if (dp[x][y].second == 'R'){
			if (f == 0){
				cout << "R\n";
				cin >> x2 >> y2;
				fflush(stdout);

				if (x2 == x && y2 == y){
					f = 2;
				}
				else{
					f = 1;
				}
			}
			else if (f == 2){
				cout << "L\n";
				cin >> x2 >> y2;
				fflush(stdout);
			}
			else if (f == 1){
				cout << "R\n";
				cin >> x2 >> y2;
				fflush(stdout);
			}

			x = x2;
			y = y2;
		}
		else if (dp[x][y].second == 'U'){
			if (s == 0){
				cout << "U\n";
				cin >> x2 >> y2;
				fflush(stdout);

				if (x2 == x && y2 == y){
					s = 2;
				}
				else{
					s = 1;
				}
			}
			else if (s == 2){
				cout << "D\n";
				cin >> x2 >> y2;
				fflush(stdout);
			}
			else if (s == 1){
				cout << "U\n";
				cin >> x2 >> y2;
				fflush(stdout);
			}

			x = x2;
			y = y2;
		}
		else if (dp[x][y].second == 'D'){
			if (s == 0){
				cout << "D\n";
				cin >> x2 >> y2;
				fflush(stdout);

				if (x2 == x && y2 == y){
					s = 2;
				}
				else{
					s = 1;
				}
			}
			else if (s == 2){
				cout << "U\n";
				cin >> x2 >> y2;
				fflush(stdout);
			}
			else if (s == 1){
				cout << "D\n";
				cin >> x2 >> y2;
				fflush(stdout);
			}

			x = x2;
			y = y2;
		}
	}


	return 0;
}