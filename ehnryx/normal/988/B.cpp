#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

bool cmp(const string& a, const string& b) {
	return a.size() < b.size(); 
}

bool issub(const string& a, const string& b) {
	if (a.size() > b.size()) return false;
	for (int i=0; i<=b.size()-a.size(); i++) {
		bool match = true;
		for (int j=0; j<a.size(); j++) {
			if (a[j] != b[i+j]) {
				match = false;
				break;
			}
		}
		if (match) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	string s;
	vector<string> arr;
	for (int i=0; i<n; i++) {
		cin >> s;
		arr.push_back(s);
	}
	sort(arr.begin(), arr.end(), cmp);

	for (int i=1; i<n; i++) {
		if (!issub(arr[i-1], arr[i])) {
			cout << "NO" << nl;
			return 0;
		}
	}

	cout << "YES" << nl;
	for (const string& it : arr) {
		cout << it << nl;
	}

	return 0;
}