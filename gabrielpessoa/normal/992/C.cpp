#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 1e5+5;
const ll mod = 1e9+7;
const int m = 2; // size of matrix

struct Matrix { 
	ll mat[m][m];
	Matrix operator * (const Matrix &p) {
		Matrix ans;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				for(int k = ans.mat[i][j] = 0; k < m; k++)
					ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % mod;
		return ans;
	}
};

Matrix fExp(Matrix a, ll b) {
	Matrix ans;	
	for(int i = 0; i < m; i++) for(int j = 0; j < m; j++)
		ans.mat[i][j] = i == j;
	while(b) {
		if(b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int main() {
	ll x, k;
	cin >> x >> k;
	if(x == 0) {
		cout << 0 << endl;
		return 0;
	}
	x %= mod;
	Matrix base;
	base.mat[0][0] = 2;
	base.mat[0][1] = -1;
	base.mat[1][0] = 0;
	base.mat[1][1] = 1;
	base = fExp(base, k);
	//cout << mod*mod*2+mod << endl;
	ll ans = (x*2*base.mat[0][0] + base.mat[0][1]) % mod;
	if(ans < 0) ans += mod;
	cout << ans << endl;
	
	//     [2 -1] * [ans]   = [2ans + 1]
	// 	 [0  1]   [1]        [1]
	return 0;
}