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
const ll INFLL = 1e18;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    cin>>a>>b;
    int sum = accumulate(a.begin(), a.end(), 0ll) + accumulate(b.begin(), b.end(), 0ll);
    vector<int> dp(sum+1);
    dp[0] = 1;
    for(int i=0;i<n;i++){
        vector<int> dp2(sum+1);
        for(int s=sum;s>=0;--s){
            if(s >= a[i]) dp2[s] |= dp[s-a[i]];
            if(s >= b[i]) dp2[s] |= dp[s-b[i]];
        }
        dp = dp2;
    }
    ll ans = INFLL;
    for(int i=0;i<=sum;i++){
        if(dp[i] && (1ll * i * i + 1ll * (sum - i) * (sum - i) < ans)){
            ans = 1ll * i * i + 1ll * (sum - i) * (sum - i);
        }
    }
    for(int i=0;i<n;i++){
        ans -= a[i] * a[i] + b[i] * b[i];
    }
    for(int i=0;i<n;i++){
        ans += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
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