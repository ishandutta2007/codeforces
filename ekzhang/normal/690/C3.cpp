#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200013
#define MAXLG 19

int N;
int parent[MAXN];
int L[MAXN][MAXLG];
int depth[MAXN];

void lcadp_init(int n) {
	L[n][0] = parent[n];
	for (int i = 1; i < MAXLG; i++) {
		L[n][i] = L[L[n][i - 1]][i - 1];
	}
}

int lca(int u, int v) {
	for (int i = MAXLG - 1; i >= 0; i--) {
		if (depth[u] - (1<<i) >= depth[v])
			u = L[u][i];
		if (depth[v] - (1<<i) >= depth[u])
			v = L[v][i];
	}
	for (int i = MAXLG - 1; i >= 0; i--) {
		if (L[u][i] != L[v][i]) {
			u = L[u][i];
			v = L[v][i];
		}
	}
	return (u == v ? u : parent[u]);
}

int dist(int u, int v) {
	return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	int a = 0, b = 0, d = 0;

	for (int i = 1; i < N; i++) {
		cin >> parent[i];
		parent[i]--;
		depth[i] = depth[parent[i]] + 1;
		lcadp_init(i);

		int dia = dist(i, a);
		int dib = dist(i, b);
		if (dia >= dib && dia > d) {
			d = dia;
			b = i;
		}
		else if (dib > d) {
			d = dib;
			a = i;
		}
		cout << d << ' ';
	}

	cout << endl;
	return 0;
}