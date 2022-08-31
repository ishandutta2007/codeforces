#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

const double PI = 3.14159265358;

const int MAXN = 23;

double dp[1 << MAXN];

int N;
int X[MAXN], Y[MAXN], A[MAXN];

int main() {
	cin >> N;
	int L, R;
	cin >> L >> R;
	for(int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i] >> A[i];
	}
	double res = L;
	for(int b = 0; b < (1 << N); b++) dp[b] = L;
	for(int b = 0; b < (1 << N); b++) {
		double v = dp[b];
		if(v > res) res = v;
		for(int p = 0; p < N; p++) {
			if(!(b & (1 << p))) {
				double x = X[p], y = Y[p], a = A[p];
				a *= PI;
				a /= 180;
				a += atan((v - x) / y);
				double nv = x + y * tan(a);
				if(nv < v || nv > R) {
					nv = R;
				}

				int np = b + (1 << p);

				if(nv > dp[np]) dp[np] = nv;
			}
		}
	}

	res -= L;

	cout << fixed << setprecision(9);
	cout << res << '\n';
}