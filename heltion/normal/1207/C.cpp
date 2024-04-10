//Author: Heltion
//Date: 08-22-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
char s[maxn];
LL dp[maxn][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	dp[0][1] = 1e18;
	for(cin >> T; T; T -= 1){
		LL n, a, b;
		cin >> n >> a >> b;
		cin >> (s + 1);
		for(int i = 1; i <= n; i += 1){
			if(s[i] == '0'){
				dp[i][0] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2 * a + 2 * b);
				dp[i][1] = min(dp[i - 1][0] + 2 * a + b, dp[i - 1][1] + a + 2 * b);
			}
			else{
				dp[i][0] = 1e18;
				dp[i][1] = dp[i - 1][1] + a + 2 * b;
			}
		}
		cout << dp[n][0] + b << '\n';
	}
	return 0;
}