#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 2e5;

int N, K;
pii D[MAXN];
int par[MAXN];

bool good() {
	for(int i = 0; i < N; i++) {
		D[i].second = i;
	}
	sort(D, D + N);
	int numC = -1;
	int p = 0;
	if(D[0].first != 0) return false;
	par[D[0].second] = -1;
	if(K == 1) {
		if(N == 2) {
			if(D[1].first == 1) par[D[1].second] = D[0].second;
			else return false;
			return true;
		} else {
			return false;
		}
	}
	for(int i = 1; i < N; i++) {
		while(p < i && D[p].first + 1 < D[i].first) p++, numC = 0;
		if(D[p].first + 1 != D[i].first) return false;
		par[D[i].second] = D[p].second;
		numC ++;
		if(numC == K - 1) {
			p++, numC = 0;
		}
	}
	return true;
}

int main() {
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		cin >> D[i].first;
	}
	if(good()) {
		cout << N - 1 << '\n';
		for(int i = 0; i < N; i++) {
			if(par[i] != -1) {
				cout << (i + 1) << ' ' << (par[i] + 1) << '\n';
			}
		}
	} else {
		cout << -1 << '\n';
	}
	return 0;
}