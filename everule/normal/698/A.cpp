//https://codeforces.com/problemset/problem/698/A
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
ll solve(){
     int n;
     cin>>n;
     int seq[n];
     for(int i=0;i<n;i++){
         cin>>seq[i];
     } 
     int dp[n+1][3]; //number of days, and last activity
     dp[0][0]=0;
     dp[0][1]=1e9;
     dp[0][2]=1e9;
     for(int i=1;i<=n;i++){
        dp[i][0]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+1;
        dp[i][1]=1e9;
        dp[i][2]=1e9;
        if(seq[i-1]&1){
            dp[i][1]=min(dp[i-1][2],dp[i-1][0]);
        }
        if(seq[i-1]&2){
            dp[i][2]=min(dp[i-1][1],dp[i-1][0]);
        }
  }
  return min({dp[n][0],dp[n][1],dp[n][2]});
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	//cin >>t;
    //precompute();
    t=1;
	while(t--){
     //init();
       cout<<solve();
	}
}