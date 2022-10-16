/*input
5
1 2
1 3
3 4
2 5

*/
#include <bits/stdc++.h>

using namespace std;

long double ats = 0;
vector<int> gra[100000];

bool apl[100000] = {};

void dfs(int d, int ilg = 0, long double prop = 1) {
	apl[d] = true;
	int kie = 0;

	for (auto && i : gra[d])
		if (!apl[i])
			kie ++;

	for (auto && i : gra[d]) {
		if (!apl[i])
			dfs(i, ilg + 1, prop / kie);
	}

	if (kie == 0) {
		//cout << d << " " << ilg << " " << prop << endl;
		ats += ilg * prop;
	}

}


int main () {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gra[a].push_back(b);
		gra[b].push_back(a);
	}

	dfs(0);

	cout << fixed << setprecision(7) << ats;

	return 0;
}