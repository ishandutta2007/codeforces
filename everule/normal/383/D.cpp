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
const int p = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    int sum = accumulate(seq.begin(), seq.end(), 0);
    vector<vector<int>> dp(n+1, vector<int>(2*sum+1));
    dp[0][sum] = 1;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2*sum;j++){
            if(j-seq[i-1] >= 0){
                dp[i][j]+=dp[i-1][j-seq[i-1]];
            }
            if(j+seq[i-1] <= 2*sum){
                dp[i][j]+=dp[i-1][j+seq[i-1]];
            }
            dp[i][j]%=p;
        }
        ans+=dp[i][sum];
        ++dp[i][sum];
    }
    cout<<ans%p<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}