#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a-1; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
unordered_map<string, int> good_strings;
unordered_set<string> good_substrings;

unordered_map<string, int> cache[1<<12];
unordered_map<string, pair<int, pair<int, string>>> next_key[1<<12];
unordered_map<string, int> suffix_value_cache;

int get_suffix_value(string s) {
	if (suffix_value_cache.count(s))
		return suffix_value_cache[s];
	int res = 0;
	while (sz(s) >= 1) {
		res += good_strings[s];
		s.pop_back();
	}
	suffix_value_cache[s] = res;
	return res;
}

int rec(int used, string suffix) {
	if (cache[used].count(suffix))
		return cache[used][suffix];
	if (used == (1<<12)-1) {
		int res = 0;
		rep(i,0,sz(suffix))
		rep(j,i+1,sz(suffix)+1) {
			res += good_strings[suffix.substr(i, j-i)];
		}
		cache[used][suffix] = res;
		return res;
	}
	int res = -1;
	rep(cind,0,12) {
		if (used&(1<<cind))
			continue;
		string new_suffix = suffix;
		new_suffix.push_back('a'+cind);
		int new_res = 0;
		while (!good_substrings.count(new_suffix)) {
			new_res += get_suffix_value(new_suffix);
			new_suffix = new_suffix.substr(1);
		}
		int new_used = (used|(1<<cind));
		new_res += rec(new_used, new_suffix);
		if (new_res > res) {
			res = new_res;
			next_key[used][suffix] = make_pair(cind, make_pair(new_used, new_suffix));
		}
	}
	assert(res != -1);
	//cerr << used << " " << suffix << " " << res << endl;
	cache[used][suffix] = res;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
#ifdef DEBUG
	n = 666;
#else
	cin >> n;
#endif
	rep(i,0,n) {
		int c;
		string s;
#ifdef DEBUG
		c = 1;
		rep(j,0,3)
			s.push_back('a'+(rand()%12));
#else
		cin >> c >> s;
#endif
		map<int, char> M;
		int curPos = 0;
		M[curPos] = s[0];
		bool ok = true;
		rep(j,1,sz(s)) {
			if (M.count(curPos+1) && M[curPos+1] == s[j]) {
				++curPos;
				continue;
			}
			if (M.count(curPos-1) && M[curPos-1] == s[j]) {
				--curPos;
				continue;
			}
			if (!M.count(curPos+1)) {
				++curPos;
				M[curPos] = s[j];
				continue;
			}
			if (!M.count(curPos-1)) {
				--curPos;
				M[curPos] = s[j];
				continue;
			}
			ok = false;
		}
		if (ok) {
			string r;
			for (auto it : M) {
				r.push_back(it.second);
			}
			assert(sz(r) >= 2);
			good_strings[r] += c;
			reverse(all(r));
			good_strings[r] += c;
		}
	}
	good_substrings.insert("");
	for (auto it : good_strings) {
		string s = it.first;
		while (sz(s) >= 1) {
			good_substrings.insert(s);
			s.pop_back();
		}
	}
	rec(0, "");
	string ans;
	pair<int, string> key = make_pair(0, "");
	while (sz(ans) < 12) {
		auto new_key = next_key[key.first][key.second];
		ans.push_back('a'+new_key.first);
		key = new_key.second;
	}
	int times_used[12];
	for (char c : ans)
		times_used[c-'a']++;
	rep(i,0,12)
		assert(times_used[i]);
	cout << ans << endl;
}