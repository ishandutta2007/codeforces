//https://codeforces.com/contest/1350/problem/B
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n+1);
    for(int i=1;i<=n;i++){
        cin>>seq[i];
    }
    vector<int> dp(n+1, 1);
    dp[1]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            if(seq[j]>seq[i]){
                dp[j]=max(dp[j], dp[i]+1);
            }
        }
    }
    cout<<*max_element(dp.begin(), dp.end())<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}