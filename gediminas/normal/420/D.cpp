#include <bits/stdc++.h>

using namespace std;

struct node {
	int val;
	int prior;
	node *left = NULL, *right = NULL;
	int dyd;
	node(int v) {
		val = v;
		prior = rand();
		dyd = 1;
	}
	void fix() {
		dyd = 1;

		if (left) {
			dyd += left->dyd;
		}

		if (right) {
			dyd += right->dyd;
		}
	}
	int mazl() {
		return 1 + (left ? left->dyd : 0);
	}
};

void print(node *&d) {
	if (d == NULL)
		return;

	print(d->left);
	cout << d->val << " ";
	print(d->right);
}

void merge(node *&d, node *l, node *r) {
	if (l == NULL)
		d = r;
	else if (r == NULL)
		d = l;
	else if (l->prior > r->prior) {
		d = l;
		merge(d->right, l->right, r);
		d->fix();
	}
	else {
		d = r;
		merge(d->left, l, r->left);
		d->fix();
	}
}

void split(node *d, int k, node *&l, node *&r) {
	if (d == NULL) {
		l = r = NULL;
	}
	else if (d->mazl() <= k) {
		split(d->right, k - d->mazl(), d->right, r);
		l = d;
		d->fix();
	}
	else {
		split(d->left, k, l, d->left);
		r = d;
		d->fix();
	}
}

/*link https://codeforces.com/group/nIDHK2OChY/contest/254094/problem/A */
/*input
2 1
2 1
*/
/*output
2 1
*/
/*input
3 2
1 2
1 1
*/
/*output
2 1 3
*/
/*input
3 3
1 3
2 3
1 3
*/
/*output
-1
*/

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	node *root = NULL;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		merge(root, root, new node(i));
	}

	vector<int> konv(n, -1), atgal(n, -1);

	// print(root);
	// cout << endl;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		node *a, *b, *c;
		split(root, y - 1, a, b);
		split(b, 1, b, c);
		int z = b->val;
		merge(root, b, a);
		merge(root, root, c);

		if ((atgal[z] == x or atgal[z] == -1) and (konv[x] == z or konv[x] == -1)) {
			atgal[z] = x;
			konv[x] = z;
		}
		else {
			cout << "-1";
			exit(0);
		}

		// print(root);
		// cout << endl;
	}

	int it = 0;

	for (auto && j : atgal) {
		if (j == -1) {
			while (konv[it] != -1) {
				it++;
			}

			it++;
			cout << it << " ";
		}
		else {
			cout << j + 1 << " ";
		}
	}
}