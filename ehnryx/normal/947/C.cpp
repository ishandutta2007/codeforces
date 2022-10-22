#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef mt19937 RNG;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;

struct Trie {
	struct Node {
		int child[2];
		int cnt;
		int prev;
		bool end;
		Node(int p=-1): cnt(0), prev(p), end(false) {
			child[0] = child[1] = -1;
		}
		int& operator [] (int b) {
			return child[b];
		}
	};
	vector<Node> g;
	Trie() {
		g.push_back(Node());
		g[0].cnt = INF;
	}

	void insert(unsigned int v) {
		int cur = 0;
		for (int i = 31; i >= 0; i--) {
			bool bit = v & 1<<i;
			if (g[cur][bit] == -1) {
				int next = g.size();
				g.push_back(Node(cur));
				g[cur][bit] = next;
			}
			cur = g[cur][bit];
			g[cur].cnt++;
		}
		g[cur].end = true;
	}

	unsigned int query(unsigned int v) {
		int res = 0;
		int cur = 0;
		for (int i = 31; i >= 0; i--) {
			bool bit = v & 1<<i;
			bool next = (g[cur][bit] == -1) ? !bit : bit;
			res |= (bit^next) << i;
			cur = g[cur][next];
			g[cur].cnt--;
			if (g[cur].cnt == 0) {
				g[g[cur].prev][next] = -1;
			}
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	Trie trie;

	unsigned int message[n], val;
	for (int i = 0; i < n; i++) {
		cin >> message[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> val;
		trie.insert(val);
	}

	vector<unsigned int> ans;
	for (int i = 0; i < n; i++) {
		ans.push_back(trie.query(message[i]));
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}