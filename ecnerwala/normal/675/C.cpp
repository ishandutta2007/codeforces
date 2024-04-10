#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5;
int N;
ll A[MAXN];
ll S[MAXN];

int main() {
	cin >> N;
	S[0] = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		S[i + 1] = S[i] + A[i];
	}
	assert(S[N] == 0);
	sort(S, S + N);
	int res = N;
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		if(i && S[i - 1] == S[i]) {
		} else {
			cnt = 0;
		}
		cnt++;
		res = min(res, N - cnt);
	}
	cout << res << '\n';
	return 0;
}