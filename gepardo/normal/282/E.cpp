#include <iostream>
#include <vector>

using namespace std;

struct TrieItem {
	int cnt;
	int next[2];
};
vector<TrieItem> trie;

inline void init() {
	trie.clear();
	trie.push_back({0, {-1, -1}});
}

inline void add(int64_t vals, int curBit = 60, int v = 0) {
	trie[v].cnt++;
	if (curBit < 0) {
		return;
	}
	int addTo = !!(vals & ((int64_t)1 << curBit));
	if (trie[v].next[addTo] < 0) {
		trie[v].next[addTo] = trie.size();
		trie.push_back({0, {-1, -1}});
	}
	add(vals, curBit - 1, trie[v].next[addTo]);
}

inline void del(int64_t vals, int curBit = 60, int v = 0) {
	trie[v].cnt--;
	if (curBit < 0) {
		return;
	}
	int addTo = !!(vals & ((int64_t)1 << curBit));
	del(vals, curBit - 1, trie[v].next[addTo]);
}

inline int64_t maxXor(int64_t vals, int curBit = 60, int v = 0) {
	if (trie[v].cnt == 0 || curBit < 0) {
		return 0;
	}
	int64_t shift = (int64_t)1 << curBit;
	int addTo = !(vals & shift);
	if (trie[v].next[addTo] >= 0 && trie[trie[v].next[addTo]].cnt != 0) {
		return shift | maxXor(vals, curBit - 1, trie[v].next[addTo]);
	} else {
		return maxXor(vals, curBit - 1, trie[v].next[!addTo]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	init();
	int n; cin >> n;
	vector<int64_t> v(n), p(n+1), s(n+1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	p[0] = 0;
	for (int i = 0; i < n; i++) {
		p[i+1] = p[i] ^ v[i];
	}
	s[n] = 0;
	for (int i = n-1; i >= 0; i--) {
		s[i] = s[i+1] ^ v[i];
	}
	for (int i = 0; i <= n; i++) {
		add(s[i]);
	}
	int64_t res = 0;
	for (int i = 0; i <= n; i++) {
		res = max(res, maxXor(p[i]));
		del(s[i]);
	}
	cout << res << endl;
	return 0;	
}