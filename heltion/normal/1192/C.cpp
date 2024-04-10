#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 62;
int code(const char &c){
	if('a' <= c and c <= 'p') return c - 'a';
	if('A' <= c and c <= 'P') return c - 'A' + 16;
	if('q' <= c and c <= 'z') return c - 'q' + 32;
	if('Q' <= c and c <= 'Z') return c - 'Q' + 42;
	return c - '0' + 52;
}
LL f[8][maxn][maxn];
LL g[8][maxn][maxn][maxn];
void add(LL &x, LL y){
	x += y;
	if(x >= mod) x-= mod;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	set<string> ss;
	for(int i = 0; i < n; i += 1){
		string s;
		cin >> s;
		ss.insert(s);
		reverse(s.begin(), s.end());
		ss.insert(s);
	}
	for(auto s : ss) f[(int)s.size() - 3][code(s[0])][code(*s.rbegin())] += 1;
	for(int x = 0; x < 8; x += 1)
		for(int i = 0; i < maxn; i += 1)
			for(int j = i; j < maxn; j += 1)
				for(int k = j; k < maxn; k += 1)
					for(int m = 0; m < maxn; m += 1)
						add(g[x][i][j][k], f[x][i][m] * f[x][j][m] * f[x][k][m] % mod);
	LL ans = 0;
	for(int x = 0; x < 8; x += 1)
		for(int i = 0; i < maxn; i += 1)
			for(int j = i; j < maxn; j += 1)
				for(int k = j; k < maxn; k += 1)
					for(int m = k; m < maxn; m += 1){
						LL pans = g[x][i][j][k] * g[x][i][j][m] % mod
							* g[x][i][k][m] % mod * g[x][j][k][m] % mod;
						int y = 1;
						if(i < j){
							if(j < k) {
								if(k < m) y = 24;
								else y = 12;
							}
							else{
								if(k < m) y = 12;
								else y = 4;
							}
						}
						else{
							if(j < k){
								if(k < m) y = 12;
								else y = 6;
							}
							else{
								if(k < m) y = 4;
								else y = 1;
							}
						}
						add(ans, pans * y % mod);
					}
	cout << ans;
	return 0;
}