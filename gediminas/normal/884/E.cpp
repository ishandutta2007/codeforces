/*input
3 4
F
9
1
*/
#include <bits/stdc++.h>

using namespace std;

template<int N>
struct UnionFind {
	int par[N];
	int siz[N];
	UnionFind() {
		for (int i = 0; i < N; i++) {
			par[i] = i;
			siz[i] = 1;
		}
	}
	int operator[](const int &x) {
		return getParent(x);
	}
	int getParent(int x) {
		int t = x;

		while (par[x] != x)
			x = par[x];

		par[t] = x;
		return x;
	}
	int getSize(const int &x) {
		return siz[getParent(x)];
	}
	bool merge(int x, int y) {
		x = getParent(x);
		y = getParent(y);

		if (x == y)
			return false;

		if (siz[x] > siz[y])
			swap(x, y); // siz[x] is smaller

		par[x] = y;
		siz[y] += siz[x];
		return true;

	}
	bool connected(const int &x, const int &y) {
		return getParent(x) == getParent(y);
	}
};

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int ats = 0;

	UnionFind<32768> *par = new UnionFind<32768>;

	bool nr[16384] = {};

	for (int i = 0; i < n; i++) {
		bool piln[m] = {};

		for (int j = 0; j < m / 4; j++) {
			char x;
			cin >> x;
			int y;

			if (isdigit(x))
				y = x - '0';
			else
				y = x - 'A' + 10;

			piln[j * 4] = (y & 8);
			piln[j * 4 + 1] = (y & 4);
			piln[j * 4 + 2] = (y & 2);
			piln[j * 4 + 3] = (y & 1);
		}

		for (int i = 1; i < m; i++) {
			if (piln[i] and piln[i - 1])
				par->merge(i, i - 1);
		}

		bool laim[32768] = {};

		for (int i = 0; i < m; i++) {
			if (piln[i] and nr[i]) {
				par->merge(i, 16384 + i);
				laim[par->getParent(i)] = true;
			}
		}

		for (int i = 0; i < m; i++) {
			if (nr[i] and !laim[par->getParent(16384 + i)]) {
				ats++;
				laim[par->getParent(16384 + i)] = true;
			}
		}

		UnionFind<32768> *nauj = new UnionFind<32768>;
		int help[16384] = {};

		for (int i = 0; i < m; i++) {
			if (piln[i]) {
				int parent = par->getParent(i);

				if (parent >= 16384) {
					if (help[parent - 16384] == 0)
						help[parent - 16384] = i + 1;

					parent = help[parent - 16384] - 1;
				}

				nauj->merge(16384 + i, 16384 + parent);
			}
		}

		swap(par, nauj);
		delete nauj;

		for (int i = 0; i < m; i++)
			nr[i] = piln[i];
	}

	set<int> a;

	for (int i = 0; i < m; i++) {
		if (nr[i])
			a.insert(par->getParent(16384 + i));
	}

	cout << ats + a.size();

	return 0;
}