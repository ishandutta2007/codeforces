#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 20;

int N;
int L[MAXN], R[MAXN];

// probability that all except i are <= v
ld prob(int v, int i) {
	ld res = 1;
	for(int j = 0; j < N; j++) {
		if(j == i) continue;

		res *= max(0, min(R[j], v) - L[j] + 1);

		res /= (R[j] - L[j] + 1);
	}
	return res;
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];
	}


	ld res = 0;

	for(int v = 0; v < 20000; v++) {
		res += (prob(v, -1) - prob(v - 1, -1)) * v;
		for(int i = 0; i < N; i++) {
			// i is strictly above
			ld val = prob(v, i) - prob(v - 1, i);

			val *= max(0, R[i] - max(v + 1, L[i]) + 1);
			val /= (R[i] - L[i] + 1);
			res += val * v;

			// overcounting things with exactly 1
			if(R[i] >= v && v >= L[i]) {
				res -= prob(v - 1, i) / (R[i] - L[i] + 1) * v;
			}
		}
	}
	cout << fixed << setprecision(20) << res << '\n';
	return 0;
}