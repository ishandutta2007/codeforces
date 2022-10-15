#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
int Q;
LL V, U, W;
map<LL, pair<LL, LL> > cost;

string to_bin(LL x) {
	string ret = "";
	do {
		if (x % 2) ret += '1';
		else ret += '0';

		x >>= 1;
	} while (x);
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int t;
		cin >> t;

		if (t == 1) {
			cin >> V >> U >> W;
			string vs = to_bin(V);
			string us = to_bin(U);
			int common = 0;
			while (common < vs.size() && common < us.size()) {
				if (vs[common] == us[common]) {
					common++;
				}
				else break;
			}
			int amt = vs.size() - common;
			for (int i = 0; i < amt; i++) {
				if (V % 2) {
					cost[V / 2].second += W;
				}
				else {
					cost[V / 2].first += W;
				}
				V >>= 1;
				// error(V);
			}
			for (int len = common; len < us.size(); len++) {
				bool par = (us[len] == '1');
				if (par) {
					cost[V].second += W;
				}
				else {
					cost[V].first += W;
				}
				V <<= 1;
				V += par;
				// error(V);
			}
		}
		else {
			LL ans = 0;
			cin >> V >> U;
			string vs = to_bin(V);
			string us = to_bin(U);
			int common = 0;
			while (common < vs.size() && common < us.size()) {
				if (vs[common] == us[common]) {
					common++;
				}
				else break;
			}
			int amt = vs.size() - common;
			for (int i = 0; i < amt; i++) {
				if (V % 2) {
					ans += cost[V / 2].second;
				}
				else {
					ans += cost[V / 2].first;
				}
				V >>= 1;
			}
			for (int len = common; len < us.size(); len++) {
				bool par = (us[len] == '1');
				if (par) {
					ans += cost[V].second;
				}
				else {
					ans += cost[V].first;
				}
				V <<= 1;
				V += par;
			}
			cout << ans << '\n';
		
}		assert(U == V);
	}

	cout.flush();
	return 0;
}