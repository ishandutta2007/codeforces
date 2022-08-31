#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;

int N, M;
int K;
bool black[MAXN][MAXM];

inline bool bad(int a, int b) {
	return black[a][b] && black[a + 1][b] && black[a][b + 1] && black[a+1][b+1];
}

inline bool check(int a, int b) {
	black[a][b] = true;
	return !(bad(a, b)|| bad(a-1, b)|| bad(a-1, b-1)|| bad(a, b-1));
}

int main() {
	cin >> N >> M >> K;
	for(int v = 0; v < K; v++) {
		int i, j; cin >> i >> j;
		if(!check(i, j)) {
			cout << v + 1 << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return 0;
}