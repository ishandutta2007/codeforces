#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

int N, K;

int A[MAXN];

int onimber(int a) {
	if(a == 1) return 1;
	else if(a == 2) return 0;
	else if(a == 3) return 1;
	else if(a == 4) return 2;
	else if(a % 2 == 1) return 0;
	else {
		if(onimber(a / 2) == 1) return 2;
		else return 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> N >> K;

	int v = 0;
	if(K % 2 == 0) {
		for(int i = 0; i < N; i++) {
			int a; cin >> a;
			if(a == 1) {
				v ^= 1;
			} else if(a == 2) {
				v ^= 2;
			} else if(a % 2 == 0) {
				v ^= 1;
			} else {
				//v ^= 0;
			}
		}
	} else {
		for(int i = 0; i < N; i++) {
			int a; cin >> a;
			v ^= onimber(a);
		}
	}
	cout << (v ? "Kevin" : "Nicky") << '\n';

	return 0;
}