/*input
3
1 1

*/
#include <bits/stdc++.h>

using namespace std;

vector<int> gra[100000];
int kie[100000];

void dfs(int d, int gyl = 0) {
	kie[gyl]++;

	for (auto && x : gra[d]) {
		dfs(x, gyl + 1);
	}
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		x--;
		gra[x].push_back(i);
	}

	dfs(0);

	int ats = 0;

	for (int i = 0; i < n; i++) {
		ats += kie[i] % 2;
	}

	cout << ats;

	return 0;
}