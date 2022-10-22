//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		if((int)s.size() == 2) {
			cout << s[1] << "\n";
			continue;
		}
		char c = '9';
		for(auto c2 : s) c = min(c, c2);
		cout << c << "\n";
	}
}