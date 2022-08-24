#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

struct Trie {
	vector<vector<int>> a;
	vector<char> flag;
	vector<int> par;

	Trie() {
		a.assign(1, vector<int>(2, -1));
		flag.assign(1, 0);
		par.assign(1, -1);
	}

	void add(int n) {
		vector<int> lol;
		while (n) {
			lol.push_back(n % 2);
			n /= 2;
		}
		lol.pop_back();
		reverse(all(lol));
		int v = 0;
		for (int x : lol) {
			int to = a[v][x];
			if (to == -1) {
				to = a.size();
				a.emplace_back(2, -1);
				flag.push_back(0);
				par.push_back(v);
				a[v][x] = to;
			}
			v = to;
		}
		flag[v] = 1;
	}

	void build_vector(vector<int>& ar, int v, int cur) {
		ar.push_back(cur);
		for (int i = 0; i < 2; i++) {
			if (a[v][i] != -1) {
				build_vector(ar, a[v][i], cur * 2 + i);
			}
		}
	}

	void relax(int n, vector<int>& ans) {
		int num = n;
		vector<int> lol;
		while (n) {
			lol.push_back(n % 2);
			n /= 2;
		}
		lol.pop_back();
		reverse(all(lol));
		int v = 0;
		for (int x : lol) {
			v = a[v][x];
		}
		if (!flag[v]) {
			return;
		}

		int w = v;
		while (w > -1 && flag[w]) {
			w = par[w];
		}
		if (w != -1) {
			flag[w] = 1;
			flag[v] = 0;
		} else {
			ans.push_back(num);
		}
	}
};

int main(){

	int n = nxt();
	Trie trie;
	for (itn i = 0; i < n; i++) {
		trie.add(nxt());
	}

	vector<int> vec;
	trie.build_vector(vec, 0, 1);
	sort(all(vec));
	vector<int> ans;
	for (int i = (int)vec.size() - 1; i >= 0; --i) {
		trie.relax(vec[i], ans);
	}

	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}