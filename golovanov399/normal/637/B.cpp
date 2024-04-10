#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define x first
#define y second
#define itn int

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		m[s] = -i;
	}
	vector<pair<int, string>> a;
	for (auto x : m)
		a.pb(x.second, x.first);
	sort(all(a));
	for (auto x : a)
		cout << x.second << "\n";

	return 0;
}