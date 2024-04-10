#include <bits/stdc++.h>
using namespace std;

struct SegTree {
	struct Node {
		// first and second because a knight cannot beat itself
		int first, second;
		bool lazy;
		Node() {
			clear();
		}
		void clear() {
			first = second = 0;
			lazy = false;
		}
		void propagate(Node& left, Node& right) {
			if (this->second) {
				// two values in this
				left.first = right.first = this->first;
				left.second = right.second = this->second;
			}
			else {
				// only one value in this,  update only if it is different
				if (left.first != this->first) {
					left.second = left.first;
					left.first = this->first;
				}
				if (right.first != this->first) {
					right.second = right.first;
					right.first = this->first;
				}
			}
			// reset this and make left and right lazy
			left.lazy = right.lazy = true;
			this->clear();
		}
	};
	vector<Node> nodes;
	int length;

	SegTree(int n) {
		while (__builtin_popcount(n) != 1) n++;
		nodes.resize(2*n);
		length = n;
	}

	void upd(int left, int right, int x, int start, int end) {
		// find index
		int i = (length+left-1)/(end-start+1);
		// update if this is it
		if (left == start && right == end) {
			if (x != nodes[i].first) {
				nodes[i].second = nodes[i].first;
				nodes[i].first = x;
			} nodes[i].lazy = true;
			return;
		}
		// lazy propagate if this is not it
		if (nodes[i].lazy) {
			nodes[i].propagate(nodes[2*i], nodes[2*i+1]);
		}
		// split segments
		int mid = (start+end-1)/2;
		if (right <= mid) upd(left, right, x, start, mid);
		else if (left > mid) upd(left, right, x, mid+1, end);
		else {
			upd(left, mid, x, start, mid);
			upd(mid+1, right, x, mid+1, end);
		}
	}
	void update(int l, int r, int x) {
		upd(l, r, x, 1, length);
	}
	
	int qry(int x, int start, int end) {
		// find index
		int i = (length+x-1)/(end-start+1);
		// return if this is a leaf
		if (start == end) {
			if (nodes[i].first != x) return nodes[i].first;
			else return nodes[i].second;
		}
		// return if this is lazy and value is not self
		if (nodes[i].lazy) {
			if (nodes[i].first != x) return nodes[i].first;
			else if (nodes[i].second > 0) return nodes[i].second;
		}
		// split segments
		int mid = (start+end-1)/2;
		if (x <= mid) return qry(x, start, mid);
		else return qry(x, mid+1, end);
	}
	int query(int x) {
		return qry(x, 1, length);
	}
};

// WHY DOES MY RUNTIME INCREASE?
int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	struct Fight {
		int l, r, x;
	};
	int n, m;
	cin >> n >> m;
	SegTree knights(n);
	Fight order[m];
	for (int i = 0; i < m; i++) {
		cin >> order[i].l >> order[i].r >> order[i].x;
	}
	// update segtree in reverse order
	for (int i = m-1; i >= 0; i--) {
		knights.update(order[i].l, order[i].r, order[i].x);
	}
	// output answer
	for (int i = 0; i < n; i++) {
		cout << knights.query(i+1) << " ";
	} cout << endl;

	return 0;
}