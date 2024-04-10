#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define f first
#define s second
#define INF 1000000007

using namespace std;

int n, t, dp[31][31][5];

int main(){
	//ifstream in ("in.txt");
	cin >> n >> t;
	for (int i = 0; i < 4; i++){
		dp[n][2 * t - 1][i] = 1; 
	}
	for (int i = 0; i < 2 * t - 1; i++){
		for (int j = 0; j < 4; j++){
			dp[n][i][j] = 0;
		}
	}
	for (int i = n - 1; i >= 2; i--){
		for (int j = 2 * t; j >= 0; j--){
			for (int h = 0; h < 4; h++){
				dp[i][j][h] = 0;
				if (!(j & 1)){
					for (int q = h - 1; q >= 0; q--){
						dp[i][j][h] += dp[i + 1][j + 1][q];
					}
					for (int q = h + 1; q < 4; q++){
						dp[i][j][h] += dp[i + 1][j][q];
					}
				} else {
					for (int q = h + 1; q < 4; q++){
						dp[i][j][h] += dp[i + 1][j + 1][q];
					}
					for (int q = h - 1; q >= 0; q--){
						dp[i][j][h] += dp[i + 1][j][q];
					}
				}
			}
		}
	}
	int ans = dp[2][0][1] + dp[2][0][2] * 2 + dp[2][0][3] * 3;
	cout << ans << '\n';
	return 0;
}