#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M, K;

int P;
pii pts[100000];


int main() {
	cin >> N >> M >> K;
	P = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			pts[P] = pii(i + 1, ((i % 2) ? (M - 1 - j) : (j)) + 1);
			P++;
		}
	}
	cout << P - 2 * (K - 1);
	int i;
	for(i = 0; i < P - 2 * (K - 1); i++) {
		cout << ' ' << pts[i].first << ' ' << pts[i].second;
	}
	cout << '\n';
	for(int k = 1; k < K; k++) {
		cout << 2;
		for(int j = 0; j < 2; j++, i++) {
			cout << ' ' << pts[i].first << ' ' << pts[i].second;
		}
		cout << '\n';
	}
	return 0;
}