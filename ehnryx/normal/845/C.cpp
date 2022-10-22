#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
const ll MOD = 1e9+7;
const int INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int,int>> show;
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		show.push_back(pair<int,int>(a,b+1));
	} sort(show.begin(), show.end());
	int first, second;
	first = second = 0;
	for (int i = 0; i < n; i++) {
		if (show[i].first >= first)
			first = show[i].second;
		else if (show[i].first >= second)
			second = show[i].second;
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}