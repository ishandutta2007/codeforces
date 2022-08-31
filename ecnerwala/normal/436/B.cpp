#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3e3;
const int MAXM = 3e3;

int N, M;
int K;

int res[MAXN];
char C[MAXN][MAXM];

int main() {
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++) cin >> C[i];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			switch(C[i][j]) {
				case '.': 
					break;
				case 'D':
					break;
				case 'L': 
					if(j - i >= 0) res[j - i] ++;
					break;
				case 'R':
					if(j + i < M) res[j + i] ++;
					break;
				case 'U':
					if(i % 2 == 0) res[j] ++;
					break;
			}
		}
	}
	for(int j = 0; j < M; j++) cout << res[j] << ((j + 1 == M) ? '\n' : ' ');
	return 0;
}