#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 105;
int dp[N][N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	memset(dp, 0, sizeof(dp));
	for(int a = 0; a < N; a++){
		for(int b = 0; b < N; b++){
			for(int c = 0; c < N; c++){
				if(a >= 1 && b >= 2){
					dp[a][b][c] = max(dp[a][b][c], dp[a-1][b-2][c] + 1);
				}
				if(b >= 1 && c >= 2){
					dp[a][b][c] = max(dp[a][b][c], dp[a][b-1][c-2] + 1);
				}
			}
		}
	}
	int t, a, b, c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		cout<<3*dp[a][b][c]<<'\n';
	}

	return 0;
}