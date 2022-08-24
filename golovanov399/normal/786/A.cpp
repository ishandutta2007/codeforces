#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 14088;
short b[N][N/2];

struct Graph {
	int n;
	vector<int> out_deg;
	vector<int> size;

	Graph(int nn) {
		n = nn;
		out_deg.resize(n);
		size.resize(n);
	}

	void add_edge(int u, int v) {
		out_deg[u] += 1;
		b[v][size[v]] = u;
		++size[v];
	}

	vector<int> get_res() {
		vector<int> result(n, 2);
		vector<int> st;
		result[0] = 0;
		for (int i = 0; i < n; ++i) {
			if (out_deg[i] == 0) {
				st.push_back(i);
			}
		}

		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			for (int i = 0; i < size[v]; ++i) {
				int x = b[v][i];
				if (result[x] != 2) {
					continue;
				}
				out_deg[x] -= 1;
				if (result[v]) {
					if (out_deg[x] == 0) {
						result[x] = 0;
						st.push_back(x);
					}
				} else {
					result[x] = 1;
					st.push_back(x);
				}
			}
		}
		return result;
	}
};

int main(){
	cerr << sizeof(b) << "\n";

	int n = nxt();
	int cnt[2];
	vector<int> a[2];
	for (int i = 0; i < 2; ++i) {
		cnt[i] = nxt();
		a[i].resize(cnt[i]);
		for (int j = 0; j < cnt[i]; ++j) {
			a[i][j] = nxt();
		}
	}

	Graph graph(2 * n - 1);
	for (int i = 1; i < n; ++i) {
		for (int x : a[0]) {
			int j = i - x;
			if (j == 0) {
				graph.add_edge(i, 0);
			} else {
				if (j < 0) {
					j += n;
				}
				j += (n - 1);
				graph.add_edge(i, j);
			}
		}
		for (int x : a[1]) {
			int j = i - x;
			if (j == 0) {
				graph.add_edge(i + (n - 1), 0);
			} else {
				if (j < 0) {
					j += n;
				}
				graph.add_edge(i + (n - 1), j);
			}
		}
	}

	string ans[3] = {"Lose", "Win", "Loop"};
	cout.sync_with_stdio(0);

	vector<int> res = graph.get_res();
	reverse(res.begin() + 1, res.begin() + n);
	reverse(res.begin() + n, res.begin() + 2 * n - 1);
	for (int i = 1; i < 2 * n - 1; ++i) {
		cout << ans[res[i]] << " ";
		if (i == n - 1) {
			cout << "\n";
		}
	}
	cout << "\n";
	// cout << "\n";

	return 0;
}