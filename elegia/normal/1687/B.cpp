#include <cmath>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;



int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<pair<int, int>> edges(M);
	for (int i = 0; i != M; ++i) {
		string s(M, '0'); s[i] = '1';
		cout << "? " << s << endl;
		cin >> edges[i].first;
		edges[i].second = i;
	}
	int cur = 0;
	sort(edges.begin(), edges.end());
	string s(M, '0');
	for (int i = 0; i != M; ++i) {
		string t = s;
		t[edges[i].second] = '1';
		cout << "? " << t << endl;
		int val; cin >> val;
		if (val - cur == edges[i].first) {
			s = t;
			cur = val;
		}
	}
	cout << "! " << cur << endl;
	
	return 0;
}