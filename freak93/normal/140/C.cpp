#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int N; cin >> N;
	map<int, int> M;

	int max1 = 0, max2 = 0;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		++M[a[i]];
	}
	
	for (map<int, int>::iterator it = M.begin(); it != M.end(); ++it)
		if (it -> second > max1) {
			max2 = max1, max1 = it -> second;
		}
		else
			if (it -> second > max2) {
				max2 = it -> second;
			}
	
	int groups;

	if (max1 <= N / 3)
		groups = N / 3;
	else
		if (max2 <= (N - max1) / 2)
			groups = min(N / 3, (N - max1) / 2);
		else
			groups = min(N / 3, N - max1 - max2);

	vector< vector<int> > b(3, vector<int>(max(groups, 1), 0));

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < groups; ++j) {
			//cerr << M.begin() -> first << " " << M.begin() -> second << "\n";
			while (M.begin() -> second <= 0)
				M.erase(M.begin());
			if (M.begin() -> second > groups)
				M.begin() -> second = groups;
			--(M.begin() -> second);
			b[i][j] = M.begin() -> first;
		}
	
	cout << groups << "\n";
	for (int  i = 0; i < groups; ++i)
		cout << b[2][i] << " " << b[1][i] << " " << b[0][i] << "\n";
}