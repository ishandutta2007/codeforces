#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

const int maxn = 100005;

int b[maxn];

bool fcomp(pair<int, string> a, pair<int, string> b) {
	if (a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	int n; cin >> n;
	pair<int, string> a[maxn];
	for (int i = 0; i < n; ++i)
    	cin >> a[i].second >> a[i].first;
	sort(a, a + n, fcomp);
	map<string, int> M;
	for (int i = 0; i < n; ++i)
		M[a[i].second] = i;
	int m; cin >> m;
	for (int i = n - m; i < n; ++i)
		cin >> b[i];
	sort(b + n - m, b + n);
	
	string vas;
	cin >> vas;
	int k = M[vas];

	if (m == 0) {
		cout << n - k << " " << n - k << "\n";
		return 0;
	}
	int score = a[k].first + b[n - 1];
   	int j = n - 2, i;
	int pos = 1; int left = n - 1;
	for (i = 0; i < n; ++i)
		if (i != k) {
			while (j >= 0 && (b[j] + a[i].first > score || (b[j] + a[i].first == score && a[i].second < a[k].second)))
				--j, ++pos;
			if (j >= 0)
				--j;
		}
	
	int minpos = pos;

	score = a[k].first + b[0];
	j = 1;
	pos = n;
	for (i = n - 1; i >= 0; --i)
		if (i != k) {
			while (j < n && (b[j] + a[i].first < score || (b[j] + a[i].first == score && a[i].second > a[k].second)))
				--pos, ++j;
			if (j < n)
				++j;
		}

	cout << minpos << " " << pos;
}