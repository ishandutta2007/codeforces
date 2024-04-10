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


int g[100][100];


int main(){
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> g[i][j];
		}
	}

	vector <int> mn1(100, inf), mn2(100, inf);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			mn1[i] = min(mn1[i], g[i][j]);
			mn2[j] = min(mn2[j], g[i][j]);
		}
	}

	int ans = inf;
	vector <pair <int, int> > ans1;
	for (int i = 0; i <= mn1[0]; ++i){
		bool can = true;
		int a[100], b[100];
		a[0] = i;

		for (int j = 0; j < m; ++j){
			b[j] = g[0][j] - i;
		}

		if (!can){
			continue;
		}

		for (int j = 1; j < n; ++j){
			a[j] = g[j][0] - b[0];

			if (a[j] < 0){
				can = false;
				break;
			}
		}

		if (!can){
			continue;
		}

		for (int ii = 0; ii < n; ++ii){
			for (int jj = 0; jj < m; ++jj){
				if (a[ii] + b[jj] != g[ii][jj]){
					can = false;
				}
			}
		}

		if (!can){
			continue;
		}

		int new_ans = 0;
		for (int j = 0; j < n; ++j){
			new_ans += a[j];
		}

		for (int j = 0; j < m; ++j){
			new_ans += b[j];
		}

		if (new_ans < ans){
			ans = new_ans;

			ans1 = {};
			for (int ii = 0; ii < n; ++ii){
				for (int jj = 0; jj < a[ii]; ++jj){
					ans1.push_back({ 1, ii + 1});
				}
			}

			for (int ii = 0; ii < m; ++ii){
				for (int jj = 0; jj < b[ii]; ++jj){
					ans1.push_back({ 2, ii + 1});
				}
			}
		}
	}

	if (ans == inf){
		cout << -1;
	}
	else{
		cout << ans << "\n";

		for (int i = 0; i < ans1.size(); ++i){
			if (ans1[i].first == 1){
				cout << "row ";
			}
			else{
				cout << "col ";
			}

			cout << ans1[i].second << "\n";
		}
	}


	return 0;
}