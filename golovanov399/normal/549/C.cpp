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

const int N = 100;
int a[N][N][N][2][2];

int res(int m, int c, int d, int st, int pl){
	if (a[m][c][d][st][pl] > -1)
		return a[m][c][d][st][pl];
	if (m == 0){
		return a[m][c][d][st][pl] = (st != pl);
	}
	if (c == 0){
		return a[m][c][d][st][pl] = (res(m - 1, c, d - 1, st, pl ^ 1) ^ 1);
	} else 
	if (d == 0){
		return a[m][c][d][st][pl] = (res(m - 1, c - 1, d, st ^ 1, pl ^ 1) ^ 1);
	} else {
		return a[m][c][d][st][pl] = ((res(m - 1, c, d - 1, st, pl ^ 1) & res(m - 1, c - 1, d, st ^ 1, pl ^ 1)) ^ 1);
	}
}

int stupid(int n, int k, int c){
	return res(n - k, c, n - c, c % 2, 0);
}

int ans(int n, int k, int c){
	if (n % 2 == 0){
		if (k == n){
			return (c % 2 ? 1 : 0);
		} else
		if (k % 2 == 0){
			return (0);
		} else {
			return (k + c * 2 > n ? 1 : 0);
		}
	} else {
		if (k == n){
			return (c % 2 ? 1 : 0);
		} else
		if (k % 2 == 0){
			return (k + c * 2 > n && c * 2 - k < n ? 1 : 0);
		} else {
			return (2 * c - k >= n ? 1 : 0);
		}
	}
}

int main(){

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int ij = 0; ij < N; ij++){
				a[i][j][ij][0][0] = a[i][j][ij][0][1] = a[i][j][ij][1][0] = a[i][j][ij][1][1] = -1;
			}
		}
	}

	// int n = nxt();
	// for (int k = 0; k <= n; k++){
	// 	for (int c = 0; c <= n; c++){
	// 		cout << res(n - k, c, n - c, c % 2, 0) << " ";
	// 	}
	// 	cout << "\n";
	// }
	
	int n = nxt(), k = nxt();
	int c = 0;
	for (int i = 0; i < n; i++){
		c += nxt() % 2;
	}

	puts(ans(n, k, c) ? "Stannis" : "Daenerys");

	return 0;
}