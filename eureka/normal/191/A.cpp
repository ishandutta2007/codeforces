#include<iostream>
#include<cstring>
using namespace std;

const int N = 26;
int dp[2][N][N];

int main(){
	int cur = 0, nxt = 1;
	for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) dp[cur][i][j] = -1000000000;
	for (int i=0; i<N; ++i) dp[cur][i][i] = 0;
	char ch[N];
	int n;
	cin >> n;
	while (n --){
		for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) dp[nxt][i][j] = dp[cur][i][j];
		cin >> ch;
		int len = strlen(ch);
		int s = ch[0] - 'a', t = ch[len-1] - 'a';
		for (int i=0; i<N; ++i){
			dp[nxt][i][t] = max(dp[nxt][i][t], dp[cur][i][s] + len);
		}
		swap(cur, nxt);
	}
	int ans = 0;
	for (int i=0; i<N; ++i) ans = max(ans, dp[cur][i][i]);
	cout << ans << endl;
	return 0;
}