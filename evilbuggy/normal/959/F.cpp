#include <bits/stdc++.h>
using namespace std;

const int K = 20;
const int N = 100005;
const int mod = 1000000007;

int basis[N][K], sz[N], pw[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	pw[0] = 1;
	for(int i = 1; i <= n; i++){
		pw[i] = pw[i - 1] << 1;
		if(pw[i] >= mod)pw[i] -= mod;
	}

	sz[0] = 0;
	memset(basis[0], -1, sizeof(basis[0]));
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		sz[i] = sz[i - 1];
		for(int j = 0; j < K; j++){
			basis[i][j] = basis[i - 1][j];
		}
		for(int j = 0; j < K; j++){
			if((x >> j) & 1){
				if(basis[i][j] == -1){
					basis[i][j] = x;
					sz[i]++;
					break;
				}
				x ^= basis[i][j];
			}
		}
	}

	while(q--){
		int l, x;
		cin >> l >> x;
		for(int i = 0; i < K; i++){
			if((x >> i) & 1){
				if(basis[l][i] != -1){
					x ^= basis[l][i];
				}
			}
		}
		if(x == 0)cout << pw[l - sz[l]] << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}