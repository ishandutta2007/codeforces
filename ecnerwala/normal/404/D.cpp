#include<iostream>
#include<cstring>
#include<cassert>

using namespace std;

const int MOD = 1e9 + 7;

int N;
char c[2000000];

int numWays() {
	if(N == 1) {
		if(c[0] == '*') return 1;
		else if(c[0] == '0') return 1;
		else if(c[0] == '?') return 2;
		else return 0;
	}
	if(c[0] == '2') return 0;
	if(c[N - 1] == '2') return 0;
	for(int i = 0; i < N; i++) {
		//pass through for 0's
		if(c[i] == '0') {
			if(i > 0) {
				if(c[i - 1] == '?') c[i - 1] = '-';
				else if(c[i - 1] == '*') return 0;
			}
			if(i + 1 < N) {
				if(c[i + 1] == '?') c[i + 1] = '-';
				else if(c[i + 1] == '*') return 0;
			}
		}
	}
	for(int i = 0; i < N; i++) {
		int max = (i > 0) + ((i + 1) < N);
		if(c[i] == '0' + max) {
			if(i > 0) {
				if(c[i - 1] == '?') c[i - 1] = '*';
				else if(c[i - 1] != '*') return 0;
			}
			if(i + 1 < N) {
				if(c[i + 1] == '?') c[i + 1] = '*';
				else if(c[i + 1] != '*') return 0;
			}
		}
	}

	for(int i = 1; i + 1 < N; i++) {
		if(c[i] == '1') {
			int numq = (c[i - 1] == '?') + (c[i + 1] == '?');
			int numm = (c[i - 1] == '*') + (c[i + 1] == '*');
			int numf = 2 - numm - numq;
			if(numq == 0) {
				if(numf != 1) return 0;
			} else if(numq == 1) {
				if(numm == 0) {
					if(c[i - 1] == '?') c[i - 1] = '*';
					else if(c[i + 1] == '?') c[i + 1] = '*';
					else assert(false);
				} else if(numm == 1){
					if(c[i - 1] == '?') c[i - 1] = '-';
					else if(c[i + 1] == '?') c[i + 1] = '-';
					else assert(false);
				} else assert(false);
			}
		}
	}
	for(int i = N - 2; i > 0; i--) {
		if(c[i] == '1') {
			int numq = (c[i - 1] == '?') + (c[i + 1] == '?');
			int numm = (c[i - 1] == '*') + (c[i + 1] == '*');
			int numf = 2 - numm - numq;
			if(numq == 0) {
				if(numf != 1) return 0;
			} else if(numq == 1) {
				if(numm == 0) {
					if(c[i - 1] == '?') c[i - 1] = '*';
					else if(c[i + 1] == '?') c[i + 1] = '*';
					else assert(false);
				} else if(numm == 1){
					if(c[i - 1] == '?') c[i - 1] = '-';
					else if(c[i + 1] == '?') c[i + 1] = '-';
					else assert(false);
				} else assert(false);
			}
		}
	}

	//cerr << c << '\n';

	int res = 1;
	for(int i = 0; i < N; i++) {
		if(c[i] == '?' && (i == 0 || c[i - 1] != '1')) {
			res *= 2;
			if(res >= MOD) res -= MOD;
		}
	}
	return res;
}

int main() {
	cin >> c;
	N = strlen(c);
	cout << numWays() << '\n';
}