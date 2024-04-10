#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
#define rep(i, n) for(int i=0;i<n;i++)
string s;
int n, dp[2][305][305][70];

int main(){
	cin >> s;
	reverse(s.begin(), s.end());
	s.push_back('0'); s.push_back('0'); s.push_back('0');
	n = s.size();
	rep(i, 2) rep(j, 305) rep(k, 305){
		rep(l, 70) dp[i][j][k][l] = INF;
		if( i == 0 && ((j-k)%10+10)%10 == s[0] - '0' ){
			dp[i][j][k][35] = 0;
		}
	}
	int cur = 0, nxt = 1;
	for(int i=0;i<n-1;i++){
		rep(j, 305) rep(k, 305) rep(l, 70) dp[nxt][j][k][l] = INF;
		rep(j, 305) rep(k, 305) rep(tl, 70){
			if(dp[cur][j][k][tl] == INF) continue;
			int l = tl - 35;
			for(int x=0;x<=j && x<=6;x++){
				int a = (j-k+l)%10; a = a % 10 + 10; a %= 10;
				a = (j - k + l - a) / 10; int up = a + 35;
				a = (j-x - k + a); a = (a%10+10)%10;
				if(a == s[i+1]-'0'){
					dp[nxt][j-x][k][up] = min(dp[nxt][j-x][k][up], dp[cur][j][k][tl] + (i+1)*x);
				}
			}
			for(int x=0;x<=k && x<=6;x++){
				int a = (j-k+l)%10; a = a % 10 + 10; a %= 10;
				a = (j - k + l - a) / 10; int up = a + 35;
				a = (j+x - k + a); a = (a%10+10)%10;
				if(a == s[i+1]-'0'){
					dp[nxt][j][k-x][up] = min(dp[nxt][j][k-x][up], dp[cur][j][k][tl] + (i+1)*x);
				}
			}
		}
		swap(cur, nxt);
	}
	cout << dp[cur][0][0][35] << endl;
}