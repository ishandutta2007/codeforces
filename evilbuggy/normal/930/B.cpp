#include <bits/stdc++.h>
using namespace std;

const int K = 26;
const int N = 5005;

int f[K][N][K];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int total = 0;
	int n = (int)s.size();
	memset(f, 0, sizeof(f));
	for(int k = 0; k < n; k++){
		int ch = s[k] - 'a';
		for(int p = 1; p < n; p++){
			int l = k + p;
			if(l >= n)l -= n;
			int dh = s[l] - 'a';
			f[ch][p][dh]++;
		}
	}
	for(int i = 0; i < K; i++){
		int maximum = 0;
		for(int d = 1; d < n; d++){
			int cnt = 0;
			for(int j = 0; j < K; j++){
				if(f[i][d][j] == 1)cnt++;
			}
			maximum = max(maximum, cnt);
		}
		total += maximum;
	}
	double answer = total*1.0/n;
	cout << setprecision(30) << answer << '\n';

	return 0;
}