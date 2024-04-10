/*input
4
1 1 1
1 0 0 1
9
get 1
get 2
get 3
get 4
pow 1
get 1
get 2
get 3
get 4

*/
#include <bits/stdc++.h>

using namespace std;

struct node {
	node *left = NULL, *right = NULL;
	int from, to;
	int suma = 0;
	bool inv = false;
	node(int from, int to): from(from), to(to) {
		if (from == to)
			return;

		left = new node(from, (from + to) / 2);
		right = new node((from + to) / 2 + 1, to);
	}
	node(int from, int to, int mas[]): from(from), to(to) {
		if (from == to) {
			suma = mas[from];
			return;
		}

		left = new node(from, (from + to) / 2, mas);
		right = new node((from + to) / 2 + 1, to, mas);
		suma = left->suma + right->suma;
	}
	void fix() {
		if (inv) {
			suma = to - from - suma + 1;

			if (from != to) {
				left->inv ^= inv;
				right->inv ^= inv;
			}
		}

		inv = false;
	}
	int get(int fr, int t) {
		fix();

		if (fr <= from and to <= t)
			return suma;

		if (t < from or to < fr)
			return 0;

		return left->get(fr, t) + right->get(fr, t);
	}
	void update(int fr, int t) {
		fix();

		if (t < from or to < fr)
			return;

		if (fr <= from and to <= t)
			inv ^= true;
		else {
			left->update(fr, t);
			right->update(fr, t);
			left->fix();
			right->fix();
			suma = left->suma + right->suma;
		}
	}
};

vector<int> med[200000];
int start[200000];
int pab[200000];
int timer = 0;

int tvarka[200000];

void dfs(int v) {
	tvarka[timer] = v;
	start[v] = timer;
	//cout << v << " ";
	timer++;

	for (auto && x : med[v])
		dfs(x);

	pab[v] = timer;
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		x--;
		med[x].push_back(i);
	}

	dfs(0);
	//cout << endl;

	int mas[n];

	for (int i = 0; i < n; i++)
		cin >> mas[i];

	int pagr[n];

	for (int i = 0; i < n; i++) {
		pagr[i] = mas[tvarka[i]];
		//cout << pagr[i] << " ";
	}

	//cout << endl;

	node medis(0, n - 1, pagr);

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		string s;
		int x;
		cin >> s >> x;
		x--;

		if (s[0] == 'g') {
			cout << medis.get(start[x], pab[x] - 1) << "\n";
			// /cout << start[x] << " " << pab[x] << endl;
		}
		else
			medis.update(start[x], pab[x] - 1);
	}


	return 0;
}