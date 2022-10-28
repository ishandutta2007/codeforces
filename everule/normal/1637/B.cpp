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
int MEX(vector<int> x){
    vector<bool> found(x.size());
    for(int i=0;i<x.size();i++){
        if(x[i]<x.size()){
            found[x[i]]=1;
        }
    }
    for(int i=0;i<x.size();i++){
        if(!found[i]){
            return i;
        }
    }
    return x.size();
}
const int INF = 1e9;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    ll ans = 0;
    while(a.size() > 0){
        vector<int> dp(n+1, 0);
        n = a.size();
        for(int i=1;i<=n;i++){
            vector<int> cnt(n+2);
            int mex = 0;
            for(int j=i-1;j>=0;--j){
                if(a[j] < n+2) cnt[a[j]]++;
                while(cnt[mex] > 0) mex++;
                dp[i] = max(dp[i], dp[j] + mex + 1);
            }
            ans += dp[i];
        }
        a = vector<int>(a.begin() + 1, a.end());
        //cout+dp;
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