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
    int n, k;
    cin>>n>>k;
    vector<int> seq(n);
    cin>>seq;
    vector<int> IdkWhy(n);
    cin>>IdkWhy;
    sort(seq.begin(), seq.end());
    set<pair<int,int>> currpoints;
    vector<int> dp(n+1);
    for(int i=n-1;i>=0;--i){
        currpoints.insert({seq[i], i});
        while((*(--currpoints.end())).first - seq[i] > k){
            currpoints.erase(--currpoints.end());
        }
        dp[i] = currpoints.size();
        dp[i] = max(dp[i], dp[i+1]);
    }
    currpoints.clear();
    vector<int> dp2(n+1);
    for(int i=0;i<n;i++){
        currpoints.insert({seq[i],i});
        while(seq[i] - (*currpoints.begin()).first > k){
            currpoints.erase(currpoints.begin());
        }
        dp2[i+1] = currpoints.size();
        dp2[i+1] = max(dp2[i+1], dp2[i]);
    }
    int ans = 0;
    for(int i=0;i<=n;i++){
        ans = max(ans, dp[i] + dp2[i]);
    }
    cout<<ans<<"\n";
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