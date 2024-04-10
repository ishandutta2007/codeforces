#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

int N;
int M;
int D[MAXN];
int S[MAXN];

int main() {
	cin >> N;
	queue<int> q;
	M = 0;
	for(int i = 0; i < N; i++) {
		cin >> D[i] >> S[i];
		M += D[i];
		if(D[i] == 1) q.push(i);
	}

	M /= 2;

	cout << M << '\n';

	while(!q.empty()) {
		int i = q.front();
		q.pop();

		if(D[i] == 0) continue;
		assert(D[i] == 1);

		int j = S[i];
		cout << i << ' ' << j << '\n';

		D[i] --;
		D[j] --;
		S[j] ^= i;
		S[i] ^= j;

		if(D[j] == 1) q.push(j);
	}
	return 0;
}