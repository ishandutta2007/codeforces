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
const int INF = 1e9;
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    for(int i=0;i<n;i++){
        seq[i] += i;
    }
    vector<vector<int>> dp(n, vector<int>(n, INF));
    dp[0] = vector<int>(n, 0);
    for(int i=1;i<n;i++){
        int curr = 0;
        for(int j=i-1;j>=0;--j){
            if(seq[j] < i) continue;
            dp[i][seq[j]] = min(dp[i][seq[j]], dp[j][i-1] + curr);
            ++curr;
        }
        for(int j=1;j<n;j++) dp[i][j] = min(dp[i][j], dp[i][j-1]);
    }
    cout<<dp[n-1][n-1]<<"\n";
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