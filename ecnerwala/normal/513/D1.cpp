#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e6;
const int MAXC = 2e5;

int N, C;

vector<int> cons[MAXN][2];

int V; // current vertex number
int ch[MAXN][2];

// currently at i, must hit >= t
bool dfs(int i, int t) {
	assert(i == V);
	for(int d = 0; d < 2; d++) {
		sort(cons[i][d].begin(), cons[i][d].end());
	}

	if(cons[i][0].size()) {
		int n = ++V;
		ch[i][0] = n;
		if(!dfs(n, cons[i][0].back())) return false;
	}

	if(!cons[i][1].empty() && V >= cons[i][1].front()) return false;

	if(cons[i][1].size()) t = max(t, cons[i][1].back());

	if(t > V) {
		int n = ++V;
		ch[i][1] = n;
		if(!dfs(n, t)) return false;
	}

	return true;
}

bool go() {
	cin >> N >> C;
	for(int i = 0; i < C; i++) {
		int a, b; string dir;
		cin >> a >> b >> dir;
		if(b <= a) return false;

		cons[a][dir == "RIGHT"].push_back(b);
	}
	V = 1;
	return dfs(1, N);
}

void print(int a) {
	if(!a) return;
	print(ch[a][0]);
	cout << a << ' ';
	print(ch[a][1]);
}

int main() {
	bool res = go();
	if(res) {
		print(1);
		cout << '\n';
	} else {
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}