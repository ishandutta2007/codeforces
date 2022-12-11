#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
 
int n;
int a[2222];
int cnt1[2222];
int cnt2[2222];
int ans = 0;
int dp[2222];

int last[2];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++){
    	cnt1[i] = (a[i] == 1);
    	if (i) cnt1[i] += cnt1[i - 1];
    }

    for (int i = n - 1; i >= 0; i--){
    	cnt2[i] = (a[i] == 2);
    	if (i != n - 1) cnt2[i] += cnt2[i + 1];
    }

    for (int i = 0; i < n; i++){
    	last[0] = last[1] = -1;
    	for (int j = i; j < n; j++){
    		if (a[j] == 1){
    			dp[j] = 1;
    			if (last[0] != -1) dp[j] = max(dp[last[0]] + 1, dp[j]);
    			if (last[1] != -1) dp[j] = max(dp[last[1]] + 1, dp[j]);
    		} else {
    			dp[j] = 1;
    			if (last[1] != -1) dp[j] = max(dp[last[1]] + 1, dp[j]);
    		}
    		last[a[j] - 1] = j;
    		int now = dp[j]	;	
    		if (i) now += cnt1[i - 1];
    		if (j + 1 != n) now += cnt2[j + 1];
    		ans = max(ans, now);
    	}
    }

    cout << ans;
}