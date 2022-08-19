#include<iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1000000000 + 7;

const int MAXK = 8;

int N, K;

int state[MAXK];

ll dfs(int pos = 1) {
	if(pos == K) {
		for(int i = 1; i < K; i++) {
			int p = i;
			for(int j = 0; p && j < K; j++) p = state[p];
			if(p) return 0;
		}
		return 1;
	}
	ll out = 0;
	for(state[pos] = 0; state[pos] < K; state[pos]++) {
		if(state[pos] == pos) continue;
		out += dfs(pos + 1);
		out %= MOD;
	}
	return out % MOD;
}

ll go() {
	ll out = dfs();
	out *= K; // state[0]
	for(int i = K; i < N; i++) {
		out *= N - K;
		out %= MOD;
	}
	return out;
}

int main() {
	cin >> N >> K;
	cout << go() << '\n';
	return 0;
}