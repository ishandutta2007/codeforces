#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

int tail = 1;

struct vertex {
	int terminal = 0;
	int terminal_kids = 0;
	int kid0 = -1, kid1 = -1;
};

vector <vertex> trie(1);

void add(int v, int it, vector <int> &s) {
	trie[v].terminal_kids++;
	if (it == s.size()) {
		trie[v].terminal++;
		return;
	}
	int next = s[it];
	if (next == 0) {
		if (trie[v].kid0 == -1) {
			trie[v].kid0 = tail++;
			trie.push_back({});
		}
		add(trie[v].kid0, it + 1, s);
		return;
	}
	if (trie[v].kid1 == -1) {
		trie[v].kid1 = tail++;
		trie.push_back({});
	}
	add(trie[v].kid1, it + 1, s);
}

void del(int v, int it, vector <int> &s) {
	trie[v].terminal_kids--;
	if (it == s.size()) {
		trie[v].terminal--;
		return;
	}
	int next = s[it];
	if (next == 0) del(trie[v].kid0, it + 1, s);
	else del(trie[v].kid1, it + 1, s);
}

void get(int v, int it, vector <int> &s, vector <int> &ans) {
	if (trie[v].terminal_kids == 0) return;
	if (it == s.size()) return;
	int next = s[it];
	if (next == 0) {
		if (trie[v].kid1 == -1 || trie[trie[v].kid1].terminal_kids == 0) {
			ans[it] = 0;
			get(trie[v].kid0, it + 1, s, ans);
			return;
		}
		ans[it] = 1;
		get(trie[v].kid1, it + 1, s, ans);
		return;
	}
	if (trie[v].kid0 == -1 || trie[trie[v].kid0].terminal_kids == 0) {
		ans[it] = 1;
		get(trie[v].kid1, it + 1, s, ans);
		return;
	}
	ans[it] = 0;
	get(trie[v].kid0, it + 1, s, ans);
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		char c;
		cin >> c;
		vector <int> num(32);
		int val;
		cin >> val;
		int copy_val = val;
		for (int it = 0; it < 32; it++) {
			num[it] = val % 2;
			val /= 2;
		}
		reverse(num.begin(), num.end());
		if (c == '+') add(0, 0, num);
		if (c == '-') del(0, 0, num);
		if (c == '?') {
			vector <int> ans(32);
			get(0, 0, num, ans);
			int answer = 0;
			for (int i = 0; i < ans.size(); i++) answer = answer * 2 + (ans[i] ^ num[i]);
			cout << max(answer, copy_val) << endl;
		}
	}
	return 0;
}