//https://codeforces.com/contest/1337/problem/E
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
const ll p =998244353;
ll modpower(ll base, ll power, ll mod=p){
    ll ans =1;
    base%=p;
    while(power){
        if(power&1){
            ans*=base;
            ans%=p;
        }
        base*=base;
        base%=p;
        power>>=1;
    }
    return ans;
}
void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n, vector<int>(m));
    for(int j=0;j<m;j++){
        dp[0][j]=2*(s[0]==t[j]);
    }
    ll ans=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(i+j>=m || t[i+j]==s[i]){
                dp[i][j]+=dp[i-1][j];
            }
            if(t[j]==s[i]){
                dp[i][j]+=(j+1==m ? modpower(2,i) : dp[i-1][j+1]);
            }
            dp[i][j]%=p;
        }
    }
   /*for(const auto &vec : dp){
        for(const auto &x : vec){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    */
   for(int i=m-1;i<n;i++){
       ans+=dp[i][0];
       ans%=p;
   }
    cout<<ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}