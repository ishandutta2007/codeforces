#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 20;
const int MAXM = 1e3 + 20;

const int MAXK = 1e6 + 20;

ll N, M;
ll A[MAXN][MAXM];
ll K;

ll P;

ll rowVal[MAXK];
ll colVal[MAXK];

int main() {
	cin >> N >> M >> K >> P;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	//precompute rows
	priority_queue<ll> pq;
	for(int i = 0; i < N; i++) {
		int s = 0;
		for(int j = 0; j < M; j++) {
			s += A[i][j];
		}
		pq.push(s);
	}
	rowVal[0] = 0;
	for(int i = 1; i <= K; i++) {
		rowVal[i] = rowVal[i - 1];
		ll v = pq.top(); pq.pop();
		rowVal[i] += v;
		v -= P * M;
		pq.push(v);
	}

	while(!pq.empty()) pq.pop();

	for(int i = 0; i < M; i++) {
		int s = 0;
		for(int j = 0; j < N; j++) {
			s += A[j][i];
		}
		pq.push(s);
	}
	colVal[0] = 0;
	for(int i = 1; i <= K; i++) {
		colVal[i] = colVal[i - 1];
		ll v = pq.top(); pq.pop();
		colVal[i] += v;
		v -= P * N;
		pq.push(v);
	}

	ll res = rowVal[0] + colVal[K];
	for(int i = 0; i <= K; i++) {
		ll v = rowVal[i] + colVal[K - i] - i * (K - i) * P;
		if(v > res) res = v;
	}
	cout << res << '\n';
	return 0;
}