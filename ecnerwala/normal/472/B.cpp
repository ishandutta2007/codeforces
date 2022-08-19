#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4000;
int N, K;
int F[MAXN];

int main() {
	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> F[i];
	sort(F, F + N);
	reverse(F, F + N);
	int res = 0;
	for(int i = 0; i < N; i += K) {
		res += (F[i] - 1) * 2;
	}
	cout << res << '\n';
	return 0;
}