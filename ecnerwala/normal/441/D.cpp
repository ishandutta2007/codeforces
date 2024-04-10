#include<bits/stdc++.h>

using namespace std;

const int MAXN = 4e3;
int N;

int P[MAXN];

int M;
int C;

const int MAXK = MAXN * 2;

int K;
int X[2 * MAXK];

bool vis[MAXN];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> P[i], P[i] --;
	cin >> M;
	M = N - M;
	C = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < N; i++) {
		if(vis[i]) continue;
		C++;
		for(int j = i; !vis[j]; j = P[j]) {
			vis[j] = true;
		}
	}
	if(C < M) {
		//make more cycles
		int i = 0;
		while(C < M) {
			while(P[i] == i) i++;
			int nxt = N;
			for(int j = P[i]; j != i; j = P[j]) {
				if(j < nxt) nxt = j;
			}
			X[2 * K] = i;
			X[2 * K + 1] = nxt;
			swap(P[i], P[nxt]);
			K++;
			C++;
		}
	} else if (C > M){
		//merge cycles
		while(C > M) {
			memset(vis, 0, sizeof(vis));
			vis[0] = true;
			for(int j = P[0]; j != 0; j = P[j]) {
				vis[j] = true;
			}
			int nxt = 1;
			while(vis[nxt]) nxt++;
			X[2 * K] = 0;
			X[2 * K + 1] = nxt;
			swap(P[0], P[nxt]);
			K++;
			C--;
		}
	} else {
		K = 0;
	}

	cout << K << '\n';
	for(int i = 0; i < 2 * K; i++) {
		if(i) cout << ' ';
		cout << X[i] + 1;
	}
	cout << '\n';
	return 0;
}