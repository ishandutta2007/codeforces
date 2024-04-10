#include <bits/stdc++.h>
using namespace std;

const int maxN = 205;
const int mod = 1000000007;

int fail[maxN], go[maxN][2], dp[maxN][maxN][maxN];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int m = (int)s.size();
	
	{
		fail[0] = 0;
		int i = 1, j = 0;
		while(i < m){
			if(s[i] == s[j]){
				fail[i] = j + 1;
				i++; j++;
			}else if(j){
				j = fail[j - 1];
			}else{
				fail[i] = 0;
				i++;
			}
		}
		for(int i = 0; i < m; i++){
			if(s[i] == '('){
				go[i][0] = i + 1;
				if(i){
					go[i][1] = go[fail[i - 1]][1];
				}else{
					go[i][1] = 0;
				}
			}else{
				go[i][1] = i + 1;
				if(i){
					go[i][0] = go[fail[i - 1]][0];
				}else{
					go[i][0] = 0;
				}
			}
		}
		go[m][0] = go[m][1] = m;
	}
	memset(dp, 0, sizeof(dp));
	
	dp[0][0][0] = 1;
	for(int i = 0; i < 2*n; i++){
		for(int s = 0; s <= i; s++){
			for(int t = 0; t <= m; t++){
				for(int c = 0; c <= 1; c++){
					if(s + 1 - 2*c >= 0){
						add(dp[i + 1][s + 1 - 2*c][go[t][c]], dp[i][s][t]);
					}
				}
			}
		}
	}
	cout << dp[2*n][0][m] << '\n';

	return 0;
}