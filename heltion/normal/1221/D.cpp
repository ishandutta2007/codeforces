//Author: Heltion
//Date: 09-19-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 320000;
int a[maxn], b[maxn];
LL dp[maxn][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	a[0] = -1e9;
	int q;
	for(cin >> q; q; q -= 1){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i += 1) cin >> a[i] >> b[i];
		for(int i = 1; i <= n; i += 1)
			for(int j = 0; j < 3; j += 1){
				dp[i][j] = 1e18;
				for(int k = 0; k < 3; k += 1) if(a[i - 1] + k != a[i] + j)
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
			}
		cout << *min_element(dp[n], dp[n] + 3) << "\n";
	}
	return 0;
}