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
    vector<int> seq(n<<1);
    cin>>seq;
    vector<int> segments;
    for(int i=1, curr=1, mx = seq[0];i<2*n;i++){
        if(seq[i]>mx){
            segments.pb(curr);
            mx = seq[i];
            curr=0;
        }
        ++curr;
        if(i==2*n-1){
            segments.pb(curr);
        }
    }
    vector<bool> dp(n+1);
    dp[0]=1;
    for(const auto &c : segments){
        for(int i=n;i>=c;i--){
            dp[i] = dp[i]|dp[i-c];
        }
    }
    cout<<(dp[n] ? "YES\n" : "NO\n");
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