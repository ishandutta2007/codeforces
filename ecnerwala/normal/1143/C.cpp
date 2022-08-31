#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
int P[MAXN];
int C[MAXN];
bool isBad[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i] >> C[i];
		if (P[i] == -1) P[i] = 0;
		if (C[i] == 0) {
			isBad[P[i]] = true;
			isBad[i] = true;
		}
	}
	vector<int> res;
	for (int i = 1; i <= N; i++) {
		if (!isBad[i]) res.push_back(i);
	}
	if (res.empty()) res.push_back(-1);
	for (int i = 0; i < int(res.size()); i++) {
		cout << res[i] << " \n"[i+1 == int(res.size())];
	}

	return 0;
}