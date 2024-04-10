/*input
12
1 6
10 1
4 1
7 1
1 2
5 1
1 8
1 11
3 1
12 1
9 1
580660007 861441526 -264928594 488291045 253254575 -974301934 709266786 926718320 87511873 514836444 -702876508 848928657
*/
#include <bits/stdc++.h>

using namespace std;
vector<int> gra[100000];
long long vert[100000];
bool apl[100000];

pair<long long, long long> dfs(int v) {
	apl[v] = true;

	pair<long long, long long> y(0, 0);

	for (int &x : gra[v]) {
		if (!apl[x]) {
			pair<long long, long long> b = dfs(x);
			y.first = max(y.first, b.first);
			y.second = max(y.second, b.second);
		}
	}

	vert[v] += -y.first + y.second;

	if (vert[v] > 0)
		y.first += vert[v];
	else
		y.second -= vert[v];

	//cout << v << " " << y.first << " " << y.second << endl;
	return y;
}

int main () {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		gra[x].push_back(y);
		gra[y].push_back(x);
	}

	for (int i = 0; i < n; i++)
		cin >> vert[i];

	pair<long long, long long> x = dfs(0);

	cout << x.first + x.second << endl;

	return 0;
}