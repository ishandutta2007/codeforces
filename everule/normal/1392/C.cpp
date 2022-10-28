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
    vector<vector<ll>> seq;
    int last = 1e9 + 7;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<last){
            seq.pb({x});
        }
        else{
            seq.back().pb(x);
        }
        last = x;
    }
    reverse(seq.begin(), seq.end());
    ll ans = 0;
    for(int i=1;i<seq.size();i++){
        ans += seq[i].back() - seq[i-1].front();
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