#include <bits/stdc++.h>
using namespace std;

struct SegTree {
	int length, layers;
	vector<int> nodes;

	SegTree(int n) {
		length = 1<<n;
		layers = n+1;
		nodes.resize(2*length+1);
	}
	int& operator [] (int i) {
		return nodes[length+i];
	}
	void build() {
		int curr = length/2;
		int op = 1;
		for (int i = length-1; i > 0; i--) {
			if (op == 1) nodes[i] = nodes[2*i] | nodes[2*i+1];
			else nodes[i] = nodes[2*i] ^ nodes[2*i+1];
			if (i == curr) {
				curr /= 2;
				op = -op;
			}
		}
	}

	void update(int i, int b) {
		i += length;
		nodes[i] = b;
		int op = 1;
		i /= 2;
		while (i) {
			//cerr << "update " << i << endl;
			if (op == 1) nodes[i] = nodes[2*i] | nodes[2*i+1];
			else nodes[i] = nodes[2*i] ^ nodes[2*i+1];
			i /= 2;
			op = -op;
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, queries;
	cin >> n >> queries;
	SegTree st(n);
	for (int i = 0; i < st.length; i++) {
		cin >> st[i];
	}
	st.build();

	int a, b;
	for (int i = 0; i < queries; i++) {
		cin >> a >> b;
		st.update(a-1, b);
		cout << st.nodes[1] << '\n';
	}

	return 0;
}