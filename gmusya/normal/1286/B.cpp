#include <iostream>
#include <vector>

using namespace std;

int n, root, timer = 0;
vector <bool> used;
vector <int> c, p, kids, answer, in, out;
vector <vector <int>> g;

void dfs1(int v) {
	in[v] = timer++;
	used[v] = true;
	for (int to : g[v]) {
		if (!used[to])
			dfs1(to);
		kids[v] += kids[to] + 1;
	}
	out[v] = timer++;
}

void dfs2(int v) {
	used[v] = true;
	for (int to : g[v]) {
		if (!used[to])
			dfs2(to);
	}
	if (kids[v] == c[v]) {
		answer.push_back(v);
		return;
	}
	int cnt = 0;
	for (int i = 0; i < answer.size(); i++) {
		if (in[v] < in[answer[i]] && out[v] > out[answer[i]])
			cnt++;
		if (cnt > c[v]) {
			answer.insert(answer.begin() + i, v);
			break;
		}
	}
}

int main() {
	cin >> n;
	g.resize(n), c.resize(n), kids.resize(n), used.resize(n), p.resize(n), in.resize(n), out.resize(n);
	for (int i = 0; i < n; i++) {;
		cin >> p[i] >> c[i];
		p[i]--;
		if (p[i] == -1)
			root = i;
		else
			g[p[i]].push_back(i);
	}
	dfs1(root);
	for (int i = 0; i < n; i++)
		if (c[i] > kids[i]) {
			cout << "NO";
			return 0;
		}
	used.assign(n, false);
	dfs2(root);
	cout << "YES" << endl;
	vector <int> k(n);
	for (int i = 0; i < n; i++)
		k[answer[i]] = i;
	for (int i = 0; i < n; i++)
		cout << k[i] + 1 << " ";
	return 0;
}