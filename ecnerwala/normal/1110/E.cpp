#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
ll C[MAXN];
ll T[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> C[i];
	for (int i = 0; i < N; i++) cin >> T[i];
	if (C[0] != T[0] || C[N-1] != T[N-1]) {
		cout << "No\n";
		return 0;
	}
	for (int i = 0; i < N-1; i++) {
		C[i] -= C[i+1];
		T[i] -= T[i+1];
	}
	N--;
	//for (int i = 0; i < N; i++) { cerr << C[i] << ' '; } cerr << '\n';
	//for (int i = 0; i < N; i++) { cerr << T[i] << ' '; } cerr << '\n';
	sort(C, C + N);
	sort(T, T + N);
	for (int i = 0; i < N; i++) {
		if (C[i] != T[i]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}