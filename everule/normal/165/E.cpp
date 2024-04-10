//https://codeforces.com/problemset/problem/165/E
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
const int maxmask= (1<<22) - 1;
void solve(){
    int n;
    cin>>n;
    vector<int> dp(maxmask + 1, -1);
    vector<int> seq(n);
    for(auto &x : seq){
        cin>>x;
        dp[(x^maxmask)]=x;
    }
    for(int i=0;i<22;i++){
        for(int j=0;j<=maxmask;j++){
            if(dp[j]!=-1 && (j & (1<<i))){
                dp[j^(1<<i)]=dp[j];
            }
        }
    }
    for(auto &x : seq){
        cout<<dp[x]<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}