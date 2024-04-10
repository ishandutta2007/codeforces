#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

map<long long, int> o;
int t;

long long C(long long x) {
	long long pot = 1;
	long long pat = 0;
	
	while (x > 0) {
		pat += (x%2) * pot;
		pot *= 10;
		x /= 10;
	}

	return pat;
}

void solve() {
	for (scanf("%d", &t); t; t--) {
		long long x;
		char op;
		scanf(" %c %lld", &op, &x);


		if (op == '+') {
			o[C(x)]++;
		}
		else if (op == '-') {
			o[C(x)]--;
		}
		else {
			printf("%d\n", o[x]);
		}
	}
}


int main() {
    solve();
}