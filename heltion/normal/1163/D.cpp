//Author: Heltion
//Date: 2019-05-09
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
char c[1200], s[60], t[60];
int dp[1200][60][60], trans[60][26], trant[60][26];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> (c + 1) >> (s + 1) >> (t + 1);
	int n = strlen(c + 1), m = strlen(s + 1), q = strlen(t + 1);
	for(int i = 0; i < m; i += 1){
		trans[i][s[1] - 'a'] = min(1, m - 1);
		for(int j = 0; j < 26; j += 1)
			for(int k = 1; k <= i; k += 1){
				bool ok = true;
				for(int l = k; l <= i; l += 1) if(s[l] != s[l - k + 1]) ok = false;
				if(j != s[i - k + 2] - 'a') ok = false;
				if(ok == true and i - k + 2 < m) trans[i][j] = max(trans[i][j], i - k + 2);
			}
	}
	for(int i = 0; i < q; i += 1){
		trant[i][t[1] - 'a'] = min(1, q - 1);
		for(int j = 0; j < 26; j += 1)
			for(int k = 1; k <= i; k += 1){
				bool ok = true;
				for(int l = k; l <= i; l += 1) if(t[l] != t[l - k + 1]) ok = false;
				if(j != t[i - k + 2] - 'a') ok = false;
				if(ok == true and i - k + 2 < q) trant[i][j] = max(trant[i][j], i - k + 2);
			}
	}

	for(int i = 0; i <= n; i += 1)
		for(int j = 0; j <= m; j += 1)
			for(int k = 0; k <= q; k += 1){
				dp[i][j][k] = -1e9;
			}
	dp[0][0][0] = 0;
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1)
			for(int k = 0; k < q; k += 1)
				for(int a = c[i + 1] == '*' ? 0 : c[i + 1] - 'a'; a < (c[i + 1] == '*' ? 26 : c[i + 1] - 'a' + 1); a += 1){
					int ch = 0;
					if(j == m - 1 and a == s[m] - 'a') ch += 1;
					if(k == q - 1 and a == t[q] - 'a') ch -= 1;
					maxi(dp[i + 1][trans[j][a]][trant[k][a]], dp[i][j][k] + ch);
				}
	int ans = -1e9;
	for(int j = 0; j < m; j += 1)
		for(int k = 0; k < q; k += 1)
			ans = max(ans, dp[n][j][k]);
	cout << ans;
	return 0;
	for(int i = 0; i < m; i += 1)
		for(int j = 0; j < 26; j += 1){
			cout << i << " " << j << " " << trans[i][j] << endl;
		}
	for(int i = 0; i < q; i += 1)
		for(int j = 0; j < 26; j += 1){
			cout << i << " " << j << " " << trant[i][j] << endl;
		}
	for(int i = 1; i <= n; i += 1)
		for(int j = 0; j < m; j += 1)
			for(int k = 0; k < q; k += 1){
				if(dp[i][j][k] != -1e9){
					cout << i << " " << j << " " << k << endl;
					cout << dp[i][j][k] << endl;
				}
			}
	
	return 0;
}