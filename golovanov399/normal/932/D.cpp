#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Node {
	int w;
	vector<int> p;
	vector<int> pr_ge;
	vector<int> maxs;
	vector<long long> sums;

	Node(int _w): w(_w) {}
};

vector<Node> nodes;

void addNode(int r, int w) {
	--r;
	nodes.emplace_back(w);
	auto& node = nodes.back();

	int prv = r;
	for (int l = (int)nodes[r].maxs.size() - 1; l >= 0; --l) {
		if (l >= (int)nodes[prv].maxs.size()) {
			continue;
		}
		if (nodes[prv].maxs[l] < w) {
			if (l >= (int)nodes[prv].p.size()) {
				prv = -1;
				break;
			} else {
				prv = nodes[prv].p[l];
			}
		}
	}

	node.sums = {w};
	if (prv > -1 && nodes[prv].w >= w) {
		node.pr_ge = {prv};
		for (int i = 0;; ++i) {
			if (i >= (int)nodes[prv].sums.size()) {
				break;
			} else {
				node.sums.push_back(node.sums[i] + nodes[prv].sums[i]);
				if (i >= (int)nodes[prv].pr_ge.size()) {
					break;
				}
				node.pr_ge.push_back(nodes[prv].pr_ge[i]);
				prv = node.pr_ge.back();
			}
		}
	}

	node.p = {r};
	node.maxs = {w};
	prv = r;
	for (int i = 0;; ++i) {
		if (i >= (int)nodes[prv].p.size()) {
			break;
		} else {
			node.maxs.push_back(max(node.maxs[i], nodes[prv].maxs[i]));
			if (i >= (int)nodes[prv].p.size()) {
				break;
			}
			node.p.push_back(nodes[prv].p[i]);
			prv = node.p.back();
		}
	}
}

template <typename T>
ostream& operator <<(ostream& ostr, const vector<T>& a) {
	ostr << "{";
	for (int i = 0; i < (int)a.size(); ++i) {
		if (i) {
			ostr << ", ";
		}
		ostr << a[i];
	}
	ostr << "}";
	return ostr;
}

ostream& operator <<(ostream& ostr, const Node& node) {
	ostr << "w: " << node.w << ", p: " << node.p << ", pr_ge: " << node.pr_ge << ", maxs: " << node.maxs << ", sums: " << node.sums;
	return ostr;
}

int getAns(int r, long long x) {
	--r;

	// for (auto node : nodes) {
	// 	cerr << node << "\n";
	// }
	// cerr << "\n";

	int ans = 0;
	for (int i = (int)nodes[r].sums.size() - 1; i >= 0; --i) {
		if (i >= (int)nodes[r].sums.size()) {
			continue;
		}
		if (nodes[r].sums[i] <= x) {
			x -= nodes[r].sums[i];
			ans += 1 << i;
			if (i >= (int)nodes[r].pr_ge.size()) {
				break;
			}
			r = nodes[r].pr_ge[i];
		}
	}

	return ans;
}

int main() {
	nodes.emplace_back(0);
	auto& root = nodes[0];
	root.maxs = {0};
	root.sums = {0};

	long long last = 0;
	int q = nxt();
	while (q--) {
		int t;
		long long p, q;
		scanf("%d%lld%lld", &t, &p, &q);
		if (t == 1) {
			long long r = p ^ last;
			long long w = q ^ last;

			addNode(r, w);
		} else {
			long long r = p ^ last;
			long long x = q ^ last;

			last = getAns(r, x);
			printf("%d\n", (int)last);
		}
	}

	return 0;
}