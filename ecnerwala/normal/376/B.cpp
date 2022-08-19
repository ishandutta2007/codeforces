#include<iostream>

using namespace std;

typedef long long ll;
const int MAXN = 200;
int N, M;
ll debt[200];

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		debt[a] -= c;
		debt[b] += c;
	}

	ll ans = 0;
	for(int i = 0; i < N; i++) {
		if(debt[i] > 0) ans += debt[i];
	}
	cout << ans << '\n';
	return 0;
}