#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const ull P[2] = {323232323, 3232323};
const ull mod = 1000000007;

char buf[200010];
string s;
ull h[200010][26][2];
ull power[200010][2];

ull get_h(int l, int r, int c){
	ull h1 = (h[r][c][0] - h[l - 1][c][0] * power[r - l + 1][0] % mod + mod) % mod;
	ull h2 = (h[r][c][1] - h[l - 1][c][1] * power[r - l + 1][1] % mod + mod) % mod;
	return (h1 << 32) | h2;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int p = 0; p < 2; p++){
		power[0][p] = 1;
		for (int i = 1; i <= n; i++){
			power[i][p] = power[i - 1][p] * P[p] % mod;
		}
	}
	scanf("%s", buf), s = buf;
	s = " " + s;
	for (int p = 0; p < 2; p++){
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < 26; j++){
				h[i][j][p] = (h[i - 1][j][p] * P[p] % mod + (s[i] == j + 'a' ? 1 : 2)) % mod;
			}
		}
	}
	for (int i = 0; i < m; i++){
		int x, y, len;
		scanf("%d%d%d", &x, &y, &len);
		vector <ull> h1, h2;
		for (int i = 0; i < 26; i++){
			h1.push_back(get_h(x, x + len - 1, i));
			h2.push_back(get_h(y, y + len - 1, i));
		}
		sort(h1.begin(), h1.end()), sort(h2.begin(), h2.end());
		if (h1 == h2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}