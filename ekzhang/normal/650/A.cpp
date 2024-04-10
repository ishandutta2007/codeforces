#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
int N;
map<int, vector<int> > byx;
map<int, vector<int> > byy;
map<pair<int, int>, int> occur;
long long ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		byx[X].push_back(Y);
		byy[Y].push_back(X);
		occur[make_pair(X, Y)] += 1;
	}

	for (auto p : byx) {
		LL r = p.second.size();
		ans += r * (r - 1) / 2;
	}
	for (auto p : byy) {
		LL r = p.second.size();
		ans += r * (r - 1) / 2;
	}
	for (auto p : occur) {
		LL r = p.second;
		ans -= r * (r - 1) / 2;
	}


	cout << ans << endl;
	return 0;
}