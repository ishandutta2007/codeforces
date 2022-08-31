#include<bits/stdc++.h>

using namespace std;
const int MAXN = 200;
int N;

double P[MAXN];

double go() {

	sort(P, P + N);
	if(P[N - 1] * 2 >= 1) return P[N - 1];

	double pnone = 1;
	double pone = 0;
	for(int i = N - 1; i >= 0; i--) {
		double p = P[i];
		if(pnone > pone) {
			pone += (pnone - pone) * p;
			pnone -= pnone * p;
		}
	}
	return pone;
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> P[i];
	}
	cout <<	fixed << setprecision(10) << go() << '\n';
}