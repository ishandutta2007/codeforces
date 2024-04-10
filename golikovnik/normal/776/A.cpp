#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n;
	cin >> n;
	set<string> names;
	names.insert(s);	
	names.insert(t);
	cout << s << " " << t << "\n";
	for (int i = 0; i < n; ++i) {
		string a, b;
		cin >> a >> b;
		names.erase(a);
		names.insert(b);
		for (const string &x: names) {
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;	
}