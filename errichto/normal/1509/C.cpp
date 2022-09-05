#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<vector<long long>> dp(n, vector<long long>(n));
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	for(int L = n - 1; L >= 0; --L) {
		for(int R = L + 1; R < n; ++R) {
			dp[L][R] = min(dp[L+1][R], dp[L][R-1]) + a[R] - a[L];
		}
	}
	printf("%lld\n", dp[0][n-1]);
}


// 30 10 20 27 24 15


// 24 27 30 20 15 10   OPT
 // ------>
 
 
// set: 84 86 15 82 80 16


// order: 15 16 80 82 84 86
// 1 + 65 + 65 + 65 + 65

// better: 80 82 84 86 16 15
// 2 + 4 + 6 + 65 + 65





// ---x----x-------x-x------x--------xx-->
                // ^ ^      ^
                
                
                
// set: 15 16 80 82 84 86
        // <--------->
        
// O(N^2) states


// [L,R] -> [L,R+1] or [L-1,R]