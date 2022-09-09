#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
char s[2][maxn];
bool f[2][maxn];
int main(){
	ios::sync_with_stdio(false);
	int q;
	for(cin >> q; q; q -= 1){
		int n;
		cin >> n >> (s[0] + 1) >> (s[1] + 1);
		f[0][0] = true;
		for(int i = 1; i <= n; i += 1){
			f[0][i] = f[1][i] = false;
			if(s[0][i] <= '2') f[0][i] = f[0][i - 1];
			if(s[1][i] <= '2') f[1][i] = f[1][i - 1];
			if(s[0][i] >= '3' and s[1][i] >= '3'){
				f[0][i] = f[1][i - 1];
				f[1][i] = f[0][i - 1];
			}
		}
		cout << (f[1][n] ? "YES\n" : "NO\n");
	}
}