/*input

1
10
*/
#include <bits/stdc++.h>

using namespace std;

int mas[200000];
vector<int> gra[200000];
bool apl[200000];
int ats[200000];
vector<int> dal;
vector<int> kie;

void dfs(int v, int gyl, int gc) {
	apl[v] = true;

	if (v != 0)
		gc = __gcd(gc, mas[v]);

	for (int i = 0; i < dal.size(); i++) {
		if (mas[v] % dal[i] == 0)
			kie[i]++;

		if (kie[i] == gyl)
			ats[v] = dal[i];
	}

	ats[v] = max(ats[v], (v == 0 ? mas[v] : gc));

	for (int x : gra[v]) {
		if (!apl[x])
			dfs(x, gyl + 1, gc);
	}

	for (int i = 0; i < dal.size(); i++) {
		if (mas[v] % dal[i] == 0)
			kie[i]--;
	}
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> mas[i];

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		gra[x].push_back(y);
		gra[y].push_back(x);
	}

	for (int i = 1; i <= mas[0]; i++) {
		if (mas[0] % i == 0)
			dal.push_back(i);
	}

	kie.resize(dal.size());

	dfs(0, 0, 0);

	for (int i = 0; i < n; i++)
		cout << ats[i] << " ";



	return 0;
}