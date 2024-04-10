#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int k, f;
	int n, m;
	cin >> n >> m;
	bitset<101> good;
	good.set(); good[0] = false;
	for (int i = 0; i < m; i++) {
		cin >> k >> f;
		for (int j = 1; j <= 100; j++) {
			if (!(k <= j*f && k > j*(f-1))) {
				good[j] = false;
			}
		}
	}
	set<int> ans;
	vector<int> possible;
	for (int i = 1; i <= 100; i++) 
		if (good[i])
			possible.push_back(i);
	for (int floor = 1; floor <= 100; floor++) {
		for (int size: possible) {
			if (n <= floor*size && n > size*(floor-1)) {
				ans.insert(floor);
			}
		}
	}
	if (ans.size() == 1)
		cout << *ans.begin() << nl;
	else
		cout << -1 << nl;

	return 0;
}