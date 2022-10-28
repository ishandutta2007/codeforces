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
const int bits = 20;
const int MAXA = 3e5 + 7;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> dp(n, vector<int>(bits, 1e9));
    vector<vector<int>> curr(bits, vector<int>(bits, 1e9));
    vector<int> seq(n);
    cin>>seq;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<bits;++j){
            if(seq[i] & (1<<j)){
                for(int k=0;k<bits;++k){
                    if(seq[i] & (1<<k)){
                        dp[i][k] = i;
                        curr[j][k] = i;
                    }
                    else{
                        dp[i][k] = min(dp[i][k], curr[j][k]);
                    }
                }
            }
        }
        for(int j=0;j<bits;++j){
            if(seq[i] & (1<<j)){
                for(int k=0;k<bits;++k){
                    curr[j][k] = min(curr[j][k], dp[i][k]);
                }
            }
        }
    }
    for(int i=0;i<q;++i){
        int l,r;
        cin>>l>>r;
        --l;--r;
        int R=1e9;
        for(int j=0;j<bits;++j){
            if(seq[r] & (1<<j)){
                R = min(R, dp[l][j]);
            }
        }
        if(R<=r){
            cout<<"Shi\n";
        }
        else{
            cout<<"Fou\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}