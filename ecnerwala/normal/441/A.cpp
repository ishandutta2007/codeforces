#include<bits/stdc++.h>

using namespace std;

const int MAXN  = 100;
int N;
int V;
bool good[MAXN];

int main() {
	cin >> N >> V;
	int p = 0;
	for(int i = 0; i < N; i++) {
		int k; cin >> k;
		good[i] = false;
		for(int j = 0; j < k; j++) {
			int s; cin >> s;
			if(V > s) good[i] = true;
		}
		p += good[i];
	}
	cout << p << '\n';
	for(int i = 0; i < N; i++) {
		if(good[i]) {
			cout << i+1 << ((--p) ? ' ' : '\n');
		}
	}
	return 0;
}