#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define endl '\n'
#define make_unique(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

typedef long long ll;
typedef long double ld;
typedef double D;

template<class T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	int n = read(), m = read();
	vector<int> a(n);
	for (int &x: a) cin >> x;
	vector<int> b(m);
	for (int &x: b) cin >> x;
	sort(all(a));
	for (int x: b) {
		cout << upper_bound(all(a), x) - a.begin() << " ";
	}	
	cout << endl;
	return 0;
}