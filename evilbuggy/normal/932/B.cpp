#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int f[N], g[N], s[N][10];

void init(){
	memset(s[0], 0, sizeof(s[0]));
	for(int n = 1; n < N; n++){
		if(n < 10){
			f[n] = g[n] = n;
		}else{
			if(n%10 == 0){
				f[n] = f[n/10];
			}else{
				f[n] = f[n/10]*(n%10);
			}
			g[n] = g[f[n]];
		}
		memcpy(s[n], s[n - 1], sizeof(s[n]));
		s[n][g[n]]++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int q;
	cin >> q;
	while(q--){
		int l, r, k;
		cin >> l >> r >> k;
		cout << s[r][k] - s[l - 1][k] << '\n';
	}

	return 0;
}