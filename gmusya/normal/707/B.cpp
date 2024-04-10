#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 1000000001;

struct three {
	int a, b, c;
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector <three> a(m);
	for (int i = 0; i < m; i++)
		cin >> a[i].a >> a[i].b >> a[i].c;
	vector <bool> b(n + 1);
	for (int i = 0; i < k; i++) {
		int u;
		cin >> u;
		b[u] = true;
	}
	int answer = INF;
	for (int i = 0; i < m; i++)
		if (b[a[i].a] + b[a[i].b] == 1)
			answer = min(answer, a[i].c);
	if (answer == INF)
		cout << "-1";
	else
		cout << answer;
	return 0;
}