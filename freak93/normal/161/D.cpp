#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> E[50005];
int many[50005][505];

long long answer;
int been[50005];
void dfs(int nod) {
	for (auto it = E[nod].begin(); it != E[nod].end(); ++it)
		if (been[*it] == 0) {
			been[*it] = nod;
			dfs(*it);
			for (int j = 0; j < K; ++j)
				many[nod][j + 1] += many[*it][j];
		}
	
	long long buffer = 0;
	for (auto it = E[nod].begin(); it != E[nod].end(); ++it)
		if (been[*it] == nod)
		for (int j = 1; j <= K / 2; ++j)
			if (j != K / 2 || K % 2)
				answer += 1LL * (many[nod][j] - many[*it][j - 1]) * many[*it][K - j - 1];
			else
				buffer += 1LL * (many[nod][j] - many[*it][j - 1]) * many[*it][K - j - 1];
	answer += buffer / 2;
	
	answer += many[nod][K];
	many[nod][0] = 1;
}

int main() {
	int N;
	cin >> N >> K;
	if (K == 1) {
		cout << N - 1;
		return 0;
	}
	for (int i = 1; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	been[1] = 1;
	dfs(1);
	cout << answer;
}