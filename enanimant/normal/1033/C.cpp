// October 7, 2018
// http://codeforces.com/contest/1033/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MAXN = (int) 1e5;

int N;
vector<int> a;
bool winning[MAXN];
vector< pair<int, int> > vals;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	cin >> N;
	a.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		vals.push_back({a[i], i});
	}
	sort(vals.begin(), vals.end());
	winning[vals[N - 1].second] = false;
	for (int i = N - 2; i >= 0; i--) {
		int ind = vals[i].second;
		int c = 1;
		for (int c = 1; ind + c * a[ind] < N; c++) {
			int d = ind + c * a[ind];
			if (a[d] < a[ind]) continue;
			if (!winning[d]) {
				winning[ind] = true;
				break;
			}
		}
		for (int c = 1; ind - c * a[ind] >= 0; c++) {
			int d = ind - c * a[ind];
			if (a[d] < a[ind]) continue;
			if (!winning[d]) {
				winning[ind] = true;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << (winning[i] ? 'A' : 'B');
	}
	cout << '\n';


	return 0;
}