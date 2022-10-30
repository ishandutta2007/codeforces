#include <iostream>
    #include <fstream>
    #include <cstdlib>
    #include <cstdio>
    #include <vector>
    #include <set>
    #include <cmath>
    #include <algorithm>
    #include <string>
     
    #define ll long long
    #define mp make_pair
    #define pb push_back
    #define md 1000000007
     
    using namespace std;
     
     
    ll a[100005], t, dp[100005][2];
    vector <int> used;
    vector < vector <int> > g;
     
    void dfs (int v){
    	used[v] = 1;
    	dp[v][0] = 1;
    	dp[v][1] = 0;
        for (int i = 0; i < g[v].size(); i++){
		    int to = g[v][i];
		    if (!used[to]) {
		    	dfs(to);
		    	dp[v][1] = (dp[v][1] * dp[to][0]) % md;
		    	dp[v][1] = (dp[v][1] + dp[v][0] * dp[to][1]) % md;
		    	dp[v][0] = (dp[v][0] * dp[to][0]) % md;
		    }
	    }
	    if (a[v]) dp[v][1] = dp[v][0];
	    else dp[v][0] += dp[v][1];
    }
     
    int main() {
    int n;
    cin >> n;
    g.resize(n);
    used.resize (n, 0);
    for (int i = 1; i < n; i++){
    cin >> t;
    g[i].pb(t);
    g[t].pb(i);
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    dfs(0);
    dp[0][1] %= md;
    cout << dp[0][1];
    return 0;
    }