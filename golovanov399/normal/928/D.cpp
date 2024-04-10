#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

using Transition = array<int, 26>;
Transition def;

struct Trie {
	vector<Transition> a;
	vector<int> cnt;
	vector<int> oneof;
	vector<char> flag;

	Trie() {
		a.assign(1, def);
		cnt.assign(1, 0);
		oneof.assign(1, -1);
		flag.assign(1, 0);
	}

	int getNew() {
		a.push_back(def);
		cnt.push_back(0);
		oneof.push_back(-1);
		flag.push_back(0);
		return (int)a.size() - 1;
	}

	int go(int pos, char c) {
		c -= 'a';
		if (a[pos][c] == -1) {
			int x = getNew();
			a[pos][c] = x;
			oneof[pos] = c;
		}
		return a[pos][c];
	}

	void add(const string& s) {
		// cerr << "add word '" << s << "'\n";
		int pos = 0;
		for (char c : s) {
			pos = go(pos, c);
		}
		if (flag[pos] == 0) {
			pos = 0;
			for (char c : s) {
				cnt[pos] += 1;
				pos = go(pos, c);
			}
			cnt[pos] += 1;
		}
		flag[pos] = 1;
	}

	string getOnly(int node) {
		string res;
		while (oneof[node] != -1) {
			res += (char)('a' + oneof[node]);
			node = a[node][oneof[node]];
		}
		return res;
	}

	int getLast(int node) {
		while (node != -1 && oneof[node] != -1) {
			node = a[node][oneof[node]];
		}
		return node;
	}
};

int main() {
	def.fill(-1);
	string text = "";
	string s;
	while (getline(cin, s)) {
		text += s + "\n";
	}
	while (text.back() == '\n') {
		text.pop_back();
	}
	text.push_back('\n');

	Trie trie;
	int ans = 0;
	string cur = "";
	int node = 0;
	for (int i = 0; i < (int)text.size(); ++i) {
		// cerr << "watch symbol " << text[i] << "\n";
		char c = text[i];
		if (isalpha(c)) {
			if (node > -1) {
				node = trie.a[node][c - 'a'];
			}
			// cerr << "now node is " << node << "\n";
			cur += c;
			ans += 1;
			if (node > -1 && trie.cnt[node] == 1) {
				auto t = trie.getOnly(node);
				if (text.substr(i + 1, t.length()) == t && t.length() > 1) {
					// cerr << "the only option is ('" << cur << "', '" << t << "')\n";
					ans += 1;
					i += t.length();
					cur += t;
					node = trie.getLast(node);
				} else {
					// cerr << "cur is '" << cur << "', t is '" << t << "', and it doesn't fit\n";
					int common = 0;
					while (common < (int)t.length() && i + 1 + common < (int)text.length() && text[i + 1 + common] == t[common]) {
						++common;
					}
					// cerr << "common part, btw, is " << common << ", skipping it\n";
					i += common;
					ans += common;
					cur += t.substr(0, common);
					while (common--) {
						node = trie.a[node][trie.oneof[node]];
					}
				}
			}
		} else {
			++ans;
			trie.add(cur);
			cur = "";
			node = 0;
		}
	}
	cout << ans << "\n";

	return 0;
}