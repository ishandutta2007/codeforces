#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int a[N], b[N][N], f[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i][i] = a[i];
		f[i][i] = a[i];
	}
	for(int len = 2; len <= n; len++){
		for(int i = 1, j = len; j <= n; i++, j++){
			b[i][j] = b[i][j - 1]^b[i + 1][j];
			f[i][j] = max({f[i][j - 1], f[i + 1][j], b[i][j]});
		}
	}
	int q;
	cin >> q;
	int l, r;
	while(q--){
		cin >> l >> r;
		cout << f[l][r] << '\n';
	}

	return 0;
}