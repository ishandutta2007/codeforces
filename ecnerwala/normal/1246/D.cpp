#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
int P[MAXN];
vector<int> ch[MAXN];
int height[MAXN];

void dfs(int cur) {
	height[cur] = 0;
	for (int nxt : ch[cur]) {
		dfs(nxt);
		height[cur] = max(height[cur], height[nxt] + 1);
	}
	sort(ch[cur].begin(), ch[cur].end(), [&](int i, int j) { return height[i] > height[j]; });
}

vector<int> bamboo;
vector<int> ops;
void dfs2(int cur) {
	for (int nxt : ch[cur]) {
		if (!bamboo.empty()) ops.push_back(bamboo.back());
		dfs2(nxt);
	}
	bamboo.push_back(cur);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	P[0] = -1;
	for (int i = 1; i < N; i++) {
		cin >> P[i];
		ch[P[i]].push_back(i);
	}

	dfs(0);
	dfs2(0);
	reverse(bamboo.begin(), bamboo.end());
	reverse(ops.begin(), ops.end());
	for (int i = 0; i < N; i++) {
		cout << bamboo[i] << " \n"[i+1==N];
	}
	cout << int(ops.size()) << '\n';
	for (int i = 0; i < int(ops.size()); i++) {
		cout << ops[i] << " \n"[i+1==int(ops.size())];
	}
	if (ops.empty()) {
		cout << '\n';
	}

	return 0;
}