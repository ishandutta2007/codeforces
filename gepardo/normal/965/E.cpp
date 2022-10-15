#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

struct Node {
	int next[26];
	int cnt;
	
	Node() {
		for (int i = 0; i < 26; i++) {
			next[i] = -1;
		}
		cnt = 0;
	}
};

int main() {
	int n; cin >> n;
	vector<Node> trie;
	trie.emplace_back();
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int cur = 0;
		for (char c: s) {
			int go = c - 'a';
			if (trie[cur].next[go] < 0) {
				trie[cur].next[go] = trie.size();
				trie.emplace_back();
			}
			cur = trie[cur].next[go];
		}
		trie[cur].cnt++;
	}
	
	auto merge = [&](priority_queue<int> *a, priority_queue<int> *b) {
		if (a->size() < b->size()) {
			swap(a, b);
		}
		while (!b->empty()) {
			a->push(b->top());
			b->pop();
		}
		delete b;
		return a;
	};
	
	function<priority_queue<int> *(int, int)> dfs = [&](int v, int d) {
		auto res = new priority_queue<int>;
		for (int i = 0; i < 26; i++) {
			if (trie[v].next[i] < 0) {
				continue;
			}
			res = merge(res, dfs(trie[v].next[i], d+1));
		}
		if (trie[v].cnt) {
			res->push(d);
		} else if (!res->empty() && d != 0) {
			res->pop();
			res->push(d);
		}
		return res;
	};
	auto res = dfs(0, 0);
	
	int64_t ans = 0;
	while (!res->empty()) {
		ans += res->top();
		res->pop();
	}
	
	cout << ans << endl;
	
	delete res;
	return 0;
}