#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

void min_self(int& a, int b) {
	a = min(a, b);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
	dp[0][0] = 0;
	int last_alive = 0;
	for(int person = 0; person < n; ++person) {
		if(a[person] == 1) {
			last_alive = person;
		}
		for(int spot = 0; spot < n; ++spot) {
			int me = dp[person][spot];
			if(a[person] == 0) { // no person
				min_self(dp[person+1][spot], me);
			}
			else {
				min_self(dp[person][spot+1], me);
				if(a[spot] == 0) {
					min_self(dp[person+1][spot+1], me + abs(person - spot));
				}
			}
		}
	}
	int answer = INF;
	for(int spot = 0; spot <= n; ++spot) {
		min_self(answer, dp[last_alive+1][spot]);
	}
	printf("%d\n", answer);
}




// aliens trick / parametric search
// O(N*log(N))
// ABCD -> [4,4] + [8,15]           E=17



// _ _ A _ _ _ _ B _ C _ D E F _

// _ _ x _ _ _ _ x _ x _ x x x _


// (person, availSpot, sum)

// int dp[person][spot];
// dp[i][j] -> dp[i][j+1]
// dp[i][j] -> dp[i+1][j+1] (we add abs(i-j))

// _ s _ s e _ e s s s e e e _ _ _ 
                   // ^