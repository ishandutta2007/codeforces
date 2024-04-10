#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

const int S = 3;
int K, N[S], T[S];

priority_queue<int, vector<int>, greater<int>> pq[3];

int main() {
	cin >> K;
	for(int i = 0; i < S; i++) cin >> N[i];
	for(int i = 0; i < S; i++) cin >> T[i];
	for(int i = 0; i < S; i++) {
		for(int j = 0; j < N[i]; j++) {
			pq[i].push(0);
		}
	}
	int res = 0;
	for(int i = 0; i < K; i++) {
		res = 0;
		for(int j = 0; j < S; j++) {
			int v = pq[j].top(); pq[j].pop();
			if(v > res) res = v;
		}
		for(int j = 0; j < S; j++) {
			pq[j].push(res + T[j]);
		}
		res += T[0] + T[1] + T[2];
	}
	cout << res << '\n';
	return 0;
}