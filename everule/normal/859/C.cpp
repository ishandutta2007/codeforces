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
    vector<array<int, 2>> dp(n+1,{0,0});
    for(int i=n-1;i>=0;--i){
        if(dp[i+1][0] > dp[i+1][1] + seq[i]){
           dp[i][0] = dp[i+1][0];
           dp[i][1] = dp[i+1][1] + seq[i]; 
        }
        else{
            dp[i][0] = dp[i+1][1] + seq[i];
            dp[i][1] = dp[i+1][0];
        }
    }
    cout<<dp[0][1]<<" "<<dp[0][0]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}