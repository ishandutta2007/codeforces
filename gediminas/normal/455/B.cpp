/*input
1 2
ab
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
	Node *tol[26] = {};
};

void pridek(Node *&d, string &s, int pos) {
	if (d == NULL)
		d = new Node();

	if (pos >= s.size())
		return;

	pridek(d->tol[s[pos] - 'a'], s, pos + 1);
}

pair<bool, bool> dfs(Node *&d) { // laimi, pralaimi
	pair<bool, bool> ret(0, 0);
	int t = 0;

	for (int i = 0; i < 26; i++) {
		if (d->tol[i] != NULL) {
			pair<bool, bool> x = dfs(d->tol[i]);

			if (!x.second)
				ret.second = 1;

			if (!x.first)
				ret.first = 1;

			t++;
		}
	}

	if (t == 0)
		ret = {0, 1};

	return ret;
}

int main () {
	int n, k;
	cin >> n >> k;

	Node *root = NULL;

	for (int i = 0; i < n; i++) {
		string groupel;
		cin >> groupel;
		pridek(root, groupel, 0);
	}

	pair<bool, bool> x = dfs(root);
	bool kuris = 0;

	if (x.first and x.second)
		kuris = 0;
	else if (x.first)
		kuris = (k + 1) % 2;
	else if (x.second)
		kuris = 1;
	else
		kuris = 1;

	cout << (kuris ? "Second" : "First");


	return 0;
}