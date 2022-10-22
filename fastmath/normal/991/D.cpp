#include <bits/stdc++.h>
   
using namespace std;

const int MAXN = 107;
const int INF = 1e9 + 7;

int dp[MAXN][4];
string a[2];  

int max(int a, int b, int c) {
	return max(a, max(b, c));
}

int max(int a, int b, int c, int d) {
 	return max(a, max(b, c, d));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
  
    cin >> a[0] >> a[1];
    int n = a[0].size();

    for (int i = 0; i < MAXN; ++i) {
    	for (int j = 0; j < 4; ++j) dp[i][j] = -INF;
    }

	dp[0][3] = 0;
	for (int i = 0; i < n; ++i) {
		for (int pm = 0; pm < 4; ++pm) {
			if (i && a[0][i - 1] == 'X' && !((pm >> 0) & 1)) continue;
			if (i && a[1][i - 1] == 'X' && !((pm >> 1) & 1)) continue;


		 	for (int m = 0; m < 4; ++m) {
				if (a[0][i] == 'X' && !((m >> 0) & 1)) continue;
				if (a[1][i] == 'X' && !((m >> 1) & 1)) continue;
		 	    
		 	    dp[i + 1][m] = max(dp[i + 1][m], dp[i][pm]);

		 	    if (m == 0) {
		 	    	dp[i + 1][m] = max(dp[i + 1][m], dp[i][pm]); 
		 	    }
		 	    else if (m == 1) {
					if (pm == 0 && a[0][i] == '0') {
						dp[i + 1][m] = max(dp[i + 1][m], dp[i][pm] + 1); 
					}
		 	    }	
		 	    else if (m == 2) {
					if (pm == 0 && a[1][i] == '0') {
						dp[i + 1][m] = max(dp[i + 1][m], dp[i][pm] + 1); 
				   	}
		 	    }
		 	    else {
		 	    	if (i && a[0][i] == '0' && a[1][i] == '0') {
		 	        	if (!(pm & 1) || !((pm >> 1) & 1)) {
		 	        		dp[i + 1][m] = max(dp[i + 1][m], dp[i][pm] + 1);
		 	        	}
		 	        }
		 	        
		 	        if (a[0][i] == '0') {
		 	        	if (pm == 0) dp[i + 1][m] = max(dp[i + 1][m], dp[i][pm] + 1); 
		 	        }

		 	        if (a[1][i] == '0') {
		 	         	if (pm == 0) dp[i + 1][m] = max(dp[i + 1][m], dp[i][pm] + 1); 
		 	        }
		 	    }

		 	}	
		}
	}


   	cout << max(dp[n][0], dp[n][1], dp[n][2], dp[n][3]) << '\n';
    return 0;
}