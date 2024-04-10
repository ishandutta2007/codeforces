#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
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
    vector<int> seq(n);
    cin>>seq;
    int d = -1;
    for(int i=1;i<n;i++){
        if(seq[i]!=seq[i-1]){
            d = std::abs(seq[i] - seq[i-1]);
        }
    }
    if(d==-1){
        cout<<"0\n";
        return;
    }
    vector<set<int>> dp(n);
    dp[0] = {seq[0], seq[0] - d, seq[0] + d};
    for(int i=1;i<n;i++){
        if(dp[i-1].count(seq[i] + d)){
            dp[i].insert(seq[i] + d);
        }
        if(dp[i-1].count(seq[i] - d)){
            dp[i].insert(seq[i] - d);
        }
        if(dp[i-1].count(seq[i])){
            dp[i].insert(seq[i]);
        }
    }
    if(d%2){
        if(dp[n-1].size()==0){
            cout<<"-1\n";
            return;
        }
        cout<<d<<"\n";
        return;
    }
    bool ans = (dp[n-1].size() != 0);
    int x = d/2;
    dp = vector<set<int>>(n);
    dp[0] = {seq[0], seq[0] - x, seq[0] + x};
    for(int i=1;i<n;i++){
        if(dp[i-1].count(seq[i] + x)){
            dp[i].insert(seq[i] + x);
        }
        if(dp[i-1].count(seq[i] - x)){
            dp[i].insert(seq[i] - x);
        }
        if(dp[i-1].count(seq[i])){
            dp[i].insert(seq[i]);
        }
    }
    if(dp[n-1].size()==0 && ans==0){
        cout<<"-1\n";
        return;
    }
    if(dp[n-1].size()==0 && ans==1){
        cout<<d<<"\n";
        return;
    }
    cout<<x<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}