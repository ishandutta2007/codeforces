#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e3;
int N;
int P[MAXN];
vector<int> ch[MAXN];
int C[MAXN];

vector<int> dfs(int cur) {
	vector<int> ans;
	for (int nxt : ch[cur]) {
		auto v = dfs(nxt);
		ans.insert(ans.end(), v.begin(), v.end());
	}
	if (C[cur] > int(ans.size())) {
		cout << "NO" << '\n';
		exit(0);
	}
	ans.insert(ans.begin() + C[cur], cur);
	return ans;
}

int A[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i] >> C[i];
		ch[P[i]].push_back(i);
	}
	vector<int> ans = dfs(ch[0][0]);
	for (int i = 0; i < N; i++) A[ans[i]] = i+1;
	cout << "YES" << '\n';
	for (int i = 1; i <= N; i++) {
		cout << A[i] << " \n"[i==N];
	}

	return 0;
}