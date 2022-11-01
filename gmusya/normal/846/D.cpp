#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct triplet {
	int t, x, y;
};

bool cmp(triplet a, triplet b) {
	return (a.t < b.t);
}

int n, m, q, k;

int main() {
	cin >> n >> m >> k >> q;
	if (q == 0) {
		cout << "-1";
		return 0;
	}
	vector <triplet> a(q);
	for (int i = 0; i < q; i++) {
		cin >> a[i].x >> a[i].y >> a[i].t;
		a[i].x--;
		a[i].y--;
	}
	sort(a.begin(), a.end(), cmp);
	int l = 0;
	int r = q - 1;
	int cnt = 0;
	bool tf;
	while (l != r || cnt < 2) {
		vector <vector <int>> monitor(n);
		for (int i = 0; i < n; i++)
			monitor[i].resize(m);
		int med = (l + r) / 2;
		for (int i = 0; i <= med; i++)
			monitor[a[i].x][a[i].y] = 1;
		vector <vector <int>> sum(n);
		for (int i = 0; i < n; i++)
			sum[i].resize(m);
		sum[0][0] = monitor[0][0];;
		for (int i = 1; i < n; i++)
			sum[i][0] = sum[i - 1][0] + monitor[i][0];
		for (int i = 1; i < m; i++)
			sum[0][i] = sum[0][i - 1] + monitor[0][i];
		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++)
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + monitor[i][j];
		tf = true;
		if (sum[k - 1][k - 1] == k * k)
			tf = false;
		for (int i = k; i < n; i++)
			if (sum[i][k - 1] - sum[i - k][k - 1] == k * k)
				tf = false;
		for (int i = k; i < m; i++)
			if (sum[k - 1][i] - sum[k - 1][i - k] == k * k)
				tf = false;
		for (int i = k; i < n; i++)
			for (int j = k; j < m; j++)
				if (sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k] == k * k)
					tf = false;
		if (tf)
			l = med + 1;
		else
			r = med;
		if (cnt == 1)
			break;
		if (l == r)
			cnt++;
	}
	if (tf)
		cout << "-1";
	else
		cout << a[l].t;
	return 0;
}