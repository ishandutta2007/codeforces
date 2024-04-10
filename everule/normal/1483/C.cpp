#include <bits/stdc++.h>
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
    vector<int> h(n), b(n);
    cin>>h>>b;
    stack<int> stk;
    vector<ll> dp(n, -INFLL);
    vector<ll> bst(n, -INFLL);
    dp[0] = b[0]; 
    bst[0] = b[0];
    for(int i=0;i<n;i++){
        if(i) bst[i] = dp[i-1] + b[i];
        while(stk.size() > 0 && h[stk.top()] > h[i]){
            bst[i] = max(bst[i], bst[stk.top()] - b[stk.top()] + b[i]);
            stk.pop();
        }
        if(stk.size()) dp[i] = max(bst[i], dp[stk.top()]);
        else dp[i] = bst[i];
        stk.push(i);
    }
    //cout+dp;
    //cout+bst;
    cout<<dp[n-1]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}