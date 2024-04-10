#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 100000;
ll ans[MAXN];

struct node {
	node* c[2] = {nullptr, nullptr};
	int starNum = 0;
	bool isSeries = false;
	bool isParallel = false;
	ll K = 0;
	void getK() {
		if (starNum) {
			K = 1;
		} else if (isSeries) {
			c[0]->getK();
			c[1]->getK();
			K = min(c[0]->K, c[1]->K);
		} else if (isParallel) {
			c[0]->getK();
			c[1]->getK();
			K = c[0]->K + c[1]->K;
		} else assert(false);
	}

	void color(ll RK) {
		if (starNum) {
			ans[starNum] = RK;
		} else if (isSeries) {
			if (c[0]->K < c[1]->K) {
				c[0]->color(RK);
				c[1]->color(0);
			} else {
				c[1]->color(RK);
				c[0]->color(0);
			}
		} else if (isParallel) {
			c[0]->color(RK);
			c[1]->color(RK);
		} else assert(false);
	}
} nodes[MAXN * 2];

int R;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> R;
		int NNODES = 0;
		int N = 0;
		string S; getline(cin, S);
		vector<pair<node*, char>> stk;
		stk.push_back(pair<node*, char>(nullptr, '\0'));
		for (char c : S) {
			if (c == ' ') {
				continue;
			} else if (c == '(') {
				stk.push_back(pair<node*, char>(nullptr, '\0'));
			} else if (c == ')') {
				assert(stk.back().second == '\0');
				node* cur = stk.back().first;
				stk.pop_back();
				if (stk.back().second == '\0') {
					assert(stk.back().first == nullptr);
					stk.back().first = cur;
				} else {
					node* nxt = &nodes[NNODES++];
					*nxt = node{};
					nxt->c[0] = stk.back().first;
					nxt->c[1] = cur;
					nxt->isSeries = stk.back().second == 'S';
					nxt->isParallel = stk.back().second == 'P';
					stk.back().first = nxt;
					stk.back().second = '\0';
				}
			} else if (c == '*') {
				node* cur = &nodes[NNODES++];
				*cur = node{};
				cur->starNum = ++N;
				
				if (stk.back().second == '\0') {
					assert(stk.back().first == nullptr);
					stk.back().first = cur;
				} else {
					node* nxt = &nodes[NNODES++];
					*nxt = node{};
					nxt->c[0] = stk.back().first;
					nxt->c[1] = cur;
					nxt->isSeries = stk.back().second == 'S';
					nxt->isParallel = stk.back().second == 'P';
					stk.back().first = nxt;
					stk.back().second = '\0';
				}
			} else if (c == 'S' || c == 'P') {
				assert(stk.back().first != nullptr);
				assert(stk.back().second == '\0');
				stk.back().second = c;
			} else assert(false);
		}
		assert(stk.size() == 1);
		node* root = stk.back().first;
		root->getK();
		root->color(R * root->K);

		cout << "REVOLTING";
		for (int i = 1; i <= N; i++) {
			cout << ' ' << ans[i];
		}
		cout << '\n';
	}

	return 0;
}

// if the outermost is none, then just take it
// parallel only decreases resistance, so it pushes sum down; it's optimal when all inputs are 0
//
// r <= sum(R_i)
//
// if outermost == series
//

// for a given node, say it costs k^2r to make it equal to r
// s(k_1, k_2, ...) = min, assignment is argmin

// k_1 * (k_1 r_1) + k_2 r_2 >= sum(k_i)^2 / (1/r_1 + 1/r_2 + 1/r_3 + ...)
// K = sum(k_i)
// assignment is so that k_1 r_1 = k_2 r_2 = ... = x
// 1 / R = (k_1/x + ...)
// x = (k_1 + ... + ) * R
// r_1 * k_1 = R * K