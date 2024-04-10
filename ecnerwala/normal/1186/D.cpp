#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
ll Alo[MAXN];
ll Ahi[MAXN];

ll B[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		double v; cin >> v;
		Alo[i] = ll(floor(v + 1e-9));
		Ahi[i] = ll(ceil(v - 1e-9));
	}
	ll s = 0;
	for (int i = 0; i < N; i++) {
		B[i] = Alo[i];
		s += Alo[i];
	}
	for (int i = 0; s < 0 && i < N; i++) {
		B[i] = Ahi[i];
		s += Ahi[i] - Alo[i];
	}
	for (int i = 0; i < N; i++) cout << B[i] << '\n';

	return 0;
}