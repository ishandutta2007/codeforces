#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 2000;
const int MAXM = 4000;

int N, M;
int v[MAXM];

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> v[i];
	long long res = 0;
	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		res += min(v[a], v[b]);
	}
	cout << res << '\n';
	return 0;
}