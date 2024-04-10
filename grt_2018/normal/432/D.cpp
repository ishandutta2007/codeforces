#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100 * 1000 + 10;
string s;
int p[nax];
int cnt[nax];

int main() {_
	cin >> s;
	p[1] = 0;
	int n = (int)s.size();
	for(int i = 2; i <= n; ++i) {
		int w = p[i -  1];
		while(w > 0 && s[w] != s[i - 1]) w = p[w];
		if(s[w] == s[i - 1]) w++;
		p[i] = w;
		cnt[p[i]]++;
	}
	for(int i = n; i >= 1; --i) {
		cnt[p[i]] += cnt[i];
	}
	vector<pi> ans = {};
	int x = p[n];
	while(x > 0) {
		ans.emplace_back(x, cnt[x] + 1);
		x = p[x];
	}
	reverse(ans.begin(), ans.end());
	ans.emplace_back(n, 1);
	cout << (int)ans.size() << "\n";
	for(auto y : ans) {
		cout << y.ST << " " << y.ND << "\n";
	}
	
}