#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;

int A[maxn][maxn];
int idx[maxn*maxn];
int idy[maxn*maxn];

void init(){
	A[1][1] = 0;
	int xorh = 1;
	int xorv = 2;
	for(int len = 2; len <= 32; len <<= 1){
		int hen = len >> 1;
		for(int i = 1; i <= len; i++){
			for(int j = 1; j <= len; j++){
				if(i <= hen && j <= hen)continue;
				if(i <= hen){
					A[i][j] = A[i][len + 1 - j]^xorh;
				}else{
					A[i][j] = A[len + 1 - i][j]^xorv;
				}
			}
		}
		xorh <<= 2;
		xorv <<= 2;
	}
	for(int i = 1; i <= 32; i++){
		for(int j = 1; j <= 32; j++){
			idx[A[i][j]] = i;
			idy[A[i][j]] = j;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	int n; cin >> n;
	int k; cin >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= n; j++){
			cout << (A[i][j - 1] ^ A[i][j]) << ' ';
		}
		cout << endl;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << (A[i - 1][j] ^ A[i][j]) << ' ';
		}
		cout << endl;
	}
	int cur = A[1][1];
	while(k--){
		int x; cin >> x; cur ^= x;
		cout << idx[cur] << " " << idy[cur] << endl;
	}

	return 0;
}