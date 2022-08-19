#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
int P[MAXN];
int L[MAXN];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> P[i], P[i] --, L[P[i]] = i;
	int res = 1;
	int cnt = 1;
	for(int i = 1; i < N; i++) {
		if(L[i] > L[i - 1]) {
			cnt++;
			res = max(res, cnt);
		} else {
			cnt = 1;
		}
	}
	cout << N - res << '\n';
	return 0;
}