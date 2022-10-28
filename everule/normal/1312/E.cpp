//https://codeforces.com/problemset/problem/1312/E
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
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        dp[i][i]=seq[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            for(int k=j;k<j+i;k++){
                if(dp[j][k]!=-1 && dp[j][k]==dp[k+1][j+i]){
                    assert((dp[j][k] + 1)==dp[j][j+i] || dp[j][j+i]==-1);
                    dp[j][j+i]=dp[j][k]+1;
                }
            }
        }
    }
   /* for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    vector<int> dp2(n);
    for(int i=0;i<n;i++){
        dp2[i]=i+1;
    }
    for(int i=1;i<n;i++){
        if(dp[0][i]!=-1){
            dp2[i]=1;
            continue;
        }
        for(int j=1;j<=i;j++){
            if(dp[j][i]!=-1){
                dp2[i]=min(dp2[i],dp2[j-1]+1);
            }
        }
    }
    cout<<dp2[n-1]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}