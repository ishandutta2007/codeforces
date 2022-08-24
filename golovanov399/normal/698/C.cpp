#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int C[22][22];

int main(){

	for (int i = 0; i < 22; i++){
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}

	int n = nxt(), k = nxt();
	vector<long double> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	const int N = 1 << n;
	vector<long double> P(N);
	vector<int> sz(N);
	for (int i = 0; i < n; i++){
		int I = 1 << i;
		for (int j = I - 1; j >= 0; j--){
			P[j + I] = P[j] + a[i];
			sz[j + I] = sz[j] + 1;
		}
	}

	vector<long double> f(N);
	for (int i = 0; i < N; i++){
		if (P[i] < 0.99999)
			f[i] = 1 / (1 - P[i]);
	}

	vector<int> xuita(k);
	for (int i = 0; i < k; i++){
		for (int j = 0; j <= k - 1 - i; j++){
			if (j % 2 == 0)
				xuita[i] += C[n - 1 - i][j];
			else
				xuita[i] -= C[n - 1 - i][j];
		}
	}

	// for (int i = 0; i < k; i++)
	// 	cerr << xuita[i] << " ";
	// cerr << "\n";

	cout << setprecision(10) << fixed;

	for (int i = 0; i < n; i++){
		if (a[i] < 0.00001){
			cout << 0.0 << " ";
			continue;
		}

		long double res = 0;
		for (int j = 0; j < N; j++){
			if (sz[j] > k - 1)
				continue;
			if (j & (1 << i))
				continue;
			res += f[j] * xuita[sz[j]];
		}
		res *= a[i];
		cout << res << " ";
	}
	cout << "\n";

	return 0;
}