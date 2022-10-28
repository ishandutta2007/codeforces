#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<ll>> prefix_sum(n+1, vector<ll>(26));
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            prefix_sum[i+1][j]=prefix_sum[i][j] + (s[i]=='a'+j);
        }
    }
    vector<vector<ll>> ans(26, vector<ll>(26));
    for(int i=0;i<n;i++){
        int idx=s[i]-'a';
        for(int j=0;j<26;j++){
            ans[idx][j]+=prefix_sum[n][j]-prefix_sum[i+1][j];
        }
    }
    ll fin=-1;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            fin=max(fin, ans[i][j]);
        }
    }
    for(int i=0;i<26;i++){
        fin=max(fin, prefix_sum[n][i]);
    }
    cout<<fin;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}