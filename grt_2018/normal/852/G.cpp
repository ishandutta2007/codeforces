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
int n, m;
map<string, int>S;
set<string>st;
int ans;

void rec(string &s, int id, string cur) {
	if(id == (int)s.size()) {
		//cout << cur << "\n";
		st.insert(cur);
		return;
	}
	if(s[id] == '?') {
		for(int i = 0; i < 5; ++i) {
			rec(s, id + 1, cur + (char)(i + 'a'));
		}
		rec(s, id + 1, cur);
	} else {
		rec(s, id + 1, cur + s[id]);
	}
}

int main() {_
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		S[s]++;
	}
	while(m--) {
		string s;
		cin >> s;
		ans = 0;
		rec(s, 0, "");
		for(auto ss : st) ans += S[ss];
		st.clear();
		cout << ans << "\n";
		//cout << "---\n";
	}
}